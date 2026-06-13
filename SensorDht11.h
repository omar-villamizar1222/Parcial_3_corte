#ifndef SensorDht11_H
#define SensorDht11_H

#include "Sensores.h"

class SensorDht11 : public Sensor {
   
    float temperatura; // Variable para almacenar la temperatura leída por el sensor Dht11

    private:
        int pin; // Pin al que está conectado el sensor de humedad
        float valor; // Valor leído del sensor de humedad
        std::string nombre; // Nombre del sensor de humedad
    
    public:
        /* @brief Constructor para la clase SensorDht11, inicializa el pin, el valor y el nombre del sensor Dht11 */
        // @param Pin al que está conectado el sensor Dht11
        // @param Nombre del sensor Dht11
        // @param porcentaje de humedad leído por el sensor
        SensorDht11(int pin, float valor, std::string nombre, float temperatura);
        /* @brief Método para leer el valor del sensor Dht11, devuelve un porcentaje de humedad */
        // @return Porcentaje de humedad leído por el sensor
        float leerValor() override;
        /* @brief Método para imprimir el valor del sensor Dht11 en la LCD 16x2 */ 
        void imprimirValor() override;
        
        void setTemperatura(float temp); // Método para establecer la temperatura leída por el sensor Dht11
        //getters 
        int getPin() const; // Método para obtener el pin del sensor dht11
        float getValor() const; // Método para obtener la temperatura leída por el sensor Dht11
        std::string getNombre() const; // Método para obtener que mide el sensor Dht11
};