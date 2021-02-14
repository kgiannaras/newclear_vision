//Variables
int c1=0;
int c2=0;
int c3=0;
int c4=0;
int c5=0;
int c6=0;
int c7=0;
int c8=0;
int c9=0;
int c10=0;
int c11=0;
int c12=0;
float time1;


//HC-SR04   //Αισθητήρας Μέτρησης Απόστασης
const int trigPin3 = 28;
const int echoPin3 = 30;
long duration;
int distance;
int tankfill3;
int buf3[10];
unsigned long int avgValue3;
int z;


//PH
const int analogInPin = A15; 
int sensorValue5 = 0; 
unsigned long int avgValue; 
float b;
int buf[10];
int temp1;
float phValue;


//Servo
#include <Servo.h>//Servo library
Servo servo_test1;//initialize a servo object for the connected servo  dejios
Servo servo_test2;//initialize a servo object for the connected servo aristeros
int angle = 0;    
#define sw1 22 //Διακόπτης Χειροκίνιτου Ελέγχου servos


//DHT-11   //Αισθητήρας Θερμοκρασία Περιβάλλοντος
#include <dht.h>
dht DHT;
#define DHT11_PIN 32 // DHT-11(AM2302)
float hum;  
float temp;
int limit3 = 70;
int limit4 = 70; 
int limit5 = -5;


//HW-103   //Αισθητήρας Υγρασίας Εδάφους
int sensorPin1 = A8; 
int sensorValue1;  
int limit1 = 300; 
int sensorPin2 = A10; 
int sensorValue2;  
int limit2 = 300; 

//Lamp temperture
#define relay7 23 //Λάμπα Θέρμανσης
#define sw2 19 //Διακόπτης Χειροκίνιτου Ελέγχου Λάμπα θέρμανσης

//Fans
#define relay3 29 //Ενεργοποίηση Ανεμιστήρα 1
#define relay4 35 //Ενεργοποίηση Ανεμιστήρα 2
#define sw3 18 //Διακοπτης Χειροκίνιτου Ελέγχου Ανεμιστήρα 1
#define sw4 17 //Διακοπτης Χειροκίνιτου Ελέγχου Ανεμιστήρα 2


//LDR   //Ανιχνευτής Φωτός
int sensorPin = A9; //Σύνδεση LDR στο Analog pin 9
int sensorValue = 0;
int limit = 300; 

//Electric Valve
#define relay5 25 //Ηλεκτροβάνα για Πότισμα
#define relay2 31 //Σύνδεση relay2 στο pin 31 Αντλία
#define sw5 16  //Διακόπτης Χειροκίνιτου Ελέγχου


//Led Ανάπτυξης
#define relay6 27//Ενεργοποιεί τα Led Ανάπτυξης
#define sw6 15 //Διακόπτης Χειροκίνιτου Ελέγχου Led Ανάπτυξης


//Θέρμανση Νερού
#define relay1 21 //Θέρμανση Νερού
//#define sw8  //Διακόπτης Χειροκίνιτου Ελέγχου Θέρμανσης Νερού

//demo switch
#define sw7 26 //Διακόπτης Χειροκίνιτου demo

//DS18B20   //Αδιάβροχος Αισθητήρας Θερμοκρασίας Νερού
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 34
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
 float Celcius=0;
 
//D1 Robot   //Οθόνη
#include <LiquidCrystal.h>
const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 
const int pin_BL = 10; 
LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);
const int lcd_buttons = A0;


//Leds   //Μας Δείχνουν Ποιά Συσκευή Λειτουργεί
const int led1 = 39; 
const int led2 = 41; 
const int led3 = 43; 
const int led4 = 45; 
const int led5 = 47; 
const int led6 = 49; 
const int led7 = 24; 

/*
//Check Battery   //Έλεγχος Της Τάσης Μπαταριας
int led_lowbatt= 36;
int sensorValue3 = 0;

*/
/*
//LedError
const int GreenLed = 50;//Καλή λειτουργία
const int LedError = 54;//Πρόβλημα
int k;
*/
int i;

