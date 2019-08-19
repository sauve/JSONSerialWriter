/*
 * 
 * Simple example of json serialization to Serial
 * 
 * By Germain Sauvé
 * 
 */

#include <Arduino.h>
// include JSONSerialWriter header file 
#include <jsonserialwriter.h>


void setup() {
  // Init default Serial communication at 57600 baud
  Serial.begin(57600);
}

void loop() {
  // Declare JSONSerialWriter in this scope and name it wtiter 
  JSONSerialWriter writer;

  // Reinitialize the state and Write the start of a object to Serial  
  writer.startWriter();

  // Write the value temperature with a integer value of 10
  writer.writeValue( "temperature", 10 );

  // Write the value of humidity with name store in Flash and value as float
  writer.writeValue( F("humidity"), 22.87f );

  // Write the string value "winddirection" with both name and value in Flash memory
  writer.writeValue( F("winddirection"), F("North"));

  // Write an array of integer values for the variable name "photocells" store in memory
  writer.startArray(F("photocells"));
  // Writer values of the array
  writer.writeNumber( 10 );
  writer.writeNumber( 20 );
  writer.writeNumber( 30 );
  writer.writeNumber( 40 );
  // Write the end of the current "photocells" array
  writer.closeArray();
  
  // Start an element name "sensorstatus" 
  writer.startObject( F("sensorstatus") );
  // Write string value with both name and value in RAM
  writer.writeValue( "version", "1.0.1" );
  // Write the long unsigned value of milliseconds since the program started as "uptime"
  writer.writeValue( F("uptime"), millis() );
  // Write the boolean value with name "active"
  writer.writeValue( F("active"), true );
  // Close the current "sensorstatus" object 
  writer.closeObject();

  // Close the writer ( not the stream ) which end the serialization
  writer.closeWriter();

  // Wait 4 seconds before looping again
  delay(4000);
}
