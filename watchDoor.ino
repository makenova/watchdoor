// name the pins
const int led = D7;
const int sensorPin = D0;

int doorState = 0;

// This routine runs only once upon reset
void setup()
{
    // Configure the pins to be inputs
    pinMode(sensorPin, INPUT);
    pinMode(led, OUTPUT);
    
    doorState = digitalRead(sensorPin);;
}

// This routine loops forever 
void loop()
{
    int sensorReading = digitalRead(sensorPin);
    digitalWrite(led, sensorReading);
    
    if (sensorReading != doorState){
        String message = sensorReading ? "closed" : "open";
        doorState = sensorReading;
        Spark.publish("makenova/doorState", message);
        delay(300);
    }
}
