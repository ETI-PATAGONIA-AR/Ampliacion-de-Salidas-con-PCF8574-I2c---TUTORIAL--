//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//Ejemplo: Expansor de salidas I2c con PCF8574 - prof.martintorres@educ.ar - ETI Patagonia
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
#include "Arduino.h"
#include "PCF8574.h"

int botonSeleccion_HW = 12;
int botonSeleccion_I2c = 13;
int mode_HW = 0; 
int mode_I2c = 0; 

PCF8574 pcf8574(0x20);// dirección de la configuración del dispositivo
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void setup()
  {
  DDRD = B11111100; // Implementamos 8 bits del puerto D
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
 
  pinMode(botonSeleccion_HW, INPUT);
  pinMode(botonSeleccion_I2c, INPUT);
  mode_HW = 0;
  mode_I2c = 0;
 
  pcf8574.begin();// inicializamos la comunicación entre el uc y el CI PCF8574

  pcf8574.pinMode(P0, OUTPUT);  //se declará el pin PO del CI PCF8574 como SALIDA
  pcf8574.pinMode(P1, OUTPUT);  //se declará el pin P1 del CI PCF8574 como SALIDA
  pcf8574.pinMode(P2, OUTPUT);  //se declará el pin P2 del CI PCF8574 como SALIDA
  pcf8574.pinMode(P3, OUTPUT);  //se declará el pin P3 del CI PCF8574 como SALIDA
  pcf8574.pinMode(P4, OUTPUT);  //se declará el pin P4 del CI PCF8574 como SALIDA
  pcf8574.pinMode(P5, OUTPUT);  //se declará el pin P5 del CI PCF8574 como SALIDA
  pcf8574.pinMode(P6, OUTPUT);  //se declará el pin P6 del CI PCF8574 como SALIDA
  pcf8574.pinMode(P7, OUTPUT);  //se declará el pin P7 del CI PCF8574 como SALIDA
}
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void loop()
 {
if (digitalRead(botonSeleccion_HW)== HIGH)
   {
    mode_HW = mode_HW + 1;
    delay (400);
   }
if (mode_HW == 0){PORTD = B00000000;}
if (mode_HW == 1){PORTD = B00000100;}
if (mode_HW == 2){PORTD = B00001000;}
if (mode_HW == 3){PORTD = B00010000;}
if (mode_HW == 4){PORTD = B00100000;}
if (mode_HW == 5){PORTD = B01000000;}
if (mode_HW == 6){PORTD = B10000000;}
if (mode_HW == 7){mode_HW=0;}
//////////////////////////////////////////////////////////////////////////////////
if (digitalRead(botonSeleccion_I2c)== HIGH)
   {
    mode_I2c = mode_I2c + 1;
    delay (400);
   }
if (mode_I2c == 0)
                 {
                  pcf8574.digitalWrite(P0, LOW); //PIN P0 EN BAJO
                  pcf8574.digitalWrite(P1, LOW); //PIN P1 EN BAJO
                  pcf8574.digitalWrite(P2, LOW); //PIN P2 EN BAJO
                  pcf8574.digitalWrite(P3, LOW); //PIN P3 EN BAJO
                  pcf8574.digitalWrite(P4, LOW); //PIN P4 EN BAJO
                  pcf8574.digitalWrite(P5, LOW); //PIN P5 EN BAJO
                  pcf8574.digitalWrite(P6, LOW); //PIN P6 EN BAJO
                  pcf8574.digitalWrite(P7, LOW); //PIN P7 EN BAJO
                 }
if (mode_I2c == 1){pcf8574.digitalWrite(P0, HIGH);}//PIN P0 EN ALTO
if (mode_I2c == 2){pcf8574.digitalWrite(P1, HIGH);}//PIN P1 EN ALTO
if (mode_I2c == 3){pcf8574.digitalWrite(P2, HIGH);}//PIN P2 EN ALTO
if (mode_I2c == 4){pcf8574.digitalWrite(P3, HIGH);}//PIN P3 EN ALTO
if (mode_I2c == 5){pcf8574.digitalWrite(P4, HIGH);}//PIN P4 EN ALTO
if (mode_I2c == 6){pcf8574.digitalWrite(P5, HIGH);}//PIN P5 EN ALTO
if (mode_I2c == 7){pcf8574.digitalWrite(P6, HIGH);}//PIN P6 EN ALTO
if (mode_I2c == 8){pcf8574.digitalWrite(P7, HIGH);}//PIN P7 EN ALTO
if (mode_I2c == 9){mode_I2c=0;}
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
}