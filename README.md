# Si5351-Shield-Test-Resources

This repository contains materials to support the Kanga / m0xpd Si5351 Shield

In order to test for the presence of the device on the Arduino I2C bus, there is a simple I2C Scanner sketch

In order to exercise the shield's RF generator capabilities, there is a simple sketch which will set up all 
three channels of the Si5351 - 

CLK0 and CLK1 are set at constant frequencies and CLK2 is set to generate a simple step-wise "sweep"

This test sketch uses Jason Milldrum, nt7s' excellent Si5351 Library.
