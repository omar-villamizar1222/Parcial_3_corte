#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include "SensorDht11.h"
#include "SensorHumedad.h"
#include "Estacion_Meteorologica.h"

// pines

#define PIN_DHT11 2
#define PIN_HUMEDAD 33
#define PIN_BOTON 25

#define PIN_LED_SECO    32
#define PIN_LED_OPTIMO  35
#define PIN_LED_HUMEDO  34
// intervalos de refresco de lectura 
#define INTERVALO_MS 3000

/// lcd

LiquidCrystal_I2C lcd(0x27);

EstacionMeteorologica* estacion = nullptr;

// señales para el botón
volatile bool botonPresionado = false;
volatile unsigned long ultimoTiempoBoton = 0;

void IRAM_ATTR ISR_boton () {
  unsigned long tiempoActual = millis();
  if (tiempoActual - ultimoTiempoBoton > 200) { // debounce de 200ms
    botonPresionado = true;
    ultimoTiempoBoton = tiempoActual;
  }
}

void setup(){
    Serial.begin(115200);
    lcd.begin(16,2);

    pinMode(PIN_BOTON, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(PIN_BOTON),
                    ISR_boton, FALLING);
    
    estacion = new EstacionMeteorologica(&lcd);

    //crear sensores con new
    SensorDht11 * sDHT11 = new SensorDht11(PIN_DHT11);
    SensorHumedad* sHumedad = new SensorHumedad(PIN_HUMEDAD);

    estacion->agregarSensor(sDHT11);
    estacion->agregarSensor(sHumedad);
    estacion->setRefDHT11(sDHT11);
    estacion->setRefsensorHumedadSuelo(sHumedad);

    estacion->configurarLeds(PIN_LED_SECO, PIN_LED_OPTIMO, PIN_LED_HUMEDO);

    estacion->mostrarInicio();

    //mostrar pantalla inicial
    estacion->tomarLecturas();
    estacion->actualizarPantallaLCD();

    Serial.println("Sistema iniciado correctamente");
}

void loop(){
    if(botonPresionado){
        botonPresionado = false;
        estacion->SiguientePantalla();
        estacion->actualizarPantallaLCD();
        Serial.print("pantalla: ");
        Serial.println(estacion->pantallaActual);
    }
   //lecturas periodicas
   static unsigned long ultimaLectura =  0;
   unsigned long ahora = millis();

   if (ahora - ultimaLectura >= INTERVALO_MS){
    ultimaLectura = ahora; 
    estacion->tomarLecturas();
    estacion->imprimirValoresSerial();
    estacion->actualizarPantallaLCD();
   }
}