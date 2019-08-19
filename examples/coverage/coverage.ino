/*
 * 
 * Coverage of method of json serialization to Serial.
 * Use to test the library implementation.
 * 
 * By Germain Sauvé
 * 
 */

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
  // test escape characters in memory
  writer.writeObjName("escaptedStr");
  writer.writeString("\t\n\r\"\\");
  // test escape characters in flash  
  // add Array

  // add object

  // close the output
  writer.closeWriter();
  
  delay(4000);
}
