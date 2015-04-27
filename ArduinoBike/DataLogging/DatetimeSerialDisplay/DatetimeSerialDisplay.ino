#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;
const int chipSelect = 4;
File dataFile;

void setup () {
    
    Wire.begin();

    rtc.begin();

    if (! rtc.isrunning()) {
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // date and time THIS script has been compiled
    }
    
    pinMode(10, OUTPUT); // necessary for SD library
    
    if (!SD.begin(chipSelect))
    {
        return;
    }

    dataFile = SD.open("datalog.txt", FILE_WRITE);

}

void loop () {

    DateTime now = rtc.now();    
    String line = "";

    line += String(now.year()) + '/';
    line += pad(now.month()) + '/';
    line += pad(now.day()) + ' ';
    line += pad(now.hour()) + ':';
    line += pad(now.minute()) + ':';
    line += pad(now.second());

    line += " - ";

    for (int analogPin = 0; analogPin < 3; analogPin++) {
        String sensorValue = String(analogRead(analogPin));
        
        if (sensorValue.length() == 1)
            sensorValue = '0' + sensorValue;
        
        line += String(sensorValue);
        if (analogPin < 2) {
            line += ", ";
        }
    }    
    


    if (dataFile) {
        dataFile.println(line);
    }
    //dataFile.close();

    //delay(100);
}

String pad(int s)
{
  String resultado = String(s);
  if (resultado.length() == 1) 
      return '0' + resultado;
  else
      return resultado;
}
