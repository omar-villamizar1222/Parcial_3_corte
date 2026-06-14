#include <LiquidCrystal.h>

#include "include/SensorDht11.h"
#include "include/SensorHumedad.h"
#include "include/EstacionMeteorologica.h"


// pines
#define PIN_DHT11 2
#define PIN_HUMEDAD A0
#define PIN_BOTON 3

// intervalos de refresco de lectura 
#define INTERVALO_MS 3000

/// lcd

liquidCrystal lcd(d14,d27);

EstacionMeteorologica* estacion = nullptr;

// señales para el botón
volatile bool botonPresionado = false;
volatile unsigned long ultimoTiempoBoton = 0;

void ISR_boton() {
  unsigned long tiempoActual = millis();
  if (tiempoActual - ultimoTiempoBoton > 200) { // debounce de 200ms
    botonPresionado = true;
    ultimoTiempoBoton = tiempoActual;
  }
}

void setud(){
    Serial.begin(9600);
    lcd.begin(16,2);

    pinMode(PIN_BOTON, INPUT_PULLUP);

    attachInterrupt(digitalPintoInterrupt(PIN_BOTON),
                    ISR_boton, FALLING);
    
    estacion = new EstacionMeteorologica(&lcd);

    //crear sensores con new
    SensorDHT11 * sDHT11 = new SensorDHT11(PIN_DHT);
    SensorHumedad* sHumedad = new SensorDHT11(PIN_SUELO);

    estacion->agregarSensor(sDHT11);
    estacion->agregarSensor(sSuelo);
    estacion->setRefDHT11(sDHT11);
    estacion->setRefSuelo(sSuelo);
    
    estacio-> mostrarInicio;

    //mostrar pantalla inicial
    estacion->tomarLecturas();
    estacion->refrescarLCD();

    Serial.println("Sistema iniciado correctamente");
}

void loop(){
    if(botonPresionado){
        bontonPresionado = false;
        estacion->siguientePantalla();
        estacion->refrescarLCD();
        Serial.print("pantalla: ")
        Serial.println(estacion->pantallaActual);
    }
   //lecturas periodicas
   static unsigned long ultimaLectura =  0;
   unsigned long ahora = millis();

   if (ahora - ultimaLectura >= INTERVALO_MS){
    ultimaLectura = ahora; 
    estacion->tomarLecturas();
    estacion->mostrarEnSerial();
    estacion->refrescarLCD();
   }
}