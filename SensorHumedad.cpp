#include <"SensorHumedad.h">

SensorHumedad::SensorHumedad(uint8_t pin) 
    : Sensor("Sensor de Humedad", pin), _humedad(0.0f) {
    // Constructor para inicializar el pin del sensor de humedad y el valor de humedad
    pinMode(pin, INPUT); // Configura el pin como entrada
    setActivo(true); // Activa el sensor
}

//destructor para liberar recursos del sensor de humedad
SensorHumedad::~SensorHumedad() {} // Aquí podrías agregar código para liberar recursos si es necesario

void SensorHumedad::leerValor() {
    int raw = analogRead(_Pin()); // Lee el valor analógico del sensor de humedad
    _humedad = (float)map(raw, 0, 1023, 0, 100); // Convierte el valor leído a un porcentaje de humedad
    _humedad = constrain(_humedad, 0.0f, 100.0f); // Asegura que el valor de humedad esté entre 0% y 100%
}

// getter

float SensorHumedad::getHumedad() const {
    return _humedad; // Devuelve el valor de humedad leído por el sensor
}

string SensorHumedad::clasificarHumedad() const {
    if (_humedad < 30.0f) {
        return "Bajo"; // Clasificación de humedad baja
    } else if (_humedad < 60.0f) {
        return "Medio"; // Clasificación de humedad media
    } else {
        return "Alto"; // Clasificación de humedad alta
    }
}

void SensorHumedad::imprimirValor() const {
    Serial.print("Humedad: ");
    Serial.print(_humedad);
    Serial.println("%");
    serial.print("Clasificación: ");
    Serial.println(clasificarHumedad().c_str());
}
