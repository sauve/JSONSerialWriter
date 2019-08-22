/*
 * 
 * Coverage of method of json serialization to Serial.
 * Use to test the library implementation.
 * 
 * By Germain Sauvé
 * 
 */
 #include <avr/pgmspace.h>
#include <WString.h>

static const PROGMEM char pgchar[] = {"this is a test"};

#include <Arduino.h>
// include JSONSerialWriter header file 
#include <jsonserialwriter.h>


void setup() {
  Serial.begin(57600);
}

void loop() {
  JSONSerialWriter writer;

  // Output with no bracket

  // Output with bracket
  writer.startWriter();
  // test all type with F() and in memory names
  // byte, char, int, uint. long, ulong, string
  writer.writeValue(F("byte"), (byte)10 );
  writer.writeValue(F("int"), (int)-5 );
  writer.writeValue(F("uint"), (int unsigned)65000 );
  writer.writeValue(F("long"), (long)-5 );
  writer.writeValue(F("ulong"), (long unsigned)4000000000 );
  writer.writeValue(F("float"), 1.012345f );
  writer.writeValue(F("double"), 1.0123456789d );
  // test string in memory and flash
  writer.writeObjName(F("strRAM"));
  writer.writeString("inRAM");

  String str1 = "StringClass";
  writer.writeObjName(str1);
  writer.writeString(str1);
  
  writer.writeObjName(F("strFlash"));
  writer.writeString(F("inFlash"));

  writer.writeObjName(F("pgChar"));
  writer.writeString(FPSTR(pgchar));
  
  
  // espaced character in memory
  writer.writeObjName(F("escaptedStr"));
  writer.writeString("\t\n\r\"\\");
  // test escape characters in flash
  writer.writeObjName(F("escaptedStr"));
  writer.writeString(F("\t\n\r\"\\"));
    
  // add Array
  writer.startArray(F("array1"));
  writer.writeNumber( -5 );
  writer.writeNumber( 20.0f );
  writer.writeNumber( (long unsigned)4000000000 );
  writer.closeArray();
  
  // add object
  writer.startObject(F("object1"));
  writer.writeValue(F("objstring"), F("Str Value"));
  writer.writeValue(F("objint"), -12);
  writer.startArray(F("objarray"));
  writer.writeString("str1");
  writer.writeString(F("str2"));
  writer.closeArray();
  writer.closeObject();

  writer.writeValue(F("afterobj"), 333);
  // close the output
  writer.closeWriter();
  
  delay(4000);
}
