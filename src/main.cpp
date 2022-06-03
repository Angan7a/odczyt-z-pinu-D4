
#include "MyESP.hpp"
#include <OneWire.h>
#include <DallasTemperature.h>
#include "ThingSpeak.h"

// https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/

#define zapatka 3  // RX

#define ONE_WIRE_BUS 2  // DS18B20 on arduino pin2 corresponds to D4 on physical board
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);
float prevTemp = 0;
const char* server = "api.thingspeak.com";
String apiKey = "IHXD144KFX8UOY4B";


MyMotor MyESP::myMotor;
MyESP myESP;

void setup() {
	pinMode(zapatka,  INPUT_PULLUP);
}

void loop() {
	bool t = digitalRead(zapatka) == 0;
	delay(100);
	if( digitalRead(zapatka) == 0 )
	{
		MyESP::myMotor.startWatering();
	} else
	{
		MyESP::myMotor.stopWatering();
	}
	delay(100);
}

