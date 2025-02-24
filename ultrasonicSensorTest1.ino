#include <MeMegaPi.h>

MeUltrasonicSensor ultrasonic(PORT_6); // Ultrasonic sensor on PORT 7
MeDCMotor motorLeft(PORT2);            // Left motor connected to PORT 2
MeDCMotor motorRight(PORT1);           // Right motor connected to PORT 1

void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    float distance = ultrasonic.distanceCm(); // Measure distance in cm
    Serial.print("Distance: ");
    Serial.println(distance);

    if (distance > 0 && distance < 20) { // Ensure valid readings and check distance
        digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on
        motorLeft.stop();
        motorRight.stop();
    } else {
        digitalWrite(LED_BUILTIN, LOW);   // Turn the LED off
        motorLeft.run(100);
        motorRight.run(100);
    }

    delay(100); // Shorter delay for quicker response
}

