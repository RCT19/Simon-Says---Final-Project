int button = 13;
int button2 = 12;
int button3 = 11;
int led = 10;
int led2 = 9;
int led3 = 8;
int buttonstate = 0;
int buttonstate2 = 0;
int buttonstate3 = 0;
int sbstate = 0;
int buzzer = 7;
int time = 1000;
long r;
int level = 1;
int amount = 1;
int lives = 3;
unsigned char pattern[20]; 
int patternindex = 0;
boolean failure = false;
boolean victory = false; 
int counter = 0;
const int kPinSpeaker = 7;
#define NOTE_C4 262
#define NOTE_D4 294 
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523

void setup(){
  
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(kPinSpeaker, OUTPUT);
  randomSeed(analogRead(0));
}

void loop(){
  
  if(level == 1){
    digitalWrite(led, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(1000);
  }
  
  while(level < 21){
    
    for(amount = 0; amount < level; amount++){
      
      if(amount == (level - 1)){
        r = random(1,4);
        pattern[amount] = r;   
      }
      else{
        r = pattern[amount];
      }
      if(r == 1){
        digitalWrite(led, HIGH);
        digitalWrite(buzzer, HIGH);
        tone(buzzer, 1000);
        delay(time);
        digitalWrite(led, LOW);
        noTone(buzzer);     
        delay(time);    
      }
      if(r == 2){
        digitalWrite(led2, HIGH);
        digitalWrite(buzzer, HIGH);
        tone(buzzer, 2000);
        delay(time);
        digitalWrite(led2, LOW);
        noTone(buzzer);     
        delay(time); 
      }
      if(r == 3){
        digitalWrite(led3, HIGH);
        digitalWrite(buzzer, HIGH);
        tone(buzzer, 3000);
        delay(time);
        digitalWrite(led3, LOW);
        noTone(buzzer);     
        delay(time);   
      } 
      
    } // end for (amount)
    
    break;
  } // end while
  
  for(int i = 0; i < level; i++){
    
    do{
      buttonstate = digitalRead(button);
      buttonstate2 = digitalRead(button2);
      buttonstate3 = digitalRead(button3);
    } while(buttonstate == LOW && buttonstate2 == LOW && buttonstate3 == LOW);
    
    failure = false;
    
    if(buttonstate == HIGH){
      digitalWrite(led, HIGH);
      tone(buzzer, 1000); 
      delay(1000);
      digitalWrite(led, LOW);
      noTone(buzzer);
      if(1 != pattern[i]){
        failure = true;
        break;
      }
    }
    else{
      digitalWrite(led, LOW);
      noTone(buzzer);
    }
    if(buttonstate2 == HIGH){
      digitalWrite(led2, HIGH);
      tone(buzzer, 2000);
      delay(1000); 
      digitalWrite(led2, LOW);
      noTone(buzzer); 
      if(2 != pattern[i]){
        failure = true;
        break;
      }
    }
    else{
      digitalWrite(led2, LOW);
      noTone(buzzer);
    }
    if(buttonstate3 == HIGH){
      digitalWrite(led3, HIGH);
      tone(buzzer, 3000);
      delay(1000); 
      digitalWrite(led3, LOW);
      noTone(buzzer);  
      if(3 != pattern[i]){
        failure = true;
        break;
      }
    }
    else{
      digitalWrite(led3, LOW);
      noTone(buzzer);
    }
  } // end for( i )
  
  if(failure == true){
    delay(500);
    digitalWrite(led, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    tone(buzzer, 500);
    delay(200);
    digitalWrite(led, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    tone(buzzer, 500);
    delay(200);
    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);    
    tone(buzzer, 500);
    delay(200);
    digitalWrite(led3, LOW);
    noTone(buzzer); 
    delay(1000);
    lives--;
  } //end if failure
  else {
    delay(500);
    digitalWrite(led, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(500);
    level++;
    time = (time - 25);
  } // end else
  
  if(lives == 0){
    delay(500);
    digitalWrite(led, HIGH);
    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    digitalWrite(led3, LOW);
    delay(500);
    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led2, LOW);
    level = 1;
    delay(500);
  } //end lives = 0 if
  
  if(level == 22){
    victory = true; 
  }
  
  while(victory == true){
    tone(kPinSpeaker, NOTE_C4);
    delay(1000);
    tone(kPinSpeaker, NOTE_G4);
    delay(1000);
    tone(kPinSpeaker, NOTE_F4);
    delay(250);
    tone(kPinSpeaker, NOTE_E4);
    delay(250);
    tone(kPinSpeaker, NOTE_D4);
    delay(250);
    tone(kPinSpeaker, NOTE_C5);
    delay(1000);
    tone(kPinSpeaker, NOTE_G4);
    delay(500);
    tone(kPinSpeaker, NOTE_F4);
    delay(250);
    tone(kPinSpeaker, NOTE_E4);
    delay(250);
    tone(kPinSpeaker, NOTE_D4);
    delay(250);
    tone(kPinSpeaker, NOTE_C5);
    delay(1000);
    tone(kPinSpeaker, NOTE_G4);
    delay(500);
    tone(kPinSpeaker, NOTE_F4);
    delay(250);
    tone(kPinSpeaker, NOTE_E4);
    delay(250);
    tone(kPinSpeaker, NOTE_F4);
    delay(250);
    tone(kPinSpeaker, NOTE_D4);
    delay(2000);
    noTone(kPinSpeaker);
    delay(250);
    counter++;
    if(counter == 5){
      delay(500);
      digitalWrite(led, HIGH);
      digitalWrite(led3, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      digitalWrite(led3, LOW);
      delay(500);
      digitalWrite(led2, HIGH);
      delay(500);
      digitalWrite(led2, LOW);
      level = 0; 
      lives = 3; 
      counter = 0;
      victory = false; 
      delay(500);
    }
  }
} //end loop
