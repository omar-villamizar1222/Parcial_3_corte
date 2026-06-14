#ifndef SENSORES_H
#define SENSORES_H  


/*@brief clase base abstracta para los sensores, con un metodo virtual puro para obtener la lectura del sensor*/
#include<Arduino.h>

class Sensores {

    protected:
        bool _activo; // estado del sensor (activo/inactivo)
        String _nombre; // nombre del sensor
        uint8_t _pin; // pin al que esta conectado el sensor


/* @brief Constructor de la clase Sensor. 
 * @param pin: Pin al que está conectado el sensor.
 * @param nombre: Nombre del sensor.
 */

 public:
    
    Sensores(const String& nombre, uint8_t pin); // constructor para inicializar el nombre y el pin del sensor
           
    virtual ~Sensores(); // destructor virtual por defecto

    virtual float leerValor() = 0; // metodo virtual puro para leer el valor del sensor
    
    bool isActivo() const; // metodo para obtener el estado del sensor
    String getNombre() const; // metodo para obtener el nombre del sensor
    uint8_t getPin()const;// metodo para obtener el pin 
    
    void setActivo(bool estado); // metodo para establecer el estado del sensor

    virtual void imprimirValor() const; // metodo virtual para imprimir el valor del sensor (sob

};
#endif // SENSORES
