/*
 *  Licence under: GNU General Public License v3.0
 *
 *
 * ||  Display Menu by Fyrus  ||
 * 
 * a simple menu navigation for 1 button.
 * with ButtonGestures library
 * 
 * Click / Double Click / Hold
 * 
 * click once to scroll down.
 * click twice to enter the sub menu.
 * click and hold to go back to main menu.
 * 
 */


#include <SPI.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <ButtonGestures.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


// Declaration for SSD1306 display connected using software SPI:
#define OLED_CLK       8
#define OLED_MOSI      9
#define OLED_RESET     10
#define OLED_DC        11
#define OLED_CS        12
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);


// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
//#define OLED_RESET     4
//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define   BUTTON_PIN   2
ButtonGestures  button(BUTTON_PIN, LOW, INPUT_PULLUP);


boolean OK   = false;
boolean DOWN = false;
boolean BACK = false;

int PAGE  = 0;
int mainMenu = 1;


void setup() {

    button.set_callback(SHORT1, cb_down); // normal single click and release
    button.set_callback(SHORT2, cb_ok);   // double click and release
    button.set_callback( LONG1, cb_back); // normal single click and hold

    display.begin(SSD1306_SWITCHCAPVCC, 0x3D);

    display.clearDisplay();

}

void loop() {

  button.check_button();
  
  TopMenu();


  // when click is pressed
  if (DOWN) {
    DOWN = false;
    if (++mainMenu > 5){ // max main menu item
      mainMenu = 1;      // back to 1 after end scroll
    }
  }

  // when double click is pressed
  if (OK) {
    OK = false;
    if (PAGE == 0 && mainMenu == 0) {
      PAGE = 0;
    } else if (PAGE == 0 && mainMenu == 1) {
      PAGE = 1;
    } else if (PAGE == 0 && mainMenu == 2) {
      PAGE = 2;
    } else if (PAGE == 0 && mainMenu == 3) {
      PAGE = 3;
    } else if (PAGE == 0 && mainMenu == 4) {
      PAGE = 4;
    } else if (PAGE == 0 && mainMenu == 5) {
      PAGE = 5;
    }
  }

  // when hold is held
  if (BACK) {
    BACK = false;
    if (PAGE == 1 || PAGE == 2 || PAGE == 3 || PAGE == 4 || PAGE == 5) {
      PAGE = 0;
    }
  }
}



// Display for main menu
void TopMenu() {
  if (PAGE == 0) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(28, 0);
    display.print("DISPLAY MENU");

    if (mainMenu == 1) {
      display.setCursor(5, 16);
      display.setTextColor(WHITE);
      display.print("> main menu 1");
    } else {
      display.setCursor(5, 16);
      display.setTextColor(WHITE);
      display.print("  main menu 1");
    }

    if (mainMenu == 2) {
      display.setCursor(5, 26);
      display.setTextColor(WHITE);
      display.print("> main menu 2");
    } else {
      display.setCursor(5, 26);
      display.setTextColor(WHITE);
      display.print("  main menu 2");
    }

    if (mainMenu == 3) {
      display.setCursor(5, 36);
      display.setTextColor(WHITE);
      display.print("> main menu 3");
    } else {
      display.setCursor(5, 36);
      display.setTextColor(WHITE);
      display.print("  main menu 3");
    }

    if (mainMenu == 4) {
      display.setCursor(5, 46);
      display.setTextColor(WHITE);
      display.print("> main menu 4");
    } else {
      display.setCursor(5, 46);
      display.setTextColor(WHITE);
      display.print("  main menu 4");
    }

     if (mainMenu == 5) {
      display.setCursor(5, 56);
      display.setTextColor(WHITE);
      display.print("> main menu 5");
    } else {
      display.setCursor(5, 56);
      display.setTextColor(WHITE);
      display.print("  main menu 5");
    }


    // Display for sub menu
  } else if (PAGE == 1) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(30, 25);
    display.print("SUB 1");
  } else if (PAGE == 2) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(30, 25);
    display.print("SUB 2");
  } else if (PAGE == 3) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(30, 25);
    display.print("SUB 3");
  } else if (PAGE == 4) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(30, 25);
    display.print("SUB 4");
  } else if (PAGE == 5) {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(30, 25);
    display.print("SUB 5");
  }

  display.display();
}


void cb_down(){
  DOWN = true;
}
void cb_ok(){
  OK = true;
}
void cb_back(){
  BACK = true;
}
