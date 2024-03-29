# JSONSerialWriter
Simple in place Arduino JSON stream serializer 

Supports:
* Use of Print class as output 
* Low level access to element writing methods
* Support for string in flash memory ( progmem ) for both name and value
* Start serilalization as JSONP and close it correctly

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

## coverage

Test all methods of the Writer class. Used as complete example and to test the library.

# Limitations

What JSONSerialWriter won't be able to do:

* Calculate the size of the output before serialization
* Serialize to multiple stream 
* Pretty print the output ( no space, no identation, no new line until the end of the serialization )

# Todo

* Implement naive escaped char with pg_read from flash
    * Test UNO
    * Test MEGA
    * Test Nano
* Create, Compile and debug complex example
    * Add example for use of escaped char
* Should Write of a char be cast to a string or a number ( signed byte )?
* Arduino library file check and support
    * properties
    * .adoc
    * keywords
    * add a contribute or other file
* Debug and Optimization
    * escape character writer in bulck if no mapping needed ( not a per char print! )
    * better error support and report
* Select licence ( MIT? )
* Release and push as supported library
* Other features for subsequent release:
    * Add multiple write for the same string value
    * Compile on ARM architecture ( sam and samd, need other board to test )
    * Add better array support
    * Add raw write support


