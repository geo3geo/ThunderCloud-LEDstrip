//Thunder & Lightning
//using Arduino Nano and Led strip
//sound via DFRobotDFPlayerMini, mp3 files must be in /mp3 on SD card
//Geo Meadows
//24June2021

#include <FastLED.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

#define NUM_LEDS 120   //length of strip
#define ledstripPin 6  //LEDstrip driver
int lightningLen = 25; //length of lightning
int rxPin = 11;    // DFplayer RX to Arduino pin 11
int txPin = 10;    // DFplayer TX toArduinopin 10
int busyPin = 12;  // DFplayer BUSY connected to pin 12
int swPin = 8;     // hi-lo intensity/sound switch
#define ledstripPin 6

SoftwareSerial mySoftwareSerial(rxPin, txPin);
DFRobotDFPlayerMini myDFPlayer;

#define BRIGHTNESS 20
#define HIBRIGHTNESS 250
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(57600);
  mySoftwareSerial.begin(9600);
  //pinMode(ledPin, OUTPUT);
  pinMode(busyPin, INPUT);
  pinMode(swPin, INPUT_PULLUP);
  FastLED.addLeds<WS2812, ledstripPin, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness( BRIGHTNESS );
  clear();

  Serial.println(F("Initializing DFPlayer..."));
  //Use softwareSerial to communicate with mp3player
  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println(F("Unable to begin. Check connection and SD card, or reset the Arduino."));
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.setTimeOut(500);                   // Set serial communictaion time out 500ms
  myDFPlayer.volume(5);                         // Set volume value (0~30).
  myDFPlayer.EQ(DFPLAYER_EQ_BASS);              // Set EQ to BASS (normal/pop/rock/jazz/classic/bass)
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);  // Set device we use SD as default
  myDFPlayer.enableDAC();                       // Enable On-chip DAC
}

//////////////////////////////////////////
void loop() {
  if (digitalRead(swPin) == LOW){
    FastLED.setBrightness( HIBRIGHTNESS );  
    myDFPlayer.volume(30);    
  }
  else {
    FastLED.setBrightness( BRIGHTNESS );   
    myDFPlayer.volume(10
    );    
  }
  
  randomSeed(analogRead(0));
  int lightningLen = random(10, NUM_LEDS/3);
  int lightningStart = random(0,2*NUM_LEDS/3);
  int strikes = random(1, 8);
  
  Serial.print("LEDS = ");
  Serial.print(lightningLen);
  Serial.print(" @ ");
  Serial.print(lightningStart);
  Serial.print(" x ");
  Serial.println(strikes);
  
  strike(strikes, lightningLen, lightningStart);
  randomSeed(analogRead(0));
  int thunderDelay = random(1000, 3000);
  delay(thunderDelay);
  thunder(strikes);
}
//////////////////////////////////////////

void strike(int num, int len, int start) {
  for (int j = 0; j < num; j++) {
    for (int i = start; i < start+len; i++) {
      leds[i].setRGB(200, 200, 255);
    }
    FastLED.show();
    delay(50);
    clear();
  }
  int strikeDelay = random(100, 2000);
  delay(strikeDelay);
}

void thunder(int type) {
  if (digitalRead(busyPin) != LOW){
  myDFPlayer.playMp3Folder(type); //play file
 //myDFPlayer.next();
  Serial.print("thunder ");
  Serial.println(type);
  delay(500);
  }   
}

void clear() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].setRGB(0, 0, 0);
  }
  FastLED.show();
}
