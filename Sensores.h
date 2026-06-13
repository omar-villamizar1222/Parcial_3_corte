#ifndef SENSORES
#define SENSORES    

#include <Arduino.h>
/*@brief clase base abstracta para los sensores, con un metodo virtual puro para obtener la lectura del sensor*/
class Sensor {

    protected:
        bool activo; // estado del sensor (activo/inactivo)
        float valor; // valor leido del sensor
        String nombre; // nombre del sensor

/* @brief Constructor de la clase Sensor. 
/* @param valor: Valor leído por el sensor.
 * @param pin: Pin al que está conectado el sensor.
 * @param nombre: Nombre del sensor.
 */

 public:
    
    Sensor(const String& nombre)
           
    virtual ~Sensor(); // destructor virtual por defecto

    virtual float leerValor() = 0; // metodo virtual puro para leer el valor del sensor
    float getValor() const; // metodo para obtener el valor del sensor
    bool isActivo() const; // metodo para obtener el estado del sensor
    String getNombre() const; // metodo para obtener el nombre del sensor

    void setActivo(bool estado); // metodo para establecer el estado del sensor

    virtual string getUnidad() const; // metodo virtual para obtener la unidad de medida del sensor (sobrescribible por las clases derivadas)
    virtual void imprimirValor() const; // metodo virtual para imprimir el valor del sensor (sob

};
#endif // SENSORES
