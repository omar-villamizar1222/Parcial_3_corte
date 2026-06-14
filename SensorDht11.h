#ifndef SENSORDHT11_H
#define SENSORDHT11_H


#include "Sensores.h"
#include <DHT.h>

class SensorDht11 : public Sensores{

    private:
        DHT* _dht; // puntero al objeto DHT para manejar el sensor Dht11
        float _temperatura; // variable para almacenar la temperatura leída por el sensor Dht11
        float _humedad; // variable para almacenar la humedad leída por el sensor Dht11   
    public:
        /* @brief Constructor para la clase SensorDht11, inicializa el pin, el valor y el nombre del sensor Dht11 */
        // @param Pin al que está conectado el sensor Dht11
        // @param Nombre del sensor Dht11
        // @param porcentaje de humedad leído por el sensor
        SensorDht11(uint8_t pin);
        
        ~SensorDht11(); // destructor para liberar recursos del objeto DHT

        void leerValor() override; // método para leer el valor del sensor Dht11 y actualizar las variables de temperatura y humedad

        //getters para obtener los valores de temperatura y humedad leídos por el sensor Dht11
        float getTemperatura() const; // método para obtener la temperatura leída por el sensor Dht11
        float getHumedad() const; // método para obtener la humedad leída por el sensor Dht11

        void imprimirValor() const override; // método para imprimir los valores de temperatura y humedad leídos por el sensor Dht11

};
#endif // SensorDht11_H