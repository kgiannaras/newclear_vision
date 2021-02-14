//proapaitoymena στην περιοχη δηλωσεων
//const int analogInPin = A15; 
//int sensorValue5 = 0; 
//unsigned long int avgValue; 
//float b;
//int buf[10];
//int temp1;
//float phValue;

//ph προαπαιτουμενα στο void setup
//pinMode( A15,INPUT );



void ph() {

for(int i=0;i<10;i++) 
 { 
  buf[i]=analogRead(analogInPin);
  delay(10);
 }
 for(int i=0;i<9;i++)
 {
  for(int j=i+1;j<10;j++)
  {
   if(buf[i]>buf[j])
   {
    temp1=buf[i];
    buf[i]=buf[j];
    buf[j]=temp1;
   }
  }
 }
 avgValue=0;
 for(int i=2;i<8;i++)
 {
 avgValue+=buf[i];
 }
 float pHVol=(float)avgValue*5.0/1024/6;
 phValue = -5.70 * pHVol + 21.34;
 }
