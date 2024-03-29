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

#ifndef FPSTR
#define FPSTR(pstr_pointer) (reinterpret_cast<const __FlashStringHelper *>(pstr_pointer))
#endif


class JSONSerialWriter
{
protected:
  boolean newObject;
  boolean nameWritten;
  boolean isJSONP;
  int arraydepth;
  boolean hadwrittenValue;
  Print* printer;

  void writeComaForValue()
  {
    if (!this->nameWritten && this->hadwrittenValue )
    {
      this->printer->print(',');
    }
  }

  void setEndStateOfValue()
  {
    this->nameWritten = false;
    this->hadwrittenValue = true;
  }

public:
  JSONSerialWriter();
  JSONSerialWriter( Print* printPtr );

  void setPrint( Print* printPtr );
  void start();
  bool close();

  void startWriter();
  void startWriterJSONP( const char* callbackstr);
  void startWriterJSONP( const String &callbackstr);
  void startWriterJSONP( const __FlashStringHelper* callbackstr);

  bool closeWriter();
  void writeObjName( const char* name);
  void writeObjName( const String &str);
  void writeObjName( const __FlashStringHelper* name );
  
  void writeString( const char* str);
  void writeString( const __FlashStringHelper* str );
  void writeString( const String &str);
  void writeNumber( const int value );
  void writeNumber( const int unsigned value );
  void writeNumber( const long value );
  void writeNumber( const long unsigned value );
  void writeNumber( const byte value );
  void writeNumber( const float value );
  void writeNumber( const double value );
  void writeBoolean( const bool value );
  void writeNull();
  // Date, binary

  void writeValue( const char* name, const int value );
  void writeValue( const char* name, const int unsigned value );
  void writeValue( const char* name, const long value );
  void writeValue( const char* name, const long unsigned value );
  void writeValue( const char* name, const byte value );
  void writeValue( const char* name, const float value );
  void writeValue( const char* name, const double value );
  void writeValue( const char* name, const bool value );
  void writeValue( const char* name, const String &str);
  void writeNullValue( const char* name);
  

  void writeValue( const __FlashStringHelper* name, const int value );
  void writeValue( const __FlashStringHelper* name, const int unsigned value );
  void writeValue( const __FlashStringHelper* name, const long value );
  void writeValue( const __FlashStringHelper* name, const long unsigned value );
  void writeValue( const __FlashStringHelper* name, const byte value );
  void writeValue( const __FlashStringHelper* name, const float value );
  void writeValue( const __FlashStringHelper* name, const double value );
  void writeValue( const __FlashStringHelper* name, const bool value );
  void writeValue( const __FlashStringHelper* name, const String &str);
  void writeNullValue( const __FlashStringHelper* name);

  void writeValue( const char* name, const char* value);
  void writeValue( const __FlashStringHelper* name, const char* value);
  void writeValue( const char* name, const __FlashStringHelper* value);
  void writeValue( const __FlashStringHelper* name, const __FlashStringHelper* str );
  
  void writeStartObject();
  bool startObject( const char* name );
  bool startObject( const String &name );
  bool startObject( const __FlashStringHelper* name );
  bool closeObject();
  
  void writeStartArray();
  bool startArray( const char* name );
  bool startArray( const String &name );
  bool startArray( const __FlashStringHelper* name );
  bool closeArray();
};


#endif