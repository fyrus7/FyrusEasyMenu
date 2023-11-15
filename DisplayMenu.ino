/*
 * ||  Display Menu by Fyrus  ||
 * 
 * a simple menu navigation for 1 button.
 * with ButtonGestures library
 * 
 * Click / Double Click / Hold
 * 
 * click once to scroll down.
 * click twice to enter.
 * click and hold to go back.
 * 
 */


#include <Adafruit_SSD1306.h>
#include <ButtonGestures.h>


Adafruit_SSD1306 display(128, 64, &Wire, -1);


#define   BUTTON_PIN   2
ButtonGestures  Fyrus(BUTTON_PIN, LOW, INPUT_PULLUP);

boolean OK   = false;
boolean DOWN = false;
boolean BACK = false;

int PAGE  = 0;
int Menu = 1;


void setup() {

    Fyrus.set_callback(SHORT1, F_Down); // single click
    Fyrus.set_callback(SHORT2, F_Ok);   // double click
    Fyrus.set_callback( LONG1, F_Back); // click then hold

    display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
    display.clearDisplay();

}

void loop() {

  Fyrus.check_button();
  
  TopMenu(); // show Top Menu in loop.

  // when click is pressed
  if (DOWN) {
    DOWN = false;
    if (++Menu > 5){ // max main menu item
      Menu = 1;      // back to 1 after end scroll
    }
  }

  // when double click is pressed
  if (OK) {
    OK = false;
    if (PAGE == 0 && Menu == 0) {
      PAGE = 0;
    } else if (PAGE == 0 && Menu == 1) {
      PAGE = 1;
    } else if (PAGE == 0 && Menu == 2) {
      PAGE = 2;
    } else if (PAGE == 0 && Menu == 3) {
      PAGE = 3;
    } else if (PAGE == 0 && Menu == 4) {
      PAGE = 4;
    } else if (PAGE == 0 && Menu == 5) {
      PAGE = 5;
    }
  }

  // when hold is held while in sub menu, this bring back to top menu.
  if (BACK) {
    BACK = false;
    if (PAGE == 1 || PAGE == 2 || PAGE == 3 || PAGE == 4 || PAGE == 5) {
      PAGE = 0;
    }
  }
}


// Display for main menu.
void TopMenu() {
  if (PAGE == 0) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(28, 0); display.print("DISPLAY MENU");

    if (Menu == 1) {
       display.setCursor(5, 16); display.print("> main menu 1");
    } else {
       display.setCursor(5, 16); display.print("  main menu 1");
    }

    if (Menu == 2) {
       display.setCursor(5, 26); display.print("> main menu 2");
    } else {
       display.setCursor(5, 26); display.print("  main menu 2");
    }

    if (Menu == 3) {
      display.setCursor(5, 36); display.print("> main menu 3");
    } else {
      display.setCursor(5, 36); display.print("  main menu 3");
    }

    if (Menu == 4) {
      display.setCursor(5, 46); display.print("> main menu 4");
    } else {
      display.setCursor(5, 46); display.print("  main menu 4");
    }

     if (Menu == 5) {
      display.setCursor(5, 56); display.print("> main menu 5");
    } else {
      display.setCursor(5, 56); display.print("  main menu 5");
    }


    // Sub menu for all your code needs.
    // from here you can make 5 saperate loops with void functions.
  } else if (PAGE == 1) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(30, 25); display.print("SUB 1");
  } else if (PAGE == 2) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(30, 25); display.print("SUB 2");
  } else if (PAGE == 3) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(30, 25); display.print("SUB 3");
  } else if (PAGE == 4) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(30, 25); display.print("SUB 4");
  } else if (PAGE == 5) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(30, 25); display.print("SUB 5");
  }

  display.display();
}

void Color() { display.setTextColor(WHITE); }

// button call functions.
void F_Down(){ DOWN = true; }
void F_Ok()  { OK   = true; }
void F_Back(){ BACK = true; }

