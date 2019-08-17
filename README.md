# JSONSerialWriter
Simple in place Arduino JSON stream serializer 

Supports:
* Use of Print class as output 
* Low level access to element writing methods
* Support for string in flasf memory ( progmem )

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

* Add better array support
* Document code of simple example
* Create, Compile and debug complex example
* Add null write method
* Add character escape mecanism
* Add example for use of espace char
* Compile on ARM architecture
* Debug and Optimization
* better error support and report
* Arduino library file check and support
* Release and push as supported library
