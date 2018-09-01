/****************************************************************
**	OrangeBot Project
*****************************************************************
**        /
**       /
**      /
** ______ \
**         \
**          \
*****************************************************************
**	DHT Discrete hartley Transform
*****************************************************************
**  Understand working and meaning of the Hartley Transform
****************************************************************/

/****************************************************************
**	DESCRIPTION
****************************************************************
**	The HT Hartley Transform is similar to the FT Fourier transform
**	it works with real numbers instead of complex ones.
**
**	HT Kenrel
**	cas(x) = cos(x) +sin(x)
**
**	FT Kernel
**	cos(x) +i*sin(x)
****************************************************************/

/****************************************************************
**	HISTORY VERSION
****************************************************************
**
****************************************************************/

/****************************************************************
**	KNOWN BUGS
****************************************************************
**
****************************************************************/

/****************************************************************
**	TODO
****************************************************************
**
****************************************************************/

/****************************************************************
**	INCLUDES
****************************************************************/

//Standard C Libraries
#include <cmath>				//for sin, cos,
//Standard C++ libraries
#include <iostream>				//cout
#include <vector>				//vector
//
#include "my_utils.h"

/****************************************************************
**	NAMESPACES
****************************************************************/

//Never use a whole namespace. Use only what you need from it.
using std::cout;
using std::cerr;
//using std::endl;	//endl is resource intensive. use "\n"

using std::vector;

using std::abs;
using std::sin;
using std::sqrt;
using std::atan2;

/****************************************************************
**	DEFINES
****************************************************************/

#define N_SAMPLES 16

/****************************************************************
**	MACROS
****************************************************************/

/****************************************************************
**	PROTOTYPES
****************************************************************/

//Create a vector of length N filled with N periods of SIN with a given initial phase
extern vector<double> make_sin_vector( int size, double amplitude, double periods, double phase );

//Compute the hartley tansform and normalize the result by the number of elements
extern vector<double> hartley_transform( vector<double> in, bool f_normalize );
//overload of DHT without normalization
extern vector<double> hartley_transform( vector<double> in );

//Show content of vector
extern bool show_vector( vector<double> data );

//Show the meaning of the content of the Hartley Transform
extern bool show_hartley_transform_meaning( vector<double> data );

/****************************************************************
**	GLOBAL VARIABILES
****************************************************************/

//C++ does not have a standard definition of PI (jarring)
const double pi = 3.14159265358979323846264338327950;

/****************************************************************
**	FUNCTIONS
****************************************************************/

/****************************************************************
**	MAIN
****************************************************************
**	INPUT:
**	OUTPUT:
**	RETURN:
**	DESCRIPTION:
****************************************************************/

int main()
{
	///----------------------------------------------------------------
	///	STATIC VARIABILE
	///----------------------------------------------------------------

	///----------------------------------------------------------------
	///	LOCAL VARIABILE
	///----------------------------------------------------------------

	vector<double> signal, transform, anti_transform;

	///----------------------------------------------------------------
	///	CHECK AND INITIALIZATIONS
	///----------------------------------------------------------------

	///SETUP
	double num_periods = 4.0;
	double amplitude = 1.0;
	double phase = 0.0 *2.0 *pi;

	///----------------------------------------------------------------
	///	BODY
	///----------------------------------------------------------------

	printf("OrangeBot Projects\n");

	cout << "Parameters\n";
	cout << "number of periods of sin inside the vector: " << ENG_NUM_CSTR(num_periods) << "\n";
	cout << "amplitude of the wave: " << ENG_NUM_CSTR(amplitude) << "\n";
	cout << "phase of the wave: " << ENG_NUM_CSTR(phase) << "\n";

	cout << "\nSignal\n";
	//Fill vector with a sin
	signal = make_sin_vector( N_SAMPLES, amplitude, num_periods, phase );
	show_vector( signal );


	cout << "Transform\n";
	//Apply the transform
	transform = hartley_transform( signal, true );
	show_vector( transform );

	cout << "Anti-Transform\n";
	//Anti transform to original signal
	anti_transform = hartley_transform( transform );
	show_vector( anti_transform );

	cout << "Hartley Transform Meaning\n";
	show_hartley_transform_meaning( transform );

	///----------------------------------------------------------------
	///	FINALIZATIONS
	///----------------------------------------------------------------

    return 0;
}	//end function: main

/****************************************************************************
**	make_sin_vector
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	Create a vector of length N filled with N periods of SIN with a given initial phase
****************************************************************************/

vector<double> make_sin_vector( int size, double amplitude, double periods, double phase )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//Counter
	int t;
	//Return vector filled with a sin
	vector<double> ret;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	if (size <= 0)
	{
		//return empty vector
		return ret;
	}

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	//Create vector
	ret = vector<double>(size);
	//if: vector still empty
	if (ret.empty() == true)
	{
		//FAIL: failed to create vector
		return ret;
	}

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//for: every element
	for (t = 0;t < size;t++)
	{
		//Fill the vector with a sin of the given stats
		ret[t] = amplitude *sin( phase +2.0 *pi *periods *t /size );
	}	//end for: every element

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	//Return vector
	return ret;
}	//end function: make_sin_vector

