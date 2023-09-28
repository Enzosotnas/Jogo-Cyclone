//Link do modelo:
//https://www.instructables.com/Arduino-Cyclone-Game-1/

int led[15] {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, A3, A2, A1, A0};
int bot = 2;
int val_bot;
int val_botold = HIGH;
int currentMillis = 0;    
int offsetMillis  = 0;
int K = 2;

void setup(){
  pinMode (A0, OUTPUT);
  pinMode (A1, OUTPUT);
  pinMode (A2, OUTPUT);
  pinMode (A3, OUTPUT);
  pinMode (A4, OUTPUT);
  pinMode (A5, OUTPUT);
  pinMode (bot, INPUT);
  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (13, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int i = 0;
  val_bot = digitalRead(bot);
  currentMillis =(K*(millis()-offsetMillis))%8000; 
  if(currentMillis>0 && currentMillis<500){
    digitalWrite(A4, HIGH);
    digitalWrite(13, HIGH);
    for(i=1; i<=14; i++){
      digitalWrite(led[i], LOW);
    }
  }
  if(currentMillis>500 && currentMillis<1000){
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
  }
  if(currentMillis>1000 && currentMillis<1500){
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
  }
  if(currentMillis>1500 && currentMillis<2000){
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);  
  }
  if(currentMillis>2000 && currentMillis<2500){
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);  
  }
  if(currentMillis>2500 && currentMillis<3000){
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);  
  }
  if(currentMillis>3000 && currentMillis<3500){
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);  
  }
  if(currentMillis>3500 && currentMillis<4000){
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);  
  }
  if(currentMillis>4000 && currentMillis<4500){
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);  
  }
  if(currentMillis>4500 && currentMillis<5000){
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);  
  }
  if(currentMillis>5000 && currentMillis<5500){
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);  
  }
  if(currentMillis>5500 && currentMillis<6000){
    digitalWrite(3, LOW);
    digitalWrite(A3, HIGH);  
  }
  if(currentMillis>6000 && currentMillis<6500){
    digitalWrite(A3, LOW);
    digitalWrite(A2, HIGH);  
  }
  if(currentMillis>6500 && currentMillis<7000){
    digitalWrite(A2, LOW);
    digitalWrite(A1, HIGH);  
  }
  if(currentMillis>7000 && currentMillis<7500){
    digitalWrite(A1, LOW);
    digitalWrite(A0, HIGH);  
  }
  if(currentMillis>7500 && currentMillis<8000){
    digitalWrite(A0, LOW);
  }
  if(val_bot == HIGH && val_botold == LOW){
    if(currentMillis>7500 && currentMillis<8000){
      int r = 0;
      for(r=0; r<=2; r++){
        digitalWrite(A5, HIGH);
        digitalWrite(A4, HIGH);
        for(i=0; i<=14; i++){
          digitalWrite(led[i], HIGH);
        }
        delay(300);
        digitalWrite(A5, LOW);
        digitalWrite(A4, LOW);
        for(i=0; i<=14; i++){
          digitalWrite(led[i], LOW);
        }
        delay(300);
      }
      K++;
    }
    else{
      for(i=0; i<=14; i++){
        digitalWrite(led[i], HIGH);
      }
      digitalWrite(A4, LOW);
      delay(1500);
      K = 2;
    }
    offsetMillis =((millis()))%8000;
  }
  val_botold = val_bot;
}