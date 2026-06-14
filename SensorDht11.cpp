#include "../include/SensorDht11.h"

SensorDht11::SensorDht11(uint8_t pin) 
    : Sensor("Dht11", pin), _temperatura(0.0f), _humedad(0.0f) {
    _dht = new DHT(_pin, DHT11); // inicializa el objeto DHT para manejar el sensor Dht11
    _dht->begin(); // inicia la comunicación con el sensor Dht11
    setActivo(true); // establece el sensor como activo
}

SensorDht11::~SensorDht11() {
    delete _dht; // libera los recursos del objeto DHT
    _dht = nullptr; // evita punteros colgantes
}

void SensorDht11::leerValor() {
    _t= _dht->readTemperature(); // lee la temperatura del sensor Dht11
    _h = _dht->readHumidity(); // lee la humedad del sensor Dht11

    if(!isnan(t)) _temperatura = t; // actualiza la variable de temperatura si la lectura es válida
    if(!isnan(h)) _humedad = h; // actualiza la variable de humedad si la lectura es válida 
}

//getters

float SensorDht11::getTemperatura() const {
    return _temperatura; // devuelve la temperatura leída por el sensor Dht11
}

float SensorDht11::getHumedad() const {
    return _humedad; // devuelve la humedad leída por el sensor Dht11
}

// método para imprimir los valores de temperatura y humedad leídos por el sensor Dht11

void SensorDht11::imprimirValor() const {
    Serial.print("Temperatura: ");
    Serial.print(_temperatura);
    Serial.println(" °C")

    serial.print("Humedad: ");
    Serial.print(_humedad,1);
    Serial.println(" %");
}