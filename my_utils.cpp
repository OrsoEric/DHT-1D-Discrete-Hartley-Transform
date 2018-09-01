/****************************************************************************
**	OrangeBot Project
*****************************************************************************
**        /
**       /
**      /
** ______ \
**         \
**          \
*****************************************************************************
**	My_utils
**	Class with common utilities as static methods
*****************************************************************************
**	Author: 			Orso Eric
**	Creation Date:
**	Last Edit Date:
**	Revision:			3
**	Version:			1.1
****************************************************************************/

/****************************************************************************
**	HYSTORY VERSION
*****************************************************************************
**	V0.1
**		engineering format
**		random init
**		random double
**	V1.0
**		ported engineering format to std::string output
**		added seed print on log file with debug.h
**		refactored libraries to C++ style
**		refactored namespaces
**	V1.1
**		tested template methods just for methods and not class wide
**		refactor to: T get_rand<template type T>(T min, Tmax)
**		added overloading: T get_rand<template type T>(void)
**		tested bool method overloading for no range parameters (bool doesn't have range. Only two values)
**		ported get_rand<double>
**		ported get_rand<float>
**		ported get_rand<int>
**		added fast int method for small range of output random int
**	V1.2
**		added DEG_TO_RAD and RAD_TO_DEG macros
**		rand int now works with min==max
**		rand int now provide results with full range min to max
**		std::array is now used instead of std::string inside eng_num
**		fixed bug when sometimes a number very close to 1 would shows as 1000.0m
****************************************************************************/

/****************************************************************************
**	DESCRIPTION
*****************************************************************************
**
****************************************************************************/

/****************************************************************************
**	KNOWN BUG
*****************************************************************************
**
****************************************************************************/

/****************************************************************************
**	INCLUDES
****************************************************************************/

//Standard C Libraries
#include <cstdio>		//for fprintf
#include <cstdlib> 		//for rand
#include <ctime>		//for time(NULL)
#include <cmath>		//for std::round
//Standard C++ Libraries
#include <iostream>		//for std::cout, std::endl
#include <string>		//for std::string
#include <sstream>		//for std::ostringstream
//Debug log file
#include "debug.h"
//Class Header
#include "my_utils.h"

/****************************************************************
**	USING NAMESPACES
**	Using allows to skip redundant statements. Instead of "std::cout" you write just "cout"
**	NOTE: Use only specific parts of a namespace. It's bad practice to use all of std.
****************************************************************/

using std::string;
using std::ostringstream;

/****************************************************************************
**	NAMESPACES
****************************************************************************/

namespace User
{

/****************************************************************************
**	GLOBAL VARIABILE
****************************************************************************/

/****************************************************************************
*****************************************************************************
**	CONSTRUCTORS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Empty Constructor
**	My_utils | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

My_utils::My_utils( void )
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
}	//end constructor:

/****************************************************************************
*****************************************************************************
**	DESTRUCTORS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Default Destructor
**	~My_utils | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

My_utils::~My_utils( void )
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
}	//end empty constructor

/****************************************************************************
*****************************************************************************
**	SETTERS
*****************************************************************************
****************************************************************************/

/****************************************************************************
*****************************************************************************
**	GETTERS
*****************************************************************************
****************************************************************************/

/****************************************************************************
*****************************************************************************
**	TESTERS
*****************************************************************************
****************************************************************************/

/****************************************************************************
*****************************************************************************
**	PUBLIC METHODS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Public Static Method
**	rand_init( void )
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	wrapper for srand and time.
**	free user of including time.h and stdlib.h in the files just for this function.
****************************************************************************/

bool My_utils::rand_init( void )
{
    ///--------------------------------------------------------------------------
    ///	STATIC VARIABILE
    ///--------------------------------------------------------------------------

    ///--------------------------------------------------------------------------
    ///	LOCAL VARIABILE
    ///--------------------------------------------------------------------------

    //Random Seed
    time_t seed;

    ///--------------------------------------------------------------------------
    ///	CHECK
    ///--------------------------------------------------------------------------

    //Trace Enter with arguments
    DENTER();

    ///--------------------------------------------------------------------------
    ///	INITIALIZATIONS
    ///--------------------------------------------------------------------------

    ///--------------------------------------------------------------------------
    ///	BODY
    ///--------------------------------------------------------------------------

	//Calculate the random seed
    seed = time( NULL );
    //Initialize random generator to the seed
	srand(seed);

    ///--------------------------------------------------------------------------
    ///	FINALIZATIONS
    ///--------------------------------------------------------------------------

    //If something interesting happened in this run, you can recover the seed in the 'debug.log' and rerun it
    //Trace Return vith return value
    DRETURN_ARG("seed: %ld\n", seed);

    return false;	//OK
}	//end method: rand_init | void

/****************************************************************************
**	Public Static Method
**  get_rand<bool> | void
*****************************************************************************
**	PARAMETER:
**		p: probability to get true
**	RETURN:
**	DESCRIPTION:
**	Get a random bool. true | false at 50% probability
**	make sure to initialize the random generator to make each execution unique
**	User::My_utils::rand_init() is a wrapper that also saves the seed in the log file
****************************************************************************/

template <>
bool My_utils::get_rand<bool>( float p )
{
    ///--------------------------------------------------------------------------
    ///	STATIC VARIABILE
    ///--------------------------------------------------------------------------

    ///--------------------------------------------------------------------------
    ///	LOCAL VARIABILE
    ///--------------------------------------------------------------------------

	//Temp value
    int tmp;
    //return value
	bool ret;

    ///--------------------------------------------------------------------------
    ///	CHECK
    ///--------------------------------------------------------------------------

    ///--------------------------------------------------------------------------
    ///	INITIALIZATIONS
    ///--------------------------------------------------------------------------

    ///--------------------------------------------------------------------------
    ///	BODY
    ///--------------------------------------------------------------------------

    //Call the standard random function
    tmp = rand();
    //Apply threshold
	ret = (1.0*tmp < 1.0*p*RAND_MAX);

    ///--------------------------------------------------------------------------
    ///	FINALIZATIONS
    ///--------------------------------------------------------------------------

    //return random
    return ret;
}	//end method: get_rand<bool> | void

/****************************************************************************
**	Public Static Method
**	get_rand<double> | double, double
*****************************************************************************
**	PARAMETER:
**		min, max	:	Range of the generated number
**	RETURN:
**	DESCRIPTION:
**	Get a random double within a given range.
****************************************************************************/

template <>
double My_utils::get_rand<double>( double min, double max )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//int random
	int tmp;
	//double random
	double ret;

