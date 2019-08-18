/*
 * 
 * Simple example of json serialization
 * 
 * By Germain Sauvé
 * 
 */

#include <Arduino.j>
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

  // Write 
  writer.writeValue( F("humidity"), 22.87f );
  writer.writeValue( F("winddirection"), F("North"));
  writer.writeValue( F("windgust"), 2.6f);
  writer.writeValue( "rain", F("none"));
  char* nostr = 0;
  writer.writeValue( F("pressure"), nostr);
  
  writer.startArray(F("photocells"));
  writer.writeNumber( 10 );
  writer.writeNumber( 20 );
  writer.writeNumber( 30 );
  writer.writeNumber( 40 );
  writer.closeArray();
  
  // writer.WriteArray( F("photocells"), [ 10, 20, 30, 40] );
  
  writer.startObject( "sensorstatus" );
  writer.writeValue( "name", "testsensor" );
  writer.writeValue( "version", "1.0.1" );
  writer.writeValue( "uptime", millis() );
  writer.writeValue( F("active"), true );
  writer.closeObject();
  writer.closeWriter();
  delay(4000);
}
