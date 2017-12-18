// This #include statement was automatically added by the Particle IDE.
#include "web.h"

// Connect Vin to 3-5VDC
// Connect GND to ground
// Connect SCL to I2C clock pin (D1 on Photon/Electron)
// Connect SDA to I2C data pin  (D0 on Photon/Electron)


#include "Adafruit_Si7021.h"

Adafruit_Si7021 sensor = Adafruit_Si7021();

double h;
double t;
int sensorValue;
int humidifier = D6;
String userHumidity = "";
String humidity = "";
String temperature = "";

void setup() {
    
    //initiate the sensor
    sensor.begin();

    // set data variables
    Particle.variable("Sensor", &sensorValue, INT);
    Particle.variable("t", &t, DOUBLE);
    Particle.variable("h", &h, DOUBLE);
    Particle.variable("userHumidity", &userHumidity, STRING);
    Particle.variable("humidity", &humidity, STRING);
    Particle.variable("temperature", &temperature, STRING);
    
    pinMode(humidifier, OUTPUT);
    pinMode(D7, OUTPUT);
    
    Particle.function("detect", detect);
}

void loop() {
    
    //get data
    sensorValue = sensor.begin();
    h = sensor.readHumidity();
    t = sensor.readTemperature();

    // Publish data
    String temperature = String(t);
    String humidity = String(h);

    Particle.publish("temperature", temperature, PRIVATE);
    Particle.publish("humidity", humidity, PRIVATE);
    
    if (h < userHumidity.toFloat() && h > 0) {
        digitalWrite(humidifier, HIGH);
        digitalWrite(D7, HIGH);
    }
    else {
        digitalWrite(humidifier, LOW);
        digitalWrite(D7, LOW);
    }
    
    delay(3000);
    
}

int detect ( String arg) {
    userHumidity = arg;
    return 0;
}