	///--------------------------------------------------------------------------
	///	CHECK AND INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//Get a random number
	tmp = rand();
	//Convert directly into float.
	ret = min +(max -min)*(1.0*tmp)/(1.0*RAND_MAX);

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return ret;
}	//end function: rand_double | double, double

/****************************************************************************
**	Public Static Method
**	get_rand<float> | float, float
*****************************************************************************
**	PARAMETER:
**		min, max	:	Range of the generated number
**	RETURN:
**	DESCRIPTION:
**	Get a random float within a given range.
****************************************************************************/

template <>
float My_utils::get_rand<float>( float min, float max )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//int random
	int tmp;
	//double random
	float ret;

	///--------------------------------------------------------------------------
	///	CHECK AND INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------
	//	By default the C compiler treats constant as double. need to cast type
	//	+1.0 -> is a double by default
	//	(float)+1.0 -> is a float

	//Get a random number
	tmp = rand();
	//Convert directly into float.
	ret = min +(max -min)*((float)1.0*tmp)/((float)1.0*RAND_MAX);

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return ret;
}	//end function: get_rand<float> | float, float

/****************************************************************************
**	Public Static Method
**	get_rand<int> | int, int
*****************************************************************************
**	PARAMETER:
**		min, max	:	Range of the generated number
**	RETURN:
**	DESCRIPTION:
**	Get a random int within a given range.
**	Use a fast version when the range is small enough
**	When range is big, use interpolation in floating point
****************************************************************************/

template <>
int My_utils::get_rand<int>( int min, int max )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//Range of the output
	int delta;
	//int random
	int tmp;
	//double random
	int ret;

	///--------------------------------------------------------------------------
	///	CHECK AND INITIALIZATIONS
	///--------------------------------------------------------------------------

	//handle case min == max
	if (min == max)
	{
		return min;
	}

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------
	//	By default the C compiler treats constant as double. need to cast type
	//	+1.0 -> is a double by default
	//	(float)+1.0 -> is a float

	//Get a random number
	tmp = rand();
	//compute range
	delta = max -min;

		///--------------------------------------------------------------------------
		///	Limited range number generation
		///--------------------------------------------------------------------------
		//	If range is below threshold can use a fast % operator without compromising
		//	on the distribution of the output

	//If: below range threshold
	if (delta <= GET_RAND_INTERPOLATION_THRESHOLD)
	{
		//sum minimum by reminder of integer division by delta
		ret = min +tmp %(delta +1);
	}	//End If: below range threshold
	//If: above range threshold
	else
	{
		float tmp_float;
		//Convert directly into float.
		tmp_float = ((float)1.0 *min) +((float)1.0 *delta)*((float)1.0*tmp)/((float)1.0*RAND_MAX);
		//Round the result
		ret = round( tmp_float );
	}	//End If: above range threshold

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return ret;
}	//end function: get_rand<float> | float, float

