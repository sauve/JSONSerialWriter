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

  void setPrint( Print* printPtr);
  void start();
  bool close();

  void startWriter();
  bool closeWriter();
  void writeObjName( const char* name);
  void writeObjName( const __FlashStringHelper* name );
  
  void writeString( const char* str);
  void writeString( const __FlashStringHelper* str );
  void writeNumber( int value );
  void writeNumber( long value );
  void writeNumber( long unsigned value );
  void writeNumber( byte value );
  void writeNumber( float value );
  void writeBoolean( bool value );
  // Date, binary

  void writeValue( const char* name, int value );
  void writeValue( const char* name, long value );
  void writeValue( const char* name, long unsigned value );
  void writeValue( const char* name, byte value );
  void writeValue( const char* name, float value );
  void writeValue( const char* name, bool value );

  void writeValue( const __FlashStringHelper* name, int value );
  void writeValue( const __FlashStringHelper* name, long value );
  void writeValue( const __FlashStringHelper* name, long unsigned value );
  void writeValue( const __FlashStringHelper* name, byte value );
  void writeValue( const __FlashStringHelper* name, float value );
  void writeValue( const __FlashStringHelper* name, bool value );

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
  bool StartArray( const __FlashStringHelper* name );
  bool closeArray();
  //bool WriteArray( const char* name, int[] data);
};


#endif