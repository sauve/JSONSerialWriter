/*
 * 
 * 
 * By Germain Sauvé
 *
*/

#ifndef __JSONSERIALWRITER_H__
#define __JSONSERIALWRITER_H__

#include <Arduino.h>

// if supported by architecture ATMEGA
#include <avr/pgmspace.h>


class JSONSerialWriter
{
protected:
  boolean newObject;
  boolean nameWritten;
  int arraydepth;
  boolean hadwrittenValue;
  Print* printer;
public:
  JSONSerialWriter();
  JSONSerialWriter( Print* printPtr );

  void setPrint( Print* printPtr );
  void start();
  bool close();

  void startWriter();
  bool closeWriter();
  void writeObjName( const char* name);
  void writeObjName( const __FlashStringHelper* name );
  
  void writeString( const char* str);
  void writeString( const __FlashStringHelper* str );
  void writeNumber( const int value );
  void writeNumber( const long value );
  void writeNumber( const long unsigned value );
  void writeNumber( const byte value );
  void writeNumber( const float value );
  void writeBoolean( const bool value );
  // Date, binary

  void writeValue( const char* name, const int value );
  void writeValue( const char* name, const long value );
  void writeValue( const char* name, const long unsigned value );
  void writeValue( const char* name, const byte value );
  void writeValue( const char* name, const float value );
  void writeValue( const char* name, const bool value );

  void writeValue( const __FlashStringHelper* name, const int value );
  void writeValue( const __FlashStringHelper* name, const long value );
  void writeValue( const __FlashStringHelper* name, const long unsigned value );
  void writeValue( const __FlashStringHelper* name, const byte value );
  void writeValue( const __FlashStringHelper* name, const float value );
  void writeValue( const __FlashStringHelper* name, const bool value );

  void writeValue( const char* name, const char* value);
  void writeValue( const __FlashStringHelper* name, const char* value);
  void writeValue( const char* name, const __FlashStringHelper* value);
  void writeValue( const __FlashStringHelper* name, const __FlashStringHelper* str );
  
  void writeStartObject();
  bool startObject( const char* name );
  bool StartObject( const __FlashStringHelper* name );
  bool closeObject();
  
  void writeStartArray();
  bool startArray( const char* name );
  bool startArray( const __FlashStringHelper* name );
  bool closeArray();
  //bool WriteArray( const char* name, int[] data);
};


#endif