#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

#define moisturepin A0
#define signalpin 6
int moisturevalue = 0;

void setup()
{
  pinMode(moisturepin,INPUT);
  pinMode(signalpin,OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop()
{
  moisturevalue = analogRead(moisturepin);
  Serial.print("Moisture Level : ");
  Serial.println(moisturevalue/10);
	
  lcd.setCursor(0,0);
  lcd.print("Moisture Value....");
 
  lcd.setCursor(13,1);
  lcd.print(moisturevalue/10);
  if(moisturevalue == 0) lcd.print(00);
  lcd.setCursor(15,1);
  lcd.print("%");
  
  if(moisturevalue <= 400)
  {
    digitalWrite(signalpin,HIGH);
    lcd.setCursor(0,1);
    lcd.print("Motor is On ");
  }
  else
  {
    digitalWrite(signalpin,LOW);
    lcd.setCursor(0,1);
    lcd.print("Motor is Off ");
  }
  
  
}