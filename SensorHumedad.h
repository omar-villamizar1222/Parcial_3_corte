#ifndef SensorHumedad_H
#define SensorHumedad_H

#include "Sensores.h"

/*
 * @brief Clase que representa un sensor de humedad, hereda de la clase Sensor y implementa los métodos para leer e imprimir el valor del sensor.
 */
class SensorHumedad : public Sensor {
    
    private:
        float _humedad; // variable para almacenar el valor de humedad leído por el sensor
    
    public:
        /* @brief Constructor de la clase SensorHumedad, inicializa el pin y el nombre del sensor */
        // @param Pin al que está conectado el sensor de humedad
        // @param porcentaje de humedad leído por el sensor
        SensorHumedad(uint8_t pin);
        ~SensorHumedad(); // destructor para liberar recursos del sensor de humedad

        void leerValor() override; // método para leer el valor del sensor de humedad y actualizar la variable de humedad

        float getHumedad() // método para obtener el valor de humedad leído por el sensor
        string clasificarHumedad() // método para clasificar el nivel de humedad (bajo, medio, alto) según el valor leído por el sensor
        void imprimirValor() const override; // método para imprimir el valor de humedad leído por el sensor
    };
#endif