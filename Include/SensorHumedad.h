#ifndef SENSOR_HUMEDAD
#define SENSOR_HUMEDAD

/*
 * ============================================================
 *  SensorSuelo.h — Clase derivada de Sensor
 *  Lee humedad del suelo vía pin analógico (0–1023)
 *  y la convierte a porcentaje (0% = seco, 100% = húmedo)
 * ============================================================
 */
#include "Sensores.h"

class SensorHumedad : public Sensores {
    
    private:
        float _humedad; // variable para almacenar el valor de humedad leído por el sensor
    
    public:
        /* @brief Constructor de la clase SensorHumedad, inicializa el pin y el nombre del sensor */
        // @param Pin al que está conectado el sensor de humedad
        // @param porcentaje de humedad leído por el sensor
        SensorHumedad(uint8_t pin);
        ~SensorHumedad(); // destructor para liberar recursos del sensor de humedad

        void leerValor() override; // método para leer el valor del sensor de humedad y actualizar la variable de humedad

        float getHumedad() const; // método para obtener el valor de humedad leído por el sensor
        string clasificarHumedad() const; // método para clasificar el nivel de humedad (bajo, medio, alto) según el valor leído por el sensor
        
        void imprimirValor() const override; // método para imprimir el valor de humedad leído por el sensor
    };
#endif //SensorHumedad

