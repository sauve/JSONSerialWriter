/*
 * 
 * 
 * By Germain Sauvé
 *
*/

#ifndef __SERIALJSONWRITER_H__
#define __SERIALJSONWRITER_H__

#include <Arduino.h>
#include <avr/pgmspace.h>


class SerialJSONWriter
{
protected:
  boolean newObject;
  boolean nameWritten;
  int arraydepth;
  boolean hadwrittenValue;
public:
  SerialJSONWriter();

  void StartWriter();
  void StopWriter();
  void WriteObjName( const char* name);
  void WriteObjName( const PROGMEM char* name );
  
  void writeStartArray();
  void writeStopArray();
  void writeStringValue( const char* str);
  void writeStringValue( const PROGMEM char* str );
  
  void writeNumber( int value );
  void writeNumber( byte value );
  void writeNumber( float value );
  void writeBoolean( bool value );
  void writeStartObject();
  void writeStopObject();
  
  
  bool StartObject( const char* name );
  bool StartObject( const PROGMEM char* name );
  bool CloseObject();
  
  bool StartArray( const char* name );
  bool StartArray( const PROGMEM char* name );
  bool CloseArray();
  bool WriteArray( const char* name, int[] data)
  
  
};


#endif