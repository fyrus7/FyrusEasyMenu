/*
 * ||  FYRUS EASY MENU  ||
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

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
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


void Clear(){
  display.clearDisplay();
  display.setTextSize(2);
}


// button call functions.
void F_Down(){ DOWN = true; }
void F_Ok()  { OK   = true; }
void F_Back(){ BACK = true; }
