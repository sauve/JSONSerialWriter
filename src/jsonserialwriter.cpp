/*
 * 
 * 
 * By Germain Sauvé
 *
*/

#include "jsonserialwriter.h"

JSONSerialWriter::JSONSerialWriter()
{
  this->printer = &Serial;
  this->start();
}

JSONSerialWriter::JSONSerialWriter( Print* printPtr )
{
  this->printer = printPtr;
  this->start();
}


void JSONSerialWriter::setPrint( Print* printPtr)
{
  this->printer = printPtr;
}


void JSONSerialWriter::start()
{
  this->arraydepth = 0;
  this->newObject = true;
  this->nameWritten = false;
  this->hadwrittenValue = false;
}

bool JSONSerialWriter::close()
{
  //check for array and object depth
  this->printer->println();
  return true;
}

void JSONSerialWriter::startWriter()
{
  this->start();
  this->writeStartObject();
}

bool JSONSerialWriter::closeWriter()
{
  this->closeObject();
  return this->close();
}

void JSONSerialWriter::writeObjName( const char* name)
{
  if (!this->newObject || this->hadwrittenValue)
  {
    this->printer->print(',');
  }
  this->printer->print('\"');
  this->printer->print(name);
  this->printer->print("\":");
  this->hadwrittenValue = true;
  this->nameWritten = true;
}

void JSONSerialWriter::writeObjName( const String &name)
{
  this->writeObjName( name.c_str() );
}

void JSONSerialWriter::writeObjName( const __FlashStringHelper* name )
{
  if (!this->newObject || this->hadwrittenValue)
  {
    this->printer->print(',');
  }
  this->printer->print('\"');
  this->printer->print(name);
  this->printer->print("\":");
  this->hadwrittenValue = true;
  this->nameWritten = true;
}

void JSONSerialWriter::writeStartArray()
{
  this->printer->print('[');
  this->arraydepth++;
}

bool JSONSerialWriter::closeArray()
{
  this->printer->print(']');
  this->arraydepth--;
  this->nameWritten = false;
  return true;
}

void JSONSerialWriter::writeString( const char* str)
{
  if ( str == NULL)
   {
     this->writeNull();
     return;
   }

  this->writeComaForValue();
  // should encode escape caracters
  this->printer->print('\"');
  // naive implementation of escape characters mapping
  // should optimize by advanving pointer/size until translation and wirting thise in bulk
  int startidx = 0;
  int curidx = 0;
  char curChar = *str;
  while(  curChar )
  {
    switch( curChar )
    {
      case '\b':
        // block copy start to current
        this->printer->write( str + startidx, curidx - startidx );
        startidx = curidx + 1;
        this->printer->print("\\b");
        break;
      case '\f':
        this->printer->write( str + startidx, curidx - startidx );
        startidx = curidx + 1;
        this->printer->print("\\f");
        break;
      case '\t':
        this->printer->write( str + startidx, curidx - startidx );
        startidx = curidx + 1;
        this->printer->print("\\t");
        break;
      case '\n':
        this->printer->write( str + startidx, curidx - startidx );
        startidx = curidx + 1;
        this->printer->print("\\n");
        break;
      case '\r':
        this->printer->write( str + startidx, curidx - startidx );
        startidx = curidx + 1;
        this->printer->print("\\r");
        break;
      case '\\':
        this->printer->write( str + startidx, curidx - startidx );
        startidx = curidx + 1;
        this->printer->print("\\\\");
        break;
      case '\"':
        this->printer->write( str + startidx, curidx - startidx );
        startidx = curidx + 1;
        this->printer->print("\\\"");
        break;
    }
    curChar = *(str + curidx++);
  }
  this->printer->write( str + startidx, curidx - startidx );
  this->printer->print('\"');
  this->setEndStateOfValue();
}

// This is the implementation for the ATMEGA328P
void JSONSerialWriter::writeString( const __FlashStringHelper* str)
{
  if ( str == NULL)
   {
     this->writeNull();
     return;
   }

  this->writeComaForValue();
  // should encode escape caracters


  this->printer->print('\"');
  // need to read via progmem byte per byte fro character translation

  char* flashptr = (char*)str;
  char curChar = pgm_read_byte_near(flashptr++);
  while( curChar )
  {
    switch( curChar )
    {
      case '\b':
        this->printer->print("\\b");
        break;
      case '\f':
        this->printer->print("\\f");
        break;
      case '\t':
        this->printer->print("\\t");
        break;
      case '\n':
        this->printer->print("\\n");
        break;
      case '\r':
        this->printer->print("\\r");
        break;
      case '\\':
        this->printer->print("\\\\");
        break;
      case '\"':
        this->printer->print("\\\"");
        break;
      default:
        this->printer->print( curChar);
        break;
    }
    curChar = pgm_read_byte_near(flashptr++);
  }
  this->printer->print('\"');
  this->setEndStateOfValue();
}

void JSONSerialWriter::writeString( const String &str)
{
  this->writeString( str.c_str() );
}

void JSONSerialWriter::writeNumber( const int value )
{
  this->writeComaForValue();
  this->printer->print(value);
  this->setEndStateOfValue();
}

void JSONSerialWriter::writeNumber( const int unsigned value )
{
  this->writeComaForValue();
  this->printer->print(value);
  this->setEndStateOfValue();
}

