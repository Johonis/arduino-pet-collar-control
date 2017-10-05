#include "rffunc.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Ticker.h>


const char *ssid = "SSID";
const char *password = "PASSWORD";
const int buttonPin = D3;
bool block = false;

ESP8266WebServer server ( 80 );
IPAddress myip(192, 168, 2, 2);
Ticker flipper;

void vibrate()
{
  server.send ( 200, "text/plain", "OK." );
}

void shock()
{
  server.send ( 200, "text/plain", "OK." );
}

void beep()
{
  server.send ( 200, "text/plain", "OK." );
}


void buttonPress()
{
  if (block) return;
  //0 = shock, 1 = vibration, 2 = sound
  int strength = 30;
  int type = 0;
  execute(strength, type);
  execute(strength, type);
  execute(strength, type);
  execute(strength, type);
  // test();
  block = true;
  flipper.once(1, blockState, false); //after 15sec unblock
}

void blockState(bool val)
{
  block = val;
}

void setup() {
  pinMode(outPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  attachInterrupt(buttonPin, buttonPress, FALLING);
  Serial.begin(9600);
  WiFi.config(myip, IPAddress(192, 168, 178, 1), IPAddress(255, 255, 255, 0));

  WiFi.begin ( ssid, password );
  while ( WiFi.status() != WL_CONNECTED ) {
    delay (500);
  }
  MDNS.begin ( "ShockMan" );

  server.on ( "/vibrate", vibrate );
  server.on ( "/shock", shock );
  server.on ( "/beep", beep );
  server.begin();

  //vib50();
}

void loop() {
  server.handleClient();
}

