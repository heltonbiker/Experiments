#include "Arduino.h"
#include "BikeLightLib.h"

Light::Light(int pin)
{
	pinMode(pin, OUTPUT);
	// _pin = pin;
}