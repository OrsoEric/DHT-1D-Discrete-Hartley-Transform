# DHT-1D-Discrete-Hartley-Transform  
This program implements a naive DHT. I use it to understand the meaning of the output vector  
The FT Fourier Transform transforms complex number in time into complex frequencies  
HT is the equivalent for purely real number  
The DHT and the FHT are closely related  
It can be extended into multiple dimensions  
Multidimensionals transforms are useful for image and video processing  
Giving a neural network access to both the signal and its transform might enchance its capability  

OUTPUT  
OrangeBot Projects  
Parameters  
number of periods of sin inside the vector: +4.000  
amplitude of the wave: +1.000  
phase of the wave: +0.000  
  
Signal  
size: 16  
+0.000  | +1.000  | +122.5a | -1.000  | -244.9a | +1.000  | +367.4a | -1.000  | -489.8a | +1.000  | +612.3a | -1.000  | -734.8a | +1.000  | +857.2a | -1.000  |  
Transform  
size: 16  
+41.63a | +104.1a | +15.81a | -17.35a | +500.0m | +135.3a | -76.33a | +183.9a | -697.7a | -270.6a | -428.3a | -825.7a | -500.0m | -128.4a | +603.7a | +10.41a |  
Anti-Transform  
size: 16  
-2.345f | +1.000  | -1.050f | -1.000  | -1.041f | +1.000  | -628.3a | -1.000  | -97.90a | +1.000  | -2.814f | -1.000  | -1.417f | +1.000  | +3.607f | -1.000  |  
Hartley Transform Meaning  
Size: 16  
Amplitude f0 : +41.63a  
Amplitude f1 : +147.9a | Phase p1 : -885.1m  
Amplitude f2 : +854.0a | Phase p2 : +811.6m  
Amplitude f3 : +183.2a | Phase p3 : +919.7m  
Amplitude f4 : +1.000  | Phase p4 : +980.1a  
Amplitude f5 : +1.183f | Phase p5 : +623.0m  
Amplitude f6 : +615.2a | Phase p6 : +961.8m  
Amplitude f7 : +462.7a | Phase p7 : +188.6m  
Amplitude f8 : +697.7a  
  
  

NOTES  
element 0 is zero frequency. It's equivalent to the average of the signal  
element 1 is f1. it's the slowest sin wave with 1 period over the whole vector  
element size-1 is again f1. each frequency has two components.  
element 2 is f2. a sine wave that fits two periods inside the vector  
element size-2 is again f2.  
element 3 is f3. a sin with three periods. frequency grow toward the center  
element 0 and element size/2 have no twin component  
element of index size/2 is the highest frequency component.  
the highest frequency component is a sin with a period every two elements  
amplitude of a twin frequency is: sqrt(2*(fa^2 + fb^2))  
  example. amplitude of f1 is sqrt( 2* (v[1]^2 +v[size-1]^2))  
phase of a twin frequency is: pi/4 +atan2( fa, fb )  
  
Process returned 0 (0x0)   execution time : 0.020 s  
Press any key to continue.  

