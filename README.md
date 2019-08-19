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

## coverage

Test all methods of the Writer class. Used as complete example and to test the library.

# Limitations

What JSONSerialWriter won't be able to do:

* Calculate the size of the output before serialization
* Serialize to multiple stream 
* Pretty print the output ( no space, no identation, no new line until the end of the serialization )

# Todo

* Create, Compile and debug complex example
* Create new example as unit test
* Should Write of a char be cast to a string or a number ( signed byte )?
* Add example for use of espace char
* Add support for String class
* Arduino library file check and support
    * properties
    * .adoc
    * keywords
* Debug and Optimization
    * methode for value check to write , and set writing state ( could be inline )
* better error support and report
* Select licence
* Release and push as supported library
* Other release to add feature:
    * Add multiple write for the same string value
    * Compile on ARM architecture
    * Add better array support
    * Add raw write support
    * Release new version of librairy


