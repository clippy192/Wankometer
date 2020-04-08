#include <LiquidCrystal_I2C.h>

char answer;
int quesAns;

int defDelay = 2000;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.noBacklight();
  Serial.begin(9600);
  delay(5000);
  lcd.init();
  lcd.backlight();
  Serial.println("<Arduino is ready>");
}

void loop() {
  intro();
}

void intro() {

  lcd.clear();
  lcd.print("This program");
  lcd.setCursor(0, 1);
  lcd.print("calculates with");
  delay(defDelay);
  lcd.clear();
  lcd.print("100% accuracy,");
  lcd.setCursor(0, 1);
  lcd.print("how many times");
  delay(defDelay);
  lcd.clear();
  lcd.print("Palooka wanks");
  lcd.setCursor(0, 1);
  lcd.print("in a given day");
  delay(2000);
  answer = 10;
  press1();
}

void press1() {
  lcd.clear();
        lcd.print("Press 1 to");
    lcd.setCursor(0, 1);
    lcd.print("continue");
  while (answer == 10) {
    delay(100);
    if (Serial.available() > 0) {
      answer = Serial.read();
      Serial.print(answer, DEC);
    }
    if (answer == 49) {
      lcd.clear();
      lcd.print("cool, you did it");
      delay(defDelay);
      lcd.clear();
      lcd.print("Remember, press");
      lcd.setCursor(0, 1);
      lcd.print("1 for yes and");
      delay(defDelay);
      lcd.clear();
      lcd.print("2 for no");
      delay(5000);
      ques1();
    }
    else if ((answer != 10) && (answer != 49)) {
      lcd.clear();
      lcd.print("no, try again.");
      lcd.setCursor(0, 1);
      delay(100);
      answer = 10;
    }
  }
}

void ques1() {
  answer = 10;

  lcd.clear();
  lcd.print("Question 1:");
  delay(defDelay);
  lcd.clear();
  lcd.print("Was Half-Life 3");
  lcd.setCursor(0, 1);
  lcd.print("announced?");
  while (answer == 10) {
    delay(100);
    if (Serial.available() > 0) {
      answer = Serial.read();
      Serial.print(answer, DEC);
    }
    if (answer == 49) {
      lcd.clear();
      lcd.print("no it wasn't");
      delay(5000);
      ques1();
    }
    else if (answer == 50) {
      lcd.clear();
      lcd.print("correct!");
      delay(5000);
      ques1();
    }
  }
}
