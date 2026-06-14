#include "../include/Estacion_Meteorologica.h"


EstacionMeteorologica::EstacionMeteorologica(LiquidCrystal *lcd) 
    : _numSensores(0), pantallaActual(0),
     _lcd(lcd), _sensorDht11(nullptr), _sensorHumedad(nullptr) {
        for (int i = 0; i < MAX_SENSORES; i++) {
            _sensores[i] = nullptr; // inicializa el arreglo de sensores con punteros nulos
        }
    // Constructor por defecto, inicializa el número de sensores a 0
}

//destructor para liberar recursos de los sensores registrados en la estación meteorológica
EstacionMeteorologica::~EstacionMeteorologica() {
    for (int i = 0; i < _numSensores; i++) {
        delete _sensores[i]; // libera la memoria de cada sensor registrado
    }
}

// Método para registrar un nuevo sensor en la estación meteorológica
bool EstacionMeteorologica::agregarSensor (Sensores* sensor) {
    if (_numSensores >=  MAX_SENSORES) return false; // verifica si se ha alcanzado el límite máximo de sensores, si es así, no registra el nuevo sensor
        _sensores[_numSensores++] = sensor; // agrega el nuevo sensor al arreglo y actualiza el número de sensores
    return true; // indica que el sensor se registró exitosamente
}

void EstacionMeteorologica::setRefDHT11(SensorDht11* s) {
     _sensorDht11 = s; // establece la referencia al sensor Dht11 para la estación meteorológica
}
void EstacionMeteorologica::setRefsensorHumedadSuelo(SensorHumedad* s) {
    _sensorHumedad = s; // establece la referencia al sensor de humedad para la estación meteorológica
}

void EstacionMeteorologica::tomarLecturas() {
    for (int i = 0; i < _numSensores; i++) {
        if (_sensores[i] && _sensores[i]->isActivo()){
            _sensores[i]->leerValor(); // lee el valor de cada sensor registrado que esté activo
        }
    }
}

// Método para mostrar la información de los sensores en la LCD 16x2, alternando entre diferentes pantallas cada cierto tiempo

void EstacionMeteorologica::imprimirValoresSerial() const{
    Serial.println("miniestacion meteorologica");
    for (int i = 0; i < _numSensores; i++) {
        if (_sensores[i]){
            _sensores[i]->imprimirValor(); // imprime el valor de cada sensor registrado que esté activo en la LCD 16x2
        }
     }
     Serial.println();

}

void EstacionMeteorologica::SiguientePantalla() {
    pantallaActual = (pantallaActual + 1) % TOTAL_PANTALLAS; // alterna entre las distintas pantallas disponibles
}

void EstacionMeteorologica::mostrarPantallaTempAire(){
    float temp = _sensorDht11 ? _sensorDht11->getTemperatura() : 0.0; // obtiene la temperatura del sensor Dht11, si está disponible

    _lcd->clear(); // limpia la pantalla LCD
    _lcd->setCursor(0, 0); // establece el cursor en la primera
    _lcd->print("Temperatura: "); // imprime el texto "Temperatura: " en la LCD
    _lcd->setCursor(0, 1); // establece el cursor en la segunda línea
    _lcd->print(temp, 1); // imprime el valor de temperatura con un decimal en la LCD
    _lcd->print((char)223); // imprime el símbolo de grados en la LCD
    _lcd->print(" C"); // imprime el símbolo de grados Celsius en la LCD
}

//pantalla 1 para mostrar la humedad
void EstacionMeteorologica::mostrarPantallaHumAire(){
    float humedad = _sensorDht11 ? _sensorDht11->getHumedad() : 0.0; // obtiene la humedad del sensor de humedad, si está disponible

    _lcd->clear(); // limpia la pantalla LCD
    _lcd->setCursor(0, 0); // establece el cursor en la primera línea
    _lcd->print("Humedad: "); // imprime el texto "Humedad: " en la LCD
    _lcd->setCursor(0, 1); // establece el cursor en la segunda línea
    _lcd->print(humedad, 1); // imprime el valor de humedad con un decimal en la LCD
    _lcd->print(" %"); // imprime el símbolo de porcentaje en la LCD
}

// pantalla 2 humedad del suelo
void EstacionMeteorologica::mostrarPantallaHumSuelo(){
    float humedadSuelo = _sensorHumedad ? _sensorHumedad->getHumedad() : 0.0; // obtiene la humedad del suelo del sensor de humedad, si está disponible

    _lcd->clear(); // limpia la pantalla LCD
    _lcd->setCursor(0, 0); // establece el cursor en la primera línea
    _lcd->print("Humedad Suelo: "); // imprime el texto "Humedad Suelo: " en la LCD
    _lcd->setCursor(0, 1); // establece el cursor en la segunda línea
    _lcd->print(humedadSuelo, 1); // imprime el valor de humedad del suelo con un decimal en la LCD
    _lcd->print(" %"); // imprime el símbolo de porcentaje en la LCD
    if (_sensorHumedad) {
    _lcd->print(_sensorHumedad->clasificarHumedad());
    }
}

//refrescar la pantalla actual
void EstacionMeteorologica::actualizarPantallaLCD() {
    switch (pantallaActual) {
        case 0:
            mostrarPantallaTempAire(); // muestra la pantalla de temperatura
            break;
        case 1:
            mostrarPantallaHumAire(); // muestra la pantalla de humedad
            break;
        case 2:
            mostrarPantallaHumSuelo(); // muestra la pantalla de humedad del suelo
            break;
        default:
            break;
    }
}

void EstacionMeteorologica::mostrarInicio(){
    _lcd->clear(); // limpia la pantalla LCD
    _lcd->setCursor(0, 0); // establece el cursor en la primera línea
    _lcd->print("Miniestacion"); // imprime el texto "Miniestacion" en la LCD
    _lcd->setCursor(0, 1); // establece el cursor en la segunda línea
    _lcd->print("Meteorologica"); // imprime el texto "Meteorologica" en la LCD
    delay(2000); // espera 2 segundos antes de mostrar la siguiente pantalla
    _lcd->clear(); // limpia la pantalla LCD
    _lcd->setCursor(0, 0); // establece el cursor en la primera línea
    _lcd->print("Iniciando..."); // imprime el texto "Iniciando..." en la LCD
    delay(2000); // espera 2 segundos antes de mostrar la siguiente pantalla
}