void setup() {
  
 lcd.print("Initializing");
 delay(2000);
Serial.begin(9600);


 //HC-SR04
pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin3, INPUT); // Sets the echoPin as an Input

//ph
pinMode( A15,INPUT );

//Servo
servo_test1.attach(44);// attach the signal pin of servo to pin30 of arduino
servo_test2.attach(46);// attach the signal pin of servo to pin of arduino
servo_test1.write(0);  //dejios  
servo_test2.write(170); //aristeros

  
//ρελεδες
//pinMode(relay1, OUTPUT); //Set relay1 as an output
pinMode(relay2, OUTPUT); //Set relay2 as an output Αντλία
pinMode(sw1, INPUT);


//DHT-11   //Αισθητήρας Θερμοκρασία Περιβάλλοντος
pinMode(DHT11_PIN, INPUT);

//Fans
pinMode(relay3, OUTPUT); //Set relay3 as an output, Ενεργοποίηση Ανεμιστήρα 1
digitalWrite(relay3, LOW); 
pinMode(relay4, OUTPUT); //Set relay4 as an output, Ενεργοποίηση Ανεμιστήρα 2
digitalWrite(relay4, LOW);
pinMode(sw3, INPUT);
pinMode(sw4, INPUT);
pinMode(sensorPin1, INPUT); //A7
pinMode(sensorPin2, INPUT); //A8
digitalWrite(relay3, HIGH); //Switch relay3 off
digitalWrite(relay4, HIGH); //Swtich relay4 off

//LDR
pinMode(sensorPin, INPUT); //A9

//Electric Valve
pinMode(relay5, OUTPUT); //Set relay5 as an output, Ηλεκτροβάνα
pinMode(relay2, OUTPUT); //Set relay2 as an output, Αντλία
pinMode(sw5, INPUT);
digitalWrite(relay5, HIGH); //Switch relay5 off, Ηλεκτροβάνα
digitalWrite(relay2, HIGH); //Switch relay2 off, Αντλία


//Led Ανάπτυξης
pinMode(relay6, OUTPUT); //Set relay6 as an output, Led Ανάπτυξης
pinMode(sw6, INPUT);
digitalWrite(relay6, HIGH); //Switch relay6 off, Led Ανάπτυξης


//Lamp Temperture
pinMode(relay7, OUTPUT); //Set relay7 as an output,Λάμπα Θέρμανσης
pinMode(sw2, INPUT);
digitalWrite(relay7, HIGH); //Switch relay7 off

//demo switch
pinMode(sw7, INPUT);


//DS18B20
sensors.begin();

//D1 Robot
lcd.begin(16, 2);
lcd.setCursor(0,0);
lcd.print("Newclear Vision");
lcd.setCursor(4,1);
lcd.print("Envitech");
pinMode(lcd_buttons, INPUT); //A0
//lcd.clear();



//Leds
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
pinMode(led6, OUTPUT);
pinMode(led7, OUTPUT);
digitalWrite(led1, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
digitalWrite(led5, LOW);
digitalWrite(led6, LOW);
digitalWrite(led7, LOW);

time1 = millis();

/*

//Αντίσταση Νερού
pinMode(relay1, OUTPUT); //Set relay1 as an output,Θέρμανση Νερού
//pinMode(sw8, INPUT);
digitalWrite(relay1, HIGH); //Switch relay1 off,//Θέρμανση Νερού
*/
/*
//Check Battery
pinMode(led_lowbatt, OUTPUT);
  */

/*
//LedError
pinMode(GreenLed, OUTPUT);
digitalWrite(GreenLed, HIGH);
pinMode(LedError, OUTPUT);

*/


}//end setup



