#include <PMS.h>
#include <SoftwareSerial.h>
SoftwareSerial pmsSerial(2,3); //Rx, Tx

int line_count=0;


PMS pms(pmsSerial);
PMS::DATA data;

void setup()
{
  Serial.begin(9600);   // GPIO1, GPIO3 (TX/RX pin on ESP-12E Development Board)
  pmsSerial.begin(9600);
  
}

void loop()
{
  //Serial.println("Waking up, wait 3 seconds for stable readings...");
  pms.wakeUp();
  delay(3000);

  //Serial.println("Send read request...");
  pms.requestRead();

  //Serial.println("Reading data...");
  if (pms.readUntil(data))
  {
      if(line_count == 0) {
        Serial.println("PM 1.0,PM 2.5,PM 10.0");
      }  
      else {
        //Serial.print("PM 1.0 (ug/m3): ");
        Serial.print(data.PM_AE_UG_1_0);

        //Serial.print(",PM 2.5 (ug/m3): ");
        Serial.print(",");
        Serial.print(data.PM_AE_UG_2_5);

        //Serial.print(",PM 10.0 (ug/m3): ");
        Serial.print(",");
        Serial.println(data.PM_AE_UG_10_0);

      }
      line_count ++;
    
    
  }
  else
  {
    Serial.println("No data.");
  }

  //Serial.println("Going to sleep for 3 seconds.");
  pms.sleep();
  delay(3000);
  //Serial.println("Waking up, wait 3 seconds for stable readings...");
  pms.wakeUp();
  delay(3000);

  //Serial.println("Send read request...");
  pms.requestRead();

  //Serial.println("Reading data...");
  if (pms.readUntil(data))
  {
    //Serial.print("PM 1.0 (ug/m3): ");
    Serial.print(data.PM_AE_UG_1_0);

    //Serial.print(",PM 2.5 (ug/m3): ");
    Serial.print(",");
    Serial.print(data.PM_AE_UG_2_5);

    //Serial.print(",PM 10.0 (ug/m3): ");
    Serial.print(",");
    Serial.println(data.PM_AE_UG_10_0);
  }
  else
  {
    Serial.println("No data.");
  }

  //Serial.println("Going to sleep for 3 seconds.");
  pms.sleep();
  delay(3000);
}
