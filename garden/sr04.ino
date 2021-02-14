
/*
//HC-SR04   //Αισθητήρας Μέτρησης Απόστασης
const int trigPin3 = 30;
const int echoPin3 = 28;
long duration;
int distance;
int tankfill3;
int buf3[10];
unsigned long int avgValue3;
int z;
*/


void sr04(){

// Clears the trigPin
digitalWrite(trigPin3, LOW);
delayMicroseconds(2);
//Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin3, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");
//Serial.println(distance);


}




void hcsr3(){
  
for(int i=0;i<10;i++) 
 {
digitalWrite(trigPin3, LOW);// Clears the trigPin
delayMicroseconds(2);

digitalWrite(trigPin3, HIGH);// Sets the trigPin on HIGH state for 10 micro seconds
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);


  buf3[i]= pulseIn(echoPin3, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds 
  delay(10);
 }
 for(int i=0;i<9;i++)
 {
  for(int j=i+1;j<10;j++)
  {
   if(buf3[i]>buf3[j])
   {
  temp=buf3[i];
  buf3[i]=buf3[j];
  buf3[j]=temp;    
   }
  }
 }
 avgValue3=0;
 for(int i=2;i<8;i++)
 {
 avgValue3+=buf3[i];
 }
 float distance3 =(float)avgValue3*0.034/2/6;
//Serial.print("Distance3: ");// Prints the distance on the Serial Monitor
//Serial.println(distance3); 
 z =distance3/27*100;
tankfill3 = 100-z;

Serial.println("tk");
Serial.println(tankfill3); 
//Serial.println("%");

}//HCSR3
