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
  if (!this->newObject)
  {
    this->printer->print(",");
  }
  if (this->hadwrittenValue)
  {
    this->printer->print(",");
  }
  this->printer->print("\"");
  this->printer->print(name);
  this->printer->print("\":");
  this->hadwrittenValue = true;
  this->nameWritten = true;
}

void JSONSerialWriter::writeObjName( const __FlashStringHelper* name )
{
  if (!this->newObject)
  {
    this->printer->print(",");
  }
  if (this->hadwrittenValue)
  {
    this->printer->print(",");
  }
  this->printer->print("\"");
  this->printer->print(name);
  this->printer->print("\":");
  this->hadwrittenValue = true;
  this->nameWritten = true;
}

void JSONSerialWriter::writeStartArray()
{
  this->printer->print("[");
  this->arraydepth++;
}

bool JSONSerialWriter::closeArray()
{
  this->printer->print("]");
  this->arraydepth--;
  this->nameWritten = false;
  return true;
}

void JSONSerialWriter::writeString( const char* str)
{
  // should encode escape caracters
  this->printer->print("\"");
  this->printer->print(str);
  this->printer->print("\"");
  this->nameWritten = false;
  this->hadwrittenValue = true;
}

void JSONSerialWriter::writeString( const __FlashStringHelper* name)
{
  // should encode escape caracters
  this->printer->print("\"");
  this->printer->print(name);
  this->printer->print("\"");
  this->nameWritten = false;
  this->hadwrittenValue = true;
}

void JSONSerialWriter::writeNumber( const int value )
{
  if (!this->nameWritten && this->hadwrittenValue )
   {
    this->printer->print(",");
   }
  this->printer->print(value);
  this->nameWritten = false;
  this->hadwrittenValue = true;
}

void JSONSerialWriter::writeNumber( const byte value )
{
  if (!this->nameWritten && this->hadwrittenValue )
   {
    this->printer->print(",");
   }
  this->printer->print(value);
  this->nameWritten = false;
  this->hadwrittenValue = true;
}

void JSONSerialWriter::writeNumber( const float value )
{
  if (!this->nameWritten && this->hadwrittenValue )
   {
    this->printer->print(",");
   }
  this->printer->print(value);
  this->nameWritten = false;
  this->hadwrittenValue = true;
}

void JSONSerialWriter::writeNumber( const long value )
{
  if (!this->nameWritten && this->hadwrittenValue )
   {
    this->printer->print(",");
   }
  this->printer->print(value);
  this->nameWritten = false;
  this->hadwrittenValue = true;
}

void JSONSerialWriter::writeNumber( const long unsigned value )
{
  if (!this->nameWritten && this->hadwrittenValue )
   {
    this->printer->print(",");
   }
  this->printer->print(value);
  this->nameWritten = false;
  this->hadwrittenValue = true;
}

void JSONSerialWriter::writeBoolean( const bool value )
{
  if (!this->nameWritten && this->hadwrittenValue )
   {
    this->printer->print(",");
   }
   if (value)
   {
     this->printer->print(F("true"));
   }
   else
   {
     this->printer->print(F("false"));
   }
   
  
  this->nameWritten = false;
  this->hadwrittenValue = true;
}

// template maybe!? level of support bu compiler?
void JSONSerialWriter::writeValue( const char* name, const int value )
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

void JSONSerialWriter::writeValue( const char* name, const bool value )
{
  this->writeObjName(name);
  this->writeBoolean(value);
}


void JSONSerialWriter::writeValue( const __FlashStringHelper* name, const int value )
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

void JSONSerialWriter::writeValue( const __FlashStringHelper* name, const bool value )
{
  this->writeObjName(name);
  this->writeBoolean(value);
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
    this->printer->print(",");
   }
   this->printer->print("{");
   this->newObject = true;
   this->hadwrittenValue = false;
}

bool JSONSerialWriter::closeObject()
{
   this->printer->print("}");
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

bool JSONSerialWriter::StartObject( const __FlashStringHelper* name )
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

bool JSONSerialWriter::startArray( const __FlashStringHelper* name )
{
  this->writeObjName(name);
  this->writeStartArray();
  return true;
}

/* bool JSONSerialWriter::WriteArray( const char* name, int[] data)
{
  this->StartArray(name);
  // call writeNumber for each element in data
  return false;
} */