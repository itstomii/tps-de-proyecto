#include <LiquidCrystal.h>

#define D4  294
#define Fsharp4  370
#define G4  392
#define A4  440
#define B4  494
#define D5  587

#define buzzer 8

LiquidCrystal lcd(7, 6, 2, 3, 4, 5);

char musica[][4] = {"D4", "F#4", "G4", "A4", "F#4", "B4", "A4"};
int notas[] =       {D4,  Fsharp4, G4,  A4,  Fsharp4, B4,  A4};
float figuras[] =   {4,   4,       4,   4,   4,      4,   4};

String letra[] = {
  "Sos capaz",
  "de guiar",
  "mi energia",
  "sos el sol",
  "que llego",
  "pa' alumbrar"
};

void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
  float t = 1.20; 

  for (int i = 0; i < 6; i++) 
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(letra[i]); 

    if (i < 7) 
    {
      lcd.setCursor(0, 1);
      lcd.print(musica[i]); 

      tone(buzzer, notas[i]);
      float tempo = (1000 / figuras[i] * t);
      delay(tempo);
      noTone(buzzer);
    }
    delay(1000); 
  }
}

