#define red A0
#define green A1
#define blue A2

void setup()
{
  int pines[]={red , green , blue};
  int senal[]={ 1  ,   1   ,   1 };
    
    
    
}

void loop()
{
  //se decalara variable, condicion, para modificar el valor 
  for ( int r = 0 ; r <= 255 ; r++)
  {
    for ( int g = 0 ; g <= 255 ; g++)
    {
      for ( int b = 0 ; b <= 255 ; b++)
      {
        analogWrite(red,r);
        analogWrite(green,g);
        analogWrite(blue,b);
        delay(2);
        
      }
    }
  }
}