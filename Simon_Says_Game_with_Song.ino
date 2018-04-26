//Robert Clark
//Intro to Engineering Analysis Final Project
//Simon Says Code

int button = 13;
int button2 = 12;
int button3 = 11;
//these variables hold the numeric values of the digital input ports the push buttons are connected to on the Arduino
//circuit board.

int led = 10;
int led2 = 9;
int led3 = 8;
//these variables hold the numeric values of the digital input ports the LEDs are connected to on the Arduino circuit
//board.

int buttonstate = 0;
int buttonstate2 = 0;
int buttonstate3 = 0;
//these variables hold the state of the push buttons. Zero indicates that the push button is not pressed where "HIGH"
//denotes the push button is pressed.

int buzzer = 7;
//this variable holds the numeric value of the digital input port the buzzer is connected to on the Arduino.

int time = 1000;
//this variable is responsible for storing the time in which the LEDs are blinked for each sequence. As the game 
//progresses this variable is decremented which decreases the amount of time the user has to remember the sequence, thus
//making the game harder as you go. 

long r;
//this variable stores the random number generated to turn one random LED to create a sequence.

int level = 1;
//this variable stores the level in which the user is on in the game. The maximum value of this level is 20, before it
//is reset to 0. Therefore, there are 20 levels in the game.

int amount = 1;
//this variable stores the number of LEDs turned on for every sequence. This value is incremented by one for every
//level, which increases the difficulty of the game by requiring the user to remember longer sequences as the game
//progresses.

int lives = 3;
//this variable stores the number of lives the user has. If the user inputs the wrong sequence the value of lives is 
//decremented by one. If the user fails to input the correct sequence three times, the game will display a unique light 
//pattern indicating that the user has no more lives and then the game will reset to level 1.

unsigned char pattern[20]; 
//here I created a character array that stores 20 values. This array is responsible for storing the random numbers that 
//correspond with the sequences of the game.

int patternindex = 0;
//this int variable is responsible for storing the value of the index for the array.

boolean failure = false;
//this boolean variable is responsible for indicating to the program that the user inputted the incorrect sequence. 

boolean victory = false; 
//this boolean variable is responsible for indicating to the program that the user won all 20 levels of the game.

int counter = 0;
//this int variable is responsible for counting the number of times the victory song is played.

const int kPinSpeaker = 7;
//this variable holds the numeric value of the digital input port the buzzer is connected to on the Arduino. This 
//variable is used in the song part of the code.

#define NOTE_C4 262
#define NOTE_D4 294 
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523
//these constants are the value of the notes used for the victory song. When arranged in a certain manner, they make 
//the Star Wars theme song.
  
