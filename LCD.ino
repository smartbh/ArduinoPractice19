#include  <LiquidCrystal.h>

LiquidCrystal   lcd(12, 11, 5, 4, 3, 2);
int   sw= 6;
char  str[]="Hello!";

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(sw, INPUT);

}
#define RIGHT 1 
#define LEFT  0 

int dir= LEFT;
int i=0;


void loop() {
 
  //  to left
  int loc= 31-i;

  if(digitalRead(sw)==1)
  {
    delay(50);
    if(dir == LEFT) {
      dir = RIGHT;
    }
    else {
      dir = LEFT;
    }
  }
  
  lcd.clear();
  lcd.setCursor(loc%16, loc/16);
  lcd.print(&str[0]);
  
  if(loc <16 && loc > 16-strlen(str)){
    lcd.setCursor(0, 1);
    lcd.print(&str[16-loc]);
  }
  if(loc > 32-strlen(str) && loc < 32){
    lcd.setCursor(0, 0);
    lcd.print(&str[32-loc]);
  }

  if(dir == LEFT)
    i= ++i%32;
  else
    i = (--i+32)%32;

  delay(200);
  
}
