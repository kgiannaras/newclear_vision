
void chk_switches(){
//Servo
if(digitalRead(sw1)==HIGH){
  if (c1==0){
c1=1;
digitalWrite(led1, LOW);
//Serial.println("sw1 off");
//Serial.print("c1=");
//Serial.println(c1);
//disable
//dejios
servo_test1.write(5);//down command to rotate the servo to the specified angle
delay(100);                       
//aristeros
servo_test2.write(170);//down command to rotate the servo to the specified angle
delay(150);                       
}
}

else if(digitalRead(sw1)==LOW){
if (c1==1){
c1=0;
digitalWrite(led1, HIGH);
//("sw1 on ");
//Serial.print("c1=");
//Serial.println(c1);
//enable
//dejios
servo_test1.write(170);//up command to rotate the servo to the specified angle
delay(150);                       
//aristeros
servo_test2.write(5);//up command to rotate the servo to the specified angle
delay(150);                       
}
}
//end sw1

//Lamp Temperature
if(digitalRead(sw2)==HIGH){
  if (c2==0){
c2=1;
//Serial.println("sw2 off ");
//Serial.print("c2=");
//Serial.println(c2);
digitalWrite(relay7, HIGH);//απενεργοποιηση Λάμπα Θερμανσης
digitalWrite(led2, LOW);
delay(500);
}
}
else if(digitalRead(sw2)==LOW){ 
if (c2==1){
c2=0;
//Serial.println("sw2 on ");
//Serial.print("c2=");
//Serial.println(c2);
digitalWrite(relay7, LOW); //ενεργοποιηση Λάμπα Θερμανσης
digitalWrite(led2, HIGH);
delay(500);
}
}
//end sw2





//Fans   Έχουμε Την Δυνατότητα Να Ενεργοποιούμε Χειροκίνιτα Τους Ανεμιστήρες Με Διακόπτες
if(digitalRead(sw3)==HIGH){
if (c3==0){
c3=1;
//Serial.println("sw3 off ");
//Serial.print("c3=");
//Serial.println(c3);
digitalWrite(relay3, HIGH); //απενεργοποιηση ανεμιστηρα
digitalWrite(led3, LOW);
}
}
else if(digitalRead(sw3)==LOW){
if (c3==1){
c3=0;
//Serial.println("sw3 on ");
//Serial.print("c3=");
//Serial.println(c3);
digitalWrite(relay3, LOW); //ενεργοποιηση ανεμιστηρα
digitalWrite(led3, HIGH);
}
}
//end sw3

//Fans   Έχουμε Την Δυνατότητα Να Ενεργοποιούμε Χειροκίνιτα Τους Ανεμιστήρες Με Διακόπτες
if(digitalRead(sw4)==HIGH){
if (c4==0){
c4=1;
//Serial.println("sw4 off ");
//Serial.print("c4=");
//Serial.println(c4);
digitalWrite(relay4, HIGH);//apenergopoihsh anemisthra
digitalWrite(led4, LOW);
}
}
else if(digitalRead(sw4)==LOW){
if (c4==1){
c4=0;
//Serial.println("sw4 on ");
//Serial.print("c4=");
//Serial.println(c4);
digitalWrite(relay4, LOW);//energopoihsh anemisthra
digitalWrite(led4, HIGH);
}
}
//end sw4



//Electric Valve
if (digitalRead(sw5)==HIGH){
if (c5==1){
c5=0;
//Serial.println("sw5 off ");
//Serial.print("c5=");
//Serial.println(c5);
digitalWrite(relay5, HIGH);//Απενεργοποίηση Ηλεκτροβάνα
digitalWrite(relay2, HIGH);//Απενεργοποίηση Αντλία
digitalWrite(led5, LOW);
delay(500);
}
}
else if(digitalRead(sw5)==LOW){
if (c5==0){
c5=1;
//Serial.println("sw5 on ");
//Serial.print("c5=");
///Serial.println(c5);
digitalWrite(relay5, LOW);//Ενεργοποίηση Ηλεκτροβάνα
digitalWrite(relay2, LOW);//Ενεργοποίηση Αντλία
digitalWrite(led5, HIGH);
delay(500);
}
}
//end sw5



//Led Ανάπτυξης
if(digitalRead(sw6)==HIGH){
if (c6==0){
c6=1;
//Serial.println("sw6 off ");
//Serial.print("c6=");
//Serial.println(c6);
digitalWrite(relay6, HIGH);//Led Ανάπτυξης
digitalWrite(led6, LOW);
delay(500);
}
}
else if(digitalRead(sw6)==LOW){
if (c6==1){
c6=0;
//Serial.println("sw6 on ");
//Serial.print("c6=");
//Serial.println(c6);
digitalWrite(relay6, LOW);//Led Ανάπτυξης
digitalWrite(led6, HIGH);
delay(500);
}
}
//end sw6


//demo
if(digitalRead(sw7)==HIGH){
if (c12==0){
c12=1;


//dejios
servo_test1.write(5);//down command to rotate the servo to the specified angle
delay(100);                       
//aristeros
servo_test2.write(170);//down command to rotate the servo to the specified angle
delay(150);
digitalWrite(relay7, HIGH);//απενεργοποιηση Λάμπα Θερμανσης
digitalWrite(led2, LOW);
digitalWrite(relay3, HIGH); //απενεργοποιηση ανεμιστηρα
digitalWrite(led3, LOW);
digitalWrite(relay4, HIGH);//apenergopoihsh anemisthra
digitalWrite(led4, LOW);
digitalWrite(relay5, HIGH);//Απενεργοποίηση Ηλεκτροβάνα
//digitalWrite(relay2, HIGH);//Απενεργοποίηση Αντλία
digitalWrite(relay6, HIGH);//apenergopoihsh Led Ανάπτυξης
digitalWrite(led7, LOW);
delay(500);
}
}
else if(digitalRead(sw7)==LOW){
if (c12==1){
c12=0;
digitalWrite(led7, HIGH);
//dejios
servo_test1.write(170);//up command to rotate the servo to the specified angle
delay(4000);  
digitalWrite(led1, HIGH);
 //dejios
servo_test1.write(5);//down command to rotate the servo to the specified angle                    
//aristeros
servo_test2.write(5);//up command to rotate the servo to the specified angle
delay(4000);
servo_test2.write(170);//down command to rotate the servo to the specified angle
delay(4000);
//aristeros
servo_test2.write(5);//up command to rotate the servo to the specified angle
//dejios
servo_test1.write(170);//up command to rotate the servo to the specified angle
delay(4000); 
servo_test2.write(170);//down command to rotate the servo to the specified angle
servo_test1.write(5);//down command to rotate the servo to the specified angle 
delay(2000);


digitalWrite(led1, LOW);
digitalWrite(relay7, LOW); //ενεργοποιηση Λάμπα Θερμανσης
digitalWrite(led2, HIGH);
delay(4000);
digitalWrite(relay7, HIGH);//απενεργοποιηση Λάμπα Θερμανσης
digitalWrite(led2, LOW);
delay(2000);
digitalWrite(relay3, LOW); //ενεργοποιηση ανεμιστηρα
digitalWrite(led3, HIGH);
delay(4000);
digitalWrite(relay3, HIGH); //απενεργοποιηση ανεμιστηρα
digitalWrite(led3, LOW);
delay(2000);
digitalWrite(relay4, LOW);//energopoihsh anemisthra
digitalWrite(led4, HIGH);
delay(4000);
digitalWrite(relay4, HIGH);//apenergopoihsh anemisthra
digitalWrite(led4, LOW);
delay(2000);
digitalWrite(relay5, LOW);//Ενεργοποίηση Ηλεκτροβάνα
digitalWrite(led5, HIGH);
delay(4000);
digitalWrite(relay5, HIGH);//Απενεργοποίηση Ηλεκτροβάνα
digitalWrite(led5, LOW);
delay(2000);
//digitalWrite(relay2, LOW);//Ενεργοποίηση Αντλία
digitalWrite(relay6, LOW);//Led Ανάπτυξης
digitalWrite(led6, HIGH);
delay(5000);
digitalWrite(relay6, HIGH);//apenergopoihsh Led Ανάπτυξης
digitalWrite(led6, LOW);
delay(2000);

}
}
//end sw7


}//end void chk_switches()
