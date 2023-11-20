/*
 * ||  FYRUS EASY MENU  ||
 * 
 * a simple menu navigation for 1 button.
 * 
 * Click / Double Click / Hold
 * 
 * click once to scroll down.
 * click and hold to enter.
 * click twice to go back.
 * 
 */


#include <Adafruit_SSD1306.h>


Adafruit_SSD1306 display(128, 64, &Wire, -1);


#define Click 2 // pin is connected at D2

int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
bool buttonState = HIGH;
byte tapCounter;
int timediff;
bool flag1, flag2;
long double presstime, releasetime;

int PAGE  = 0;
int Menu = 1;


void setup() {

    pinMode(Click, INPUT_PULLUP);

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();

}

void loop() {

  TopMenu(); // show Main Menu in loop.

  int reading = digitalRead(Click);

  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
    }
  }
  if (buttonState == 0 && flag2 == 0)
  {
    presstime = millis();
    flag1 = 0;
    flag2 = 1;
    tapCounter++;
  }
  if (buttonState == 1 && flag1 == 0)
  {
    releasetime = millis();
    flag1 = 1;
    flag2 = 0;

    timediff = releasetime - presstime;
  }
  if ((millis() - presstime) > 400 && buttonState == 1)
  {
    if (tapCounter == 1) // Hold
    {
      if (timediff >= 400)
      {
      SELECT();
      }
      else // Single Click
      {
      SCROLL();
      }
      }
      else if (tapCounter == 2) // Double Click
      {
      RETURN();
      }
    tapCounter = 0;
  }
  lastButtonState = reading;

}


// Display for main menu.
void TopMenu() {
  if (PAGE == 0) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(20, 0); display.print("FYRUS EASY MENU");

    if (Menu == 1) {
       display.setCursor( 5, 20); display.print("> main 1");
       display.setCursor( 5, 30); display.print("  main 2");
       display.setCursor(70, 20); display.print("  main 3");
       display.setCursor(70, 30); display.print("  main 4");
       display.setCursor(38, 56); display.print("  main 5");
    }

    if (Menu == 2) {
       display.setCursor( 5, 20); display.print("  main 1");
       display.setCursor( 5, 30); display.print("> main 2");
       display.setCursor(70, 20); display.print("  main 3");
       display.setCursor(70, 30); display.print("  main 4");
       display.setCursor(38, 56); display.print("  main 5");
    }

    if (Menu == 3) {
       display.setCursor( 5, 20); display.print("  main 1");
       display.setCursor( 5, 30); display.print("  main 2");
       display.setCursor(70, 20); display.print("> main 3");
       display.setCursor(70, 30); display.print("  main 4");
       display.setCursor(38, 56); display.print("  main 5");
    }

    if (Menu == 4) {
       display.setCursor( 5, 20); display.print("  main 1");
       display.setCursor( 5, 30); display.print("  main 2");
       display.setCursor(70, 20); display.print("  main 3");
       display.setCursor(70, 30); display.print("> main 4");
       display.setCursor(38, 56); display.print("  main 5");
    }

     if (Menu == 5) {
       display.setCursor( 5, 20); display.print("  main 1");
       display.setCursor( 5, 30); display.print("  main 2");
       display.setCursor(70, 20); display.print("  main 3");
       display.setCursor(70, 30); display.print("  main 4");
       display.setCursor(38, 56); display.print("> main 5");
    }


    // Sub menu for all your code needs.
    // from here you can make 5 saperate loops with void functions.
  } else if (PAGE == 1) {
    Clear(); display.setCursor(30, 25); display.print("SUB 1");
  } else if (PAGE == 2) {
    Clear(); display.setCursor(30, 25); display.print("SUB 2");
  } else if (PAGE == 3) {
    Clear(); display.setCursor(30, 25); display.print("SUB 3");
  } else if (PAGE == 4) {
    Clear(); display.setCursor(30, 25); display.print("SUB 4");
  } else if (PAGE == 5) {
    Clear(); display.setCursor(30, 25); display.print("SUB 5");
  }

  display.display();
}


void SELECT(){
    if (PAGE == 0 && Menu == 0) {
        PAGE = 0;
      } else if (PAGE == 0 && Menu == 1) {
        PAGE = 1; // go to sub 1
      } else if (PAGE == 0 && Menu == 2) {
        PAGE = 2; // go to sub 2
      } else if (PAGE == 0 && Menu == 3) {
        PAGE = 3; // go to sub 3
      } else if (PAGE == 0 && Menu == 4) {
        PAGE = 4; // go to sub 4
      } else if (PAGE == 0 && Menu == 5) {
        PAGE = 5; // go to sub 5
      }
}


void SCROLL(){
  if (++Menu > 5){ // 0 to max main menu item
        Menu = 1;  // back to 1 after end scroll
  }
}


void RETURN(){
  if (PAGE == 1 || PAGE == 2 || PAGE == 3 || PAGE == 4 || PAGE == 5) {
      PAGE = 0;
  }
}


void Clear(){
  display.clearDisplay();
  display.setTextSize(2);
}
