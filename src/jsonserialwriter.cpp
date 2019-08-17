/*
 * 
 * 
 * By Germain Sauvé
 *
*/

#include "jsonserialwriter.h"

JSONSerialWriter::JSONSerialWriter()
{
  this->start();
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
  Serial.println();
  return true;
}

void JSONSerialWriter::writeObjName( const char* name)
{
  if (!this->newObject)
  {
    Serial.print(",");
  }
  if (this->hadwrittenValue)
  {
    Serial.print(",");
  }
  Serial.print("\"");
  Serial.print(name);
  Serial.print("\": ");
  this->hadwrittenValue = true;
  this->nameWritten = true;
}

/* void JSONSerialWriter::WriteObjName( const PROGMEM char* name )
{
  if (!this->newObject)
  {
    Serial.print(",");
  }
  if (this->hadwrittenValue)
  {
    Serial.print(",");
  }
  Serial.print("\"");
  Serial.print(name);
  Serial.print("\": ");
  this->hadwrittenValue = true;
  this->nameWritten = true;
} */

void JSONSerialWriter::writeStartArray()
{
  Serial.print("[");
  this->arraydepth++;
}

bool JSONSerialWriter::closeArray()
{
  Serial.print("]");
  this->arraydepth--;
  this->nameWritten = false;
  return true;
}

void JSONSerialWriter::writeString( const char* str)
{
  // should encode escape caracters
  Serial.print("\"");
  Serial.print(str);
  Serial.print("\"");
  this->nameWritten = false;
}

/* void JSONSerialWriter::writeString( const PROGMEM char* name)
{
  // should encode escape caracters
  Serial.print("\"");
  Serial.print(str);
  Serial.print("\"");
  this->nameWritten = false;
} */

void JSONSerialWriter::writeNumber( int value )
{
  Serial.print(value);
  this->nameWritten = false;
}

void JSONSerialWriter::writeNumber( byte value )
{
  Serial.print(value);
  this->nameWritten = false;
}

void JSONSerialWriter::writeNumber( float value )
{
  Serial.print(value);
  this->nameWritten = false;
}

void JSONSerialWriter::writeNumber( long value )
{
  Serial.print(value);
  this->nameWritten = false;
}

void JSONSerialWriter::writeNumber( long unsigned value )
{
  Serial.print(value);
  this->nameWritten = false;
}

void JSONSerialWriter::writeBoolean( bool value )
{
  Serial.print(value);
  this->nameWritten = false;
}

// template maybe!? level of support bu compiler?
void JSONSerialWriter::writeValue( const char* name, int value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}

void JSONSerialWriter::writeValue( const char* name, long value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}

void JSONSerialWriter::writeValue( const char* name, long unsigned value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}


void JSONSerialWriter::writeValue( const char* name, byte value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}

void JSONSerialWriter::writeValue( const char* name, float value )
{
  this->writeObjName(name);
  this->writeNumber(value);
}

void JSONSerialWriter::writeValue( const char* name, bool value )
{
  this->writeObjName(name);
  this->writeBoolean(value);
}

void JSONSerialWriter::writeValue( const char* name, const char* value)
{
  this->writeObjName(name);
  this->writeString(value);
}

/* void JSONSerialWriter::writeValue( const PROGMEM char* name, const PROGMEM char* str )
{
  this->WriteObjName(name);
  this->writeString(value);
}
 */

void JSONSerialWriter::writeStartObject()
{
   if (!this->nameWritten && !this->newObject )
   {
    Serial.print(",");
   }
   Serial.print("{");
   this->newObject = true;
   this->hadwrittenValue = false;
}

bool JSONSerialWriter::closeObject()
{
   Serial.print("}");
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

/* bool JSONSerialWriter::StartObject( const PROGMEM char* name )
{
  this->WriteObjName(name);
  this->writeStartObject();
  return true;
}
 */

bool JSONSerialWriter::startArray( const char* name )
{
  this->writeObjName(name);
  this->writeStartArray();
  return true;
}

/* bool JSONSerialWriter::StartArray( const PROGMEM char* name )
{
  this->WriteObjName(name);
  this->writeStartArray();
  return true;
} */

/* bool JSONSerialWriter::WriteArray( const char* name, int[] data)
{
  this->StartArray(name);
  // call writeNumber for each element in data
  return false;
} */