void setup(){
  
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
//in these lines I set all of the LEDs as outputs for the circuit.
  
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
//in these lines I set all of the push buttons as inputs for the circuit.
  
  pinMode(buzzer, OUTPUT);
  pinMode(kPinSpeaker, OUTPUT);
//in these lines I set the buzzer as an output for the circuit.
  
  randomSeed(analogRead(0));
//this line creates a source for the random number to be generated.
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
//this part of the program is responsible for lighting up a sequence of LEDs that indicates to the user that the game is 
//starting. This light sequence is also the same light sequence that indicates to the user that the entered the correct
//sequence and that the next level is starting.
  
  while(level < 21){
//this while loop is responsible for keeping the game 20 levels. This loop will only allow the game to go to level 20 
//and then will end the game and reset to level 1. 
    
    for(amount = 0; amount < level; amount++){
//this for loop is responsible for controlling the amount of LEDs turned on per round. The amount of LEDs that turn on 
//per round corresponds with the level the user is on.
      
      if(amount == (level - 1)){
        r = random(1,4);
        pattern[amount] = r;   
      }
      else{
        r = pattern[amount];
      }
//this if-else statement is responsible for generating a random number between one and three and storing the number in
//the array if the user advances to the next level. If the user gets the sequence wrong and remains on the same level,
//the same sequence is repeated to the user with the exception of the last LED in the sequence which is re-generated to
//create a different sequence.
      
      if(r == 1){
        digitalWrite(led, HIGH);
        digitalWrite(buzzer, HIGH);
        tone(buzzer, 1000);
        delay(time);
        digitalWrite(led, LOW);
        noTone(buzzer);     
        delay(time);    
      }
//this if statement is resonsible for turning on the red LED and playing a 1000 Hertz sound for a second if the random 
//number is a one. After the one second the program then shuts off the buzzer and LED.
      
      if(r == 2){
        digitalWrite(led2, HIGH);
        digitalWrite(buzzer, HIGH);
        tone(buzzer, 2000);
        delay(time);
        digitalWrite(led2, LOW);
        noTone(buzzer);     
        delay(time); 
      }
//this if statement is responsible for turning on the blue LED and playing a 2000 Hertz sound for a second if the random 
//number is a one. After the one second the program then shuts off the buzzer and LED.
      
      if(r == 3){
        digitalWrite(led3, HIGH);
        digitalWrite(buzzer, HIGH);
        tone(buzzer, 3000);
        delay(time);
        digitalWrite(led3, LOW);
        noTone(buzzer);     
        delay(time);   
      } 
//this if statement is responsible for turning on the green LED and playing a 3000 Hertz sound for a second if the
//random number is a one. After the one second the program then shuts off the buzzer and LED.  
    }//end for (amount)
    break;
//this break prevents the program from displaying 20 sequence elements in one round.
    
  }//end while
  
  for(int i = 0; i < level; i++){
//this for loop is responsible for receiving user input.
    
    do{
      buttonstate = digitalRead(button);
      buttonstate2 = digitalRead(button2);
      buttonstate3 = digitalRead(button3);
    } while(buttonstate == LOW && buttonstate2 == LOW && buttonstate3 == LOW);
//this do while sets all of the button state variables to the input on the physical push button. If one of the push
//buttons is pressed, the value of that button state variable will change from "LOW" to "HIGH".
    
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
//the outer if statement is responsible for turning on the red LED and playing a 1000 Hertz sound for one second if the
//push button below the red LED is pushed. After the one second the program shuts off the buzzer and the LED. If the
//button is not pressed then the LED and buzzer will remain off. In addition, the inner if statement is responsible for
//breaking the sequence is the user inputs the wrong sequence. Once the program detects that the user inputted the
//incorrect sequence, the if statement breaks and executes the failure statements. 
    
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
//the outer if statement is responsible for turning on the blue LED and playing a 2000 Hertz sound for one second if
//the push button below the blue LED is pushed. After the one second the program shuts off the buzzer and the LED. If
//the button is not pressed then the LED and buzzer will remain off. In addition, the inner if statement is responsible 
//for breaking the sequence is the user inputs the wrong sequence. Once the program detects that the user inputted the 
//incorrect sequence, the if statement breaks and executes the failure statements.     
    
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
//the outer if statement is responsible for turning on the green LED and playing a 3000 Hertz sound for one second if
//the push button below the green LED is pushed. After the one second the program shuts off the buzzer and the LED. If 
//the button is not pressed then the LED and buzzer will remain off. In addition, the inner if statement is responsible 
//for breaking the sequence is the user inputs the wrong sequence. Once the program detects that the user inputted the 
//incorrect sequence, the if statement breaks and executes the failure statements.    
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
//this if-else statement tests to see if the user inputted the correct sequence. If the user inputted the correct
//sequence then the value of failure remains false and the program increments the value of level, reduces the amount of
//time the user has to remember the sequence and also displays a light pattern indicating to the user that they entered 
//the correct sequence and the next level is going to begin. If the user enters the sequence incorrectly, then the 
//value of failure becomes true and the program displays a light pattern indicating to the user that they inputted the 
//sequence incorrectly. The program also decrements the value of lives by one. 
  
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
    lives = 3;
    delay(500); 
  } //end lives = 0 if
//this if statement is responsible for testing if the value of lives is equal to zero. If the value of lives is equal
//to zero then the game displays a distinct light pattern that indicates to the user that the game is over because they
//ran out of lives. The program also resets the value of lives to three lives and also resets the value of level to 
//one, thus restarting the game. 
  
  if(level == 22){
    victory = true; 
  }
//this if statement tests to see if the user has reached the end of the game. If the user completes the game the Star
//Wars theme song.
  
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
      level = 1; 
      lives = 3; 
      counter = 0;
      victory = false; 
      delay(500);
    }
  }
//this part of the code is responsible for the victory song of the code. When the program detects that the user
//completed 20 rounds the program will play the Star War theme song five times. After five times, the program resets
//the game by reseting the value of level to zero and lives to three. 
} //end loop
