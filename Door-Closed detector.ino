long duration, cm;
int opentime=0;
int defalut_flag=0;
 
void setup() {
  Serial.begin (9600);             // Serial Port begin
  pinMode(12, OUTPUT);             //triger pin
  pinMode(11, INPUT);              //echo pin 
  pinMode(7,OUTPUT);               //buzzier
}

void loop()
{
  //in the beginning, off the buzzier
  if(defalut_flag=0){
    digitalWrite(7,HIGH);
    defalut_flag=1;
  }

  //use ultrasonic sensor to get the distance between the door and the door frame
  digitalWrite(12, LOW);
  delayMicroseconds(5);
  digitalWrite(12, HIGH);
  delayMicroseconds(10);
  digitalWrite(12, LOW);

  pinMode(11, INPUT);             // read the echo
  duration = pulseIn(11, HIGH);   // obtain the calculation time
 
  cm = (duration/2) / 29.1;         //convert into cm

  Serial.print("Distance : ");  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if((cm>30)&&(cm<100)){
    opentime++;
    Serial.print("open time: ");
    Serial.print(opentime);
    Serial.println();
  }else{
    opentime=0;
    digitalWrite(7,HIGH);
  }

  if(opentime>30){
    Serial.print("Door is forget to close!");
    digitalWrite(7,LOW);
    Serial.println();
  }

  delay(1000);
}
