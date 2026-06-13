#ifndef SensorHumedad_H
#define SensorHumedad_H

#include "Sensores.h"

/*
 * @brief Clase que representa un sensor de humedad, hereda de la clase Sensor y implementa los métodos para leer e imprimir el valor del sensor.
 */
class SensorHumedad : public Sensor {
    
    private:
        int pin; // Pin al que está conectado el sensor de humedad
        float valor; // Valor leído del sensor de humedad
        std::string nombre; // Nombre del sensor 
    
    public:
        /* @brief Constructor de la clase SensorHumedad, inicializa el pin y el nombre del sensor */
        // @param Pin al que está conectado el sensor de humedad
        // @param Nombre del sensor de humedad
        // @param porcentaje de humedad leído por el sensor
        SensorHumedad(int pin, float valor, std::string nombre);
        /* @brief Método para leer el valor del sensor de humedad, devuelve un porcentaje de humedad */
        // @return Porcentaje de humedad leído por el sensor
        float leerValor() override;
        /* @brief Método para imprimir el valor del sensor de humedad en la LCD 16x2 */ 
        void imprimirValor() override;
        
        //getters 
        int getPin() const; // Método para obtener el pin del sensor de humedad
        float getValor() const; // Método para obtener el valor del sensor de humedad
        std::string getNombre() const; // Método para obtener el nombre del sensor de humedad
};

#endif