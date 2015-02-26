/*
 Debounce code from http://arduino.cc/en/Tutorial/Debounce
*/

// constants
const int led = D7;
const int sensorPin = D0;

// keep track of the door state
int doorState;
int lastDoorState;

// debounce variables
long lastDebounceTime = 0;
long debounceDelay = 50;

// This routine runs only once upon reset
void setup()
{
    // Configure the pins to be inputs
    pinMode(sensorPin, INPUT);
    pinMode(led, OUTPUT);
    
    // initialize variables
    doorState = digitalRead(sensorPin);
    lastDoorState = doorState;
}

// This routine loops forever 
void loop()
{
    int sensorReading = digitalRead(sensorPin);
    digitalWrite(led, sensorReading);

    if (sensorReading != lastDoorState){
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay){
        if (sensorReading != doorState){
            String message = sensorReading ? "closed" : "open";
            doorState = sensorReading;
            Spark.publish("makenova/doorState", message);
        }
    }

    lastDoorState = sensorReading;
}
