#include <Adafruit_DHT.h>

#define DHTTYPE DHT11
#define DHTPIN 	D6

DHT dht(DHTPIN, DHTTYPE);

void setup() {
	dht.begin();
}

void loop() {
	// Read temperature in Celsius
	float currentTemp = dht.getTempCelcius();
	
	// if sensor reading fails
	if (isnan(currentTemp)) {
	    return;
	}
	
	// Publish current temp
	Particle.publish("temp", String(currentTemp), PRIVATE);
	
	delay(1000);
}