/****************************************************************************
**	Public Method
**	\class	eng_num | double
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	\brief
**	Show a number in engineering notation
**	four sgnificant digit, 10^n*3 suffix, optional unit of measure
**	x.xxx s
**	xx.xx s
**	xxx.x s
**	Exponents
**	index	|	-6	-5	-4	-3	-2	-1	0	+1	+2	+3	+4	+5	+6
**	exp		|	-18	-15	-12	-9	-6	-3	0	+3	+6	+9	+12	+15	+18
**	suffix	|	a	f	p	n	u	m		K	M	G	T	P	E
****************************************************************************/

std::string My_utils::eng_num( double num )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	//exponents suffix string
	static const string suffix("afpnum KMGTPE");

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//Continue flag
	bool f_continue;
	//sign flag
	bool f_sign;
	//Counter
	int cnt;
	//Number of digits after the point
	int precision;
	//Create a streaming string that supports the same operators as cout
	ostringstream tmp_str_stream;

	///--------------------------------------------------------------------------
	///	CHECK AND INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------
	//	ALGORITHM:
	//	multiply or divide by 1000 until the number is > 1.0 && < 1000.0
	//	create a string with the '.' in the right place and with the right suffix and unit if applicable

		///STEP1: Make num between >1.0 <1000.0 and calculate 10^3X suffix

	///While Init
	//if: input is exactly 0, i don't have to scale it
	f_continue = (num != 0.0);
	//if: number is negative
	if (num < 0.0)
	{
		//remember sign
		f_sign = true;
		//make positive
		num = -num;
	}
	else
	{
		//remember sign
		f_sign = false;
	}
	//initialize exponent counter
	cnt = 0;

	///Compute multiplier
	//while: i'm not done
	while (f_continue == true)
	{
		//if: too small
		if ((num < 1.0) && ((std::abs((double)num -1.0)) > 0.0005))
		{
			//inflate by 10^3
			num = num *1000.0;
			cnt--;
		}
		//if: too big
		else if (num > 1000.0)
		{
			//shrink by 10^3
			num = num /1000.0;
			cnt++;
		}
		//if: sweet spot
		else
		{
			//done
			f_continue = false;
		}
		//if: I run out of fraction suffixes
		if (cnt < -6)
		{

			//The number is actually 0.000
			return ((f_sign)?(string("-0.000 ")):(string("+0.000 ")));
		}
		//if: i run out of multiplicative suffixes
		else if (cnt > 6)
		{
			//the number is infinite
			//done
			f_continue = false;
			//fail. return local empty string
			return string(" TOOBIG");
		}
	}	//end While: i'm not done

		///STEP2: print sign
	//Push the right sign into the string stream
	tmp_str_stream << ((f_sign)?('-'):('+'));

		///STEP3: print number with right precision
	///Precision
	//Algorithm prevents numbers lower than 1.0 or bigger than 1000.0 to exist by this point
	//Push the number inside the string stream
	if (num < 10.0)
	{
		//X.XXX
		precision = 3;
	}
	else if (num < 100.0)
	{
		//XX.XX
		precision = 2;
	}
	else
	{
		//XXX.X
		precision = 1;
	}

	///Format Settings
	//Show right number of digits after point
	tmp_str_stream.precision( precision );
	//Show floating point in fixed point format
	tmp_str_stream.setf( tmp_str_stream.fixed );
	//This is to fix representation of non meaningful zeros after point
	//left alignment
	tmp_str_stream.setf( tmp_str_stream.left );
	//Number is always five character wide
	tmp_str_stream.width( 5 );
	//Fill all spaces with number zero
	tmp_str_stream.fill('0');

	///Print Number
	//push number inside the string
	tmp_str_stream << num;

		///STEP4: Add Unit Suffix
	//I can access string with brackets. It's an overloading of std::string
	tmp_str_stream << suffix[cnt +6];

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	//Convert from string stream to string. It's a local class, it will be destroyed when it goes out of scope. No memory leak.
	return tmp_str_stream.str();
}	//end method: eng_num

/****************************************************************************
*****************************************************************************
**	PRIVATE METHODS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Public Method
**
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

bool My_utils::dummy( void )
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

    //Trace Enter with arguments
    DENTER_ARG("in: %d\n", 0);

    if (false)
    {
        //Trace Return vith return value
        DRETURN_ARG("ERROR: %d\n", 0);
        return true; //Fail
    }

    ///--------------------------------------------------------------------------
    ///	INITIALIZATIONS
    ///--------------------------------------------------------------------------

    ///--------------------------------------------------------------------------
    ///	BODY
    ///--------------------------------------------------------------------------

    ///--------------------------------------------------------------------------
    ///	FINALIZATIONS
    ///--------------------------------------------------------------------------

    //Trace Return vith return value
    DRETURN_ARG("done: %d\n", 0);

    return false;	//OK
}	//end method:

/****************************************************************************
**	NAMESPACES
****************************************************************************/

} //End Namespace