void JSONSerialWriter::writeNumber( const byte value )
{
  this->writeComaForValue();
  this->printer->print(value);
  this->setEndStateOfValue();
}

void JSONSerialWriter::writeNumber( const float value )
{
 this->writeComaForValue();
  this->printer->print(value, 4);
  this->setEndStateOfValue();
}

void JSONSerialWriter::writeNumber( const double value )
{
  this->writeComaForValue();
  this->printer->print(value, 8);
  this->setEndStateOfValue();
}

void JSONSerialWriter::writeNumber( const long value )
{
  this->writeComaForValue();
  this->printer->print(value);
  this->setEndStateOfValue();
}

void JSONSerialWriter::writeNumber( const long unsigned value )
{
  this->writeComaForValue();
  this->printer->print(value);
  this->setEndStateOfValue();
}

void JSONSerialWriter::writeBoolean( const bool value )
{
  this->writeComaForValue();
   if (value)
   {
     this->printer->print(F("true"));
   }
   else
   {
     this->printer->print(F("false"));
   }
   
  
  this->setEndStateOfValue();
}

void JSONSerialWriter::writeNull()
{
  this->writeComaForValue();
  this->printer->print(F("null"));
  this->setEndStateOfValue();
}

// template maybe!? level of support bu compiler?
void JSONSerialWriter::writeValue( const char* name, const int value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}

void JSONSerialWriter::writeValue( const char* name, const int unsigned value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}

void JSONSerialWriter::writeValue( const char* name, const long value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}

void JSONSerialWriter::writeValue( const char* name, const long unsigned value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}


void JSONSerialWriter::writeValue( const char* name, const byte value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}

void JSONSerialWriter::writeValue( const char* name, const float value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}

void JSONSerialWriter::writeValue( const char* name, const double value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}

void JSONSerialWriter::writeValue( const char* name, const bool value )
{
  this->writeObjName(name);
  this->writeBoolean(value);
}

void JSONSerialWriter::writeValue( const char* name, const String &str)
{
  this->writeObjName(name);
  this->writeString(str);
}

void JSONSerialWriter::writeNullValue( const char* name)
{
  this->writeObjName(name);
  this->writeNull();
}

void JSONSerialWriter::writeValue( const __FlashStringHelper* name, const int value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}

void JSONSerialWriter::writeValue( const __FlashStringHelper* name, const int unsigned value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}

void JSONSerialWriter::writeValue( const __FlashStringHelper* name, const long value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}

void JSONSerialWriter::writeValue( const __FlashStringHelper* name, const long unsigned value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}


void JSONSerialWriter::writeValue( const __FlashStringHelper* name, const byte value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}

void JSONSerialWriter::writeValue( const __FlashStringHelper* name, const float value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}

void JSONSerialWriter::writeValue( const __FlashStringHelper* name, const double value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}

void JSONSerialWriter::writeValue( const __FlashStringHelper* name, const bool value )
{
  this->writeObjName(name);
  this->writeBoolean(value);
}

void JSONSerialWriter::writeValue( const __FlashStringHelper* name, const String &str)
{
  this->writeObjName(name);
  this->writeString(str);
}

void JSONSerialWriter::writeNullValue( const __FlashStringHelper* name)
{
  this->writeObjName(name);
  this->writeNull();
}

void JSONSerialWriter::writeValue( const char* name, const char* value)
{
  this->writeObjName(name);
  this->writeString(value);
}

void JSONSerialWriter::writeValue( const __FlashStringHelper* name, const char* value)
{
  this->writeObjName(name);
  this->writeString(value);
}

void JSONSerialWriter::writeValue( const char* name, const __FlashStringHelper* value)
{
  this->writeObjName(name);
  this->writeString(value);
}

void JSONSerialWriter::writeValue( const __FlashStringHelper* name, const __FlashStringHelper* str )
{
  this->writeObjName(name);
  this->writeString(str);
}


void JSONSerialWriter::writeStartObject()
{
   if (!this->nameWritten && !this->newObject )
   {
    this->printer->print(',');
   }
   this->printer->print('{');
   this->newObject = true;
   this->hadwrittenValue = false;
}

bool JSONSerialWriter::closeObject()
{
   this->printer->print('}');
   this->newObject = false;
   this->hadwrittenValue = true;
   this->nameWritten = false;
   return true;
}

bool JSONSerialWriter::startObject( const char* name )
{
  this->writeObjName(name);
  this->writeStartObject();
  return true;
}

bool JSONSerialWriter::startObject( const String &name )
{
  this->writeObjName(name);
  this->writeStartObject();
  return true;
}

bool JSONSerialWriter::startObject( const __FlashStringHelper* name )
{
  this->writeObjName(name);
  this->writeStartObject();
  return true;
}


bool JSONSerialWriter::startArray( const char* name )
{
  this->writeObjName(name);
  this->writeStartArray();
  return true;
}

bool JSONSerialWriter::startArray( const String &name )
{
  this->writeObjName(name);
  this->writeStartArray();
  return true;
}

bool JSONSerialWriter::startArray( const __FlashStringHelper* name )
{
  this->writeObjName(name);
  this->writeStartArray();
  return true;
}