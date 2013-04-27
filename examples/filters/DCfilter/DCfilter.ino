/* Example of filtering an analog input to remove DC bias,
 *  using Mozzi sonification library.
 *  
 *  Demonstrates DCfilter(), DC-blocking filter useful for 
 *  highlighting changes in control signals.
 *  The output of the filter settles to 0 if the incoming signal stays constant.
 *  If the input changes, the filter output swings to track the change and 
 *  eventually settles back to 0.
 *   
 *  Mozzi help/discussion/announcements:
 *  https://groups.google.com/forum/#!forum/mozzi-users
 *
 *  Tim Barrass 2013.
 *  This example code is in the public domain.
 *   
 */
#include <DCfilter.h>

int sensorPin = A0; 
int sensorValue = 0;  // variable to store the value coming from the sensor

DCfilter dcFiltered(0.9); // parameter sets how long the filter takes to settle

void setup() {
  Serial.begin(115200);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin); 
  Serial.print(sensorValue); 
  Serial.print("  Filtered = "); 
  Serial.println(dcFiltered.next(sensorValue));
  delay(20);                  
}