void loop() {
  //PH
ph ();
//Sr04
hcsr3();

if(tankfill3 > 80){
  ph ();    
}



if(millis()-time1 > 15000){
   lcd.clear();
   
lcd.print("Newclear Vision");
lcd.setCursor(4,1);
lcd.print("Envitech");
    time1 = millis();
}

chk_switches();

  



//DHT-11   //Ενεργοποιεί Τους Ανεμιστήρες Όταν Ζεσταθεί Ο Χώρος Και Θερμαίνει Τον Χώρο Με Την Λάμπα Θέρμανσης Αυτόματα Όταν Υπάρχει Παγωνιά
int chk = DHT.read11(DHT11_PIN);
//Read data and store it to variables hum and temp
hum = DHT.humidity;
temp= DHT.temperature;
//Print temp and humidity values to serial monitor
Serial.print("ha");
Serial.print(hum);
Serial.print("ta");
Serial.print(temp);
if (temp<1) {
//k=2;
//Led_Error(k);
lcd.clear();
lcd.print("DHT-11");
lcd.setCursor(0,1);  
lcd.print ("ERROR"); 
}
  



if (temp>limit3) {
if (c7==0){
c7=1;
//Serial.println("sw3 off ");
//Serial.print("c7=");
//Serial.println(c7);
digitalWrite(relay3, LOW); //Ενεργοποίηση Ανεμιστήρα 1
digitalWrite(led3, HIGH);
delay(500);
digitalWrite(led3, LOW);
delay(500);

}
}
else {
if (c7==1){
c7=0;
//Serial.println("sw3 off ");
//Serial.print("c7=");
//Serial.println(c7);
  digitalWrite(relay3, HIGH); 
}
}




if (temp>limit4) {
  if (c8==0){
c8=1;
//Serial.println("sw3 off ");
//Serial.print("c8=");
//Serial.println(c8);
digitalWrite(relay3, LOW); //Ενεργοποίηση Ανεμιστήρα 1
digitalWrite(relay4, LOW); //Ενεργοποίηση Ανεμιστήρα 2
digitalWrite(led3, HIGH);
digitalWrite(led4, HIGH);
//delay(500);
}
}
else {
  if (c8==1){
c8=0;
//Serial.println("sw3 off ");
//Serial.print("c8=");
//Serial.println(c8);
digitalWrite(relay3, HIGH); //Απενεργοποίηση Ανεμιστήρα 1
digitalWrite(relay4, HIGH); //Απενεργοποίηση Ανεμιστήρα 2
digitalWrite(led3, LOW);
digitalWrite(led4, LOW);
//delay(500);
} 
}

/*
if (temp<limit5) {
digitalWrite(relay7, LOW); //Ενεργοποίηση Λάμπα Θέρμανσης
delay(500);
}
else {
digitalWrite(relay7, HIGH);
delay(500); 
}

*/

 
//HW-103   //Μετράμε Την Υγρασία Του Εδάφους Και Ενεργοποιούμε Με Μια Ηλεκτροβάνα Το Πότισμα
sensorValue1 = analogRead(sensorPin1); 
Serial.println("hs1");
sensorValue1 = sensorValue1/100.0;
 sensorValue1 = 10-sensorValue1;
 sensorValue1 = sensorValue1*10.0;
Serial.print(sensorValue1);
if (sensorValue1<1) {
//k=3;
//Led_Error(k);
lcd.clear();
lcd.print("HW-103(1)");
lcd.setCursor(0,1);  
lcd.print ("ERROR"); 
}
if (sensorValue1<limit1) {
  if (c10==0){
c10=1;
//Serial.print("c10=");
//Serial.println(c10);
digitalWrite(relay5, HIGH); //Απενεργοποίηση Ηλεκτροβάνα
digitalWrite(led5, LOW);
//delay(500);
}
}
else {
if (c10==1){
c10=0;
//Serial.print("c10=");
//Serial.println(c10);  
digitalWrite(relay5, LOW); //Ενεργοποίηση Ηλεκτροβάνα
digitalWrite(led5, HIGH);
//delay(500);
}
}
//delay(500); 
sensorValue2 = analogRead(sensorPin2); 
Serial.println("hs2");
sensorValue2 = sensorValue2/100.0; 
sensorValue2 = 10-sensorValue2;
 sensorValue2 = sensorValue2*10.0;
Serial.print(sensorValue2);
if (sensorValue2<1) {
//k=4;
//Led_Error(k);
lcd.clear();
lcd.print("HW-103(2)");
lcd.setCursor(0,1);  
lcd.print ("ERROR"); 
}
if (sensorValue2<limit2) {
  if (c11==0){
c11=1;
//Serial.print("c11=");
//Serial.println(c11);
digitalWrite(relay5, HIGH); //Απενεργοποίηση Ηλεκτροβάνα
digitalWrite(led5, LOW);
//delay(500);
}
}
else {
  if (c11==1){
c11=0;
//Serial.print("c11=");
//Serial.println(c11);
digitalWrite(relay5, LOW); //Ενεργοποίηση Ηλεκτροβάνα
digitalWrite(led5, HIGH);
//delay(500);g;
}
} 


//DS18B20   //ψηφιακος αισθητηρας αδιαβροχος μετραει την θερμοκρασια νερου
sensors.requestTemperatures(); 
Celcius=sensors.getTempCByIndex(0);
Serial.print("c");
Serial.println(Celcius);
delay(500);
if (Celcius<1) {
//k=6;
//Led_Error(k);
lcd.clear();
lcd.print("DS18B20");
lcd.setCursor(0,1);  
lcd.print ("ERROR"); 
}
if(Celcius<8){
  if (c9==0){
c9=1;
//Serial.print("c9=");
//Serial.println(c9);
digitalWrite(relay1, LOW);//Θέρμανση Νερού Ενεργοποιηση
delay(500);
}
}
else{
  if (c9==1){
c9=0;
//Serial.print("c9=");
//Serial.println(c9);
digitalWrite(relay1, HIGH);//Θέρμανση Νερού Απενεργοποιηση
delay(500);
}
}

//D1 Robot
d1_robot_buttons();


if (distance <1) {
//k=8;
//Led_Error(k);
}




}
//end void loop

