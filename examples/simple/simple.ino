/*
 * 
 * Simple example fo json serialization
 * 
 * By Germain Sauvé
 * 
 */

 #include <jsonserialwriter.h>

JSONSerialWriter writer;

void setup() {
  Serial.begin(57600);
}

void loop() {
  //
  writer.Start();
  writer.writeValue( "temperature", 10 );
  writer.writeValue( "humidity" 22.87f );
  writer.WriteArray( "photocells", [ 10, 20, 30, 40] );
  writer.StartObject( "sensorstatus" );
  writer.writeValue( "name", "testsensor" );
  writer.writeValue( "version", "1.0.1" );
  writer.writeValue( "uptime", millis() );
  writer.CloseObject();
  writer.Close();
}
