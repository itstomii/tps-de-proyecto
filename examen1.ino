#define luzamb A1 
#define ledr 2 
#define ledb 3 
#define ledg 4 
#define alarma 7 
#define sensorMovimiento 6 
#define boton 5

int valorLuz;
int porcentajeLuz;
bool movimientoDetectado = false;

void setup() {
  pinMode(ledr, OUTPUT);
  pinMode(ledb, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(alarma, OUTPUT);
  pinMode(luzamb, INPUT);
  pinMode(sensorMovimiento, INPUT);
  pinMode(boton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  valorLuz = analogRead(luzamb);
  porcentajeLuz = map(valorLuz , 1 , 310 , 0 , 100);//x
  
  Serial.print(valorLuz);
  Serial.print("-");
  Serial.println(porcentajeLuz);
  
  if (porcentajeLuz < 40) {
    digitalWrite(ledr, HIGH);
    digitalWrite(ledg, HIGH);
    digitalWrite(ledb, LOW);
  } else if (porcentajeLuz >= 40 && porcentajeLuz <= 60) {
    analogWrite(ledr, 128);
    analogWrite(ledb, 128);// Luz magenta (50%)
    analogWrite(ledg, 0);
  } else if(porcentajeLuz > 60) {  //  >60
    digitalWrite(ledr, HIGH); // Luz roja
    digitalWrite(ledg, LOW);
    digitalWrite(ledb, LOW);
    sonarAlarma(); 
  }

  movimientoDetectado = digitalRead(sensorMovimiento);
  if (movimientoDetectado && porcentajeLuz < 60 && digitalRead(boton) == LOW) {
    sonarAlarma(); 
  }
 
}

void sonarAlarma() {
  for (int i = 0; i < 5; i++) { 
    digitalWrite(alarma, HIGH);
    delay(50);
    digitalWrite(alarma, LOW);
    delay(50);
  }
}