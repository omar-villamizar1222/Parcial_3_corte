#ifndef SENSORES
#define SENSORES    

#include <String.h>
/*@brief clase base abstracta para los sensores, con un metodo virtual puro para obtener la lectura del sensor*/
class Sensor {
    public:
        virtual float leer() = 0; // metodo virtual puro para obtener la lectura del sensor
    protected:
        int pin; // pin al que esta conectado el sensor
        int valor; // valor leido del sensor
        std::string nombre; // nombre del sensor

/* @brief Constructor de la clase Sensor. 
/* @param valor: Valor leído por el sensor.
 * @param pin: Pin al que está conectado el sensor.
 * @param nombre: Nombre del sensor.
 */

 public:
    Sensor(int valor, int pin, std::string nombre);

    virtual ~Sensor() = default; // destructor virtual por defecto

    virtual void leerValor() = 0; // metodo virtual puro para leer el valor del sensor

    virtual void imprimirValor() = 0; // metodo virtual puro para imprimir el valor del sensor

    std::string getNombre() const; // metodo para obtener el nombre del sensor
    int getValor() const; // metodo para obtener el valor del sensor
    int getPin() const; // metodo para obtener el pin del sensor
};
#endif
