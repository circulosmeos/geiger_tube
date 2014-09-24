geiger_tube
===========

Code for the cooking-hacks.com's radiation detection board adapted to the Raspberry Pi (console output).

Code from

http://www.cooking-hacks.com/documentation/tutorials/geiger-counter-raspberry-pi-radiation-sensor-board#source_code

Adapted by circulosmeos (circulosmeos.wordpress.com):

arduPi v1.5 adapted and safe loop

See 

http://circulosmeos.wordpress.com/2014/04/21/radiation-detection-with-raspberry-pi/

COMPILATION
===========

$ g++ -lrt -lpthread geiger_tube.c arduPi.cpp -o geiger_tube
