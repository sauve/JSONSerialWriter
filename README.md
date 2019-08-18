# JSONSerialWriter
Simple in place Arduino JSON stream serializer 

Supports:
* Use of Print class as output 
* Low level access to element writing methods
* Support for string in flash memory ( progmem ) for both name and value

# Installation

In Arduino/libraries

# Usage

See examples

## simple

Output an simulated temperature and humidity sensor with sensor info. 

Shows how to:
* write basic type as value ( string, number, boolean, null)
* use string store in flash for variable name and value
* write array of number
* create a sub obbject

## complex

Graph structure with long IDs stores in flash memory.

# Todo

* Document code of simple example
* Create, Compile and debug complex example
* Create new example as unit test
* Should Write of a char be cast to a string or a number ( signed byte )?
* Add character escape mecanism
* Add example for use of espace char
* Compile on ARM architecture
* Add better array support
* Debug and Optimization
    * methode for value check to write , and set writing state ( could be inline )
* better error support and report
* Arduino library file check and support
* Release and push as supported library