/*

//Check Battery   //ελεγχος σταθμης μπαταριας
int sensorValue3 = analogRead(A8); 
float voltage = sensorValue3 * (5.00 / 1023.00) * 2; //convert the value to a true voltage.
Serial.print("voltage = ");
Serial.print(voltage); //print the voltage to LCD
Serial.println(" V");
if (voltage < 12.1) //set the voltage considered low battery here
{
digitalWrite(led_lowbatt, HIGH);
}
if (voltage < 12.1) {
k=7;
Led_Error(k);
lcd.clear();
lcd.print("Check Battery");
lcd.setCursor(0,1);  
lcd.print ("ERROR"); 
}
  */


/*

//LDR   //Αισθητήρας Ανύχνευσης Φωτός Ο Οποίος Ενεργοποιεί Αυτόματα Το Φωτισμό Ανάπτυξης Των Φυτών
sensorValue = analogRead(sensorPin); //read the value from the sensor
Serial.println(sensorValue); //prints the values coming from the sensor on the screen
if (sensorValue<1) {
k=5;
Led_Error(k);
lcd.clear();
lcd.print("LDR");
lcd.setCursor(0,1);  
lcd.print ("ERROR"); 
}
if (sensorValue<limit) {
digitalWrite(relay6, HIGH); //Led Ανάπτυξης
digitalWrite(led6, HIGH);
delay(500);
}
else {
digitalWrite(relay6, LOW); //Led Ανάπτυξης
digitalWrite(led6, LOW);
delay(500);
}

*/


/*
//Αντίσταση Νερού   //Την Ενεργοποιουμε για να ζεστανουμε το νερο με το ρελε 8
if(digitalRead(sw8)==HIGH){
if (c8==0){
c8=1
digitalWrite(relay1, HIGH);//Θέρμανση Νερού
digitalWrite(led8, LOW);
delay(500);
}
}else{
if (c8==1){
c8=0
digitalWrite(relay1, LOW);//Θέρμανση Νερού
digitalWrite(led8, HIGH);
delay(500);
}
}
*/



/*
//Led Error   //
 void Led_Error(int k)
{
digitalWrite(GreenLed, LOW);
for (int i = 1; i = k ; i++){
digitalWrite(LedError, HIGH);
delay (1000);
digitalWrite(LedError, LOW);
delay (1000);
}
digitalWrite(GreenLed, HIGH);
}


*/
