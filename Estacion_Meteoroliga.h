#ifndef ESTACION_METEOROLOGICA_H
#define ESTACION_METEOROLOGICA_H

#include "SensorDht11.h"
#include "SensorHumedad.h"
#include "Sensores.h"
#include <LiquidCrystal.h>

class EstacionMeteorologica {
    private:
        static const int MAX_SENSORES = 10; // número máximo de sensores que la estación meteorológica puede manejar
        static const int TOTAL_PANTALLAS = 3; // número de distintas pantallas que se pueden mostrar en la LCD 16x2
        
        Sensor* _sensores[MAX_SENSORES]; // arreglo de punteros a objetos Sensor para almacenar
        int _numSensores; // número actual de sensores registrados en la estación meteorológica
        LiquidCrystal* _lcd; // puntero al objeto LiquidCrystal para manejar la pantalla LCD

        SensorDht11* _sensorDht11; // puntero al objeto SensorDht11 para manejar el sensor de temperatura y humedad Dht11
        SensorHumedad* _sensorHumedad; // puntero al objeto SensorH
        
        void mostrarPantallaHumSuelo(); // método privado para actualizar la pantalla LCD con los valores de los sensores registrados
        void mostrarPantallaHumAire(); // método privado para mostrar la pantalla de humedad del aire en la LCD
        void mostrarPantallaTempAire(); // método privado para mostrar la pantalla de temperatura del
    
public:
     
        volatile int pantallaActual; // variable para almacenar la pantalla actual que se muestra en la LCD, marcada como volatile para indicar que puede ser modificada por interrupciones u otros procesos concurrentes

        EstacionMeteorologica(LiquidCrystal* lcd); // constructor para inicializar la estación meteorológica
        ~EstacionMeteorologica(); // destructor para liberar recursos de la estación meteorológica

        bool agregarSensor(Sensor* sensor); // método para agregar un nuevo sensor a la estación meteorológica

        void serRefDHT11(SensorDht11* sensorDht11); // método para establecer el puntero al sensor Dht11 en la estación meteorológica
        void serRefsensorHumedadSuelo(SensorHumedad* sensorHumedad); // método para establecer el puntero al sensor de humedad en la estación meteorológica

        void tomarLecturas(); // método para tomar lecturas de todos los sensores registrados en la estación meteorológica y actualizar la pantalla LCD
        void imprimirValoresSerial(); // método para imprimir los valores de todos los sensores registrados en la estación meteorológica en el monitor serial
        void actualizarPantallaLCD(); // método para actualizar la pantalla LCD con los valores de los sensores registrados en la estación meteorológica
        void SiguientePantalla(); // método para mostrar las diferentes pantallas en la LCD
        void PantallaAnterior(); // método para mostrar las diferentes pantallas en la LCD
};
#endif