//D1 Robot

void d1_robot_buttons() {
int x;
x = analogRead(lcd_buttons);
//Serial.print("x of lcd buttons = ");
//Serial.println(x);
lcd.setCursor(10,1);
if (x < 60) {
//RIGHT
lcd.clear();
lcd.setCursor(0,1);  
lcd.print ("Battery=");
lcd.setCursor(8,1);
//lcd.print (voltage);
lcd.setCursor(13,1);
lcd.print ("V");
time1 = millis();

}
else if (x < 200) {
//UP
lcd.clear();
lcd.setCursor(0,1);  
lcd.print ("HC-SR04=");
lcd.setCursor(9,1);
lcd.print (tankfill3);
time1 = millis();
}
else if (x < 400){
  
//DOWN
lcd.clear();
//lcd.setCursor(0,0);
//lcd.print("PH = ");
//lcd.setCursor(5,0);
//lcd.print(phValue); 
lcd.setCursor(0,1);  
lcd.print ("WaterTemp=");
lcd.setCursor(11,1);
lcd.print (Celcius);
time1 = millis();
}
else if (x < 600){
  
//LEFT
lcd.clear();
lcd.print("Hum.Soil_1=");
lcd.setCursor(11,0);
lcd.print (sensorValue1); 
lcd.setCursor(14,0);
lcd.print("%");
lcd.setCursor(0,1);
lcd.print ("Hum.Soil_2=");
lcd.setCursor(11,1);
lcd.print (sensorValue2);
lcd.setCursor(14,1);
lcd.print("%"); 
time1 = millis();
   
}
else if (x < 800){
  
//SELECT
lcd.clear();
lcd.print("Temp=");
lcd.setCursor(5,0);
lcd.print (temp); 
lcd.setCursor(0,1);
lcd.print ("Humidity=");
lcd.setCursor(9,1);
lcd.print (hum);
lcd.setCursor(14,1);
lcd.print("%");
time1 = millis();
}

}