/****************************************************************************
**	Hartley Transform
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**  naive implementation of hartley transform
****************************************************************************/

vector<double> hartley_transform( vector<double> in, bool f_normalize )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//Counters
	unsigned int t, ti;
	//argument of the CAS function
	double arg;
	//accumulator
	double acc;
	//Normalization factor
	double norm;
	//return vector
	vector<double> out;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	//if: vectors are not valid
	if (in.empty() == true)
	{
		cerr << "ERR: bad input vector\n";
		//FAIL
		return out;
	}

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	//Initialize output vector to the same size of the input
	out = vector<double>( in.size() );
	//if: failed to create vector
	if (out.empty() == true)
	{
		cerr << "ERR: could not create output vector\n";
		//FAIL
		return out;
	}
	//if: normalization is active
	if (f_normalize == true)
	{
		//Compute normalization factor
		norm = 1.0 *in.size();
	}
	else
	{
		//neutral normalization
		norm = 1.0;
	}

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//for: every element
	for (t = 0;t<in.size();t++)
	{
		//Initialize accumulator
        acc = 0.0;
		//for: every element
        for (ti = 0;ti < in.size();ti++)
        {
			//Argument of the CAS function
            arg = 2.0 *pi *t *ti /(in.size());
			//Calculate and accumulate the CAS of the element
            acc += in[ti] *(cos(arg) +sin(arg));
        }	//end for: every element
		//Write back result
        out[t] = acc / norm;
	}	//end for: every element

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return out;	//OK
}	//end function: hartley_transform

/****************************************************************************
**	Hartley Transform
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**  Wrapper without normalization
****************************************************************************/

inline vector<double> hartley_transform( vector<double> in )
{
	//Execute regular function with full arguments. disable normalization.
	return hartley_transform( in, false );
}	//end function: hartley_transform

/****************************************************************************
**	show_vector
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	Show content of vector
****************************************************************************/

bool show_vector( vector<double> data )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	unsigned int t;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	cout << "size: " << data.size() << "\n";

	for(t = 0;t < data.size();t++)
	{
		cout << ENG_NUM_CSTR( data[t] ) << " | ";
	}
	cout << "\n";

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return false;	//OK
}	//end function: show_vector

/****************************************************************************
**	show_hartley_transform_meaning
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	Show the meaning of the content of the Hartley Transform
****************************************************************************/

bool show_hartley_transform_meaning( vector<double> data )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//counter
	int t;
	//Size of the transform
	int size;
	//Temp vectors
	vector<double> amplitude;
	vector<double> phase;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------


	size = data.size();
	//Create vectors
    amplitude = vector<double>( size/2 +1 );
    phase = vector<double>( size/2 );

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	cout << "Size: " << size << "\n";
	//constant frequency
	amplitude[0] = abs( data[0] );
	//frequencies with twin components
	for (t = 1;t < size/2;t++)
	{
		amplitude[t] = sqrt( 2.0 *(data[t] *data[t] +data[size -t] *data[size -t ]) );
	}
	//maximum frequency. just 1 component
	amplitude[size/2] = abs( data[size/2] );

	for (t = 1;t < size/2;t++)
	{
		phase[t] = pi/4.0 +atan2( data[t], data[size -t] );

		phase[t] = CLIP_PI( phase[t], pi );
	}

	for (t = 0;t < size/2 +1;t++)
	{
		//
		cout << "Amplitude f" << t << " : " << ENG_NUM_CSTR( amplitude[t]);

		if ((t > 0) && (t < size/2))
		{
			cout << " | Phase p" << t << " : " << ENG_NUM_CSTR( phase[t]);
		}

		cout << "\n";
	}

	cout << "\n\n\n";
	cout << "NOTES\n";

	cout << "element 0 is zero frequency. It's equivalent to the average of the signal\n";
	cout << "element 1 is f1. it's the slowest sin wave with 1 period over the whole vector\n";
	cout << "element size-1 is again f1. each frequency has two components.\n";
	cout << "element 2 is f2. a sine wave that fits two periods inside the vector\n";
	cout << "element size-2 is again f2.\n";
	cout << "element 3 is f3. a sin with three periods. frequency grow toward the center\n";
	cout << "element 0 and element size/2 have no twin component\n";
	cout << "element of index size/2 is the highest frequency component.\n";
	cout << "the highest frequency component is a sin with a period every two elements\n";
	cout << "amplitude of a twin frequency is: sqrt(2*(fa^2 + fb^2))\n";
	cout << "  example. amplitude of f1 is sqrt( 2* (v[1]^2 +v[size-1]^2))\n";
	cout << "phase of a twin frequency is: pi/4 +atan2( fa, fb )\n";

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return false;
}	//end function: show_hartley_transform_meaning

/****************************************************************************
**
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

void f( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end function:
