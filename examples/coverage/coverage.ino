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
  
  // add Array

  // add object

  // close the output
  writer.closeWriter();
  
  delay(4000);
}
