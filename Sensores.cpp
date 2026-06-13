#include "Sensores.h"

Sensores::Sensores(const String& nombre, uint8_t pin) 
    : _nombre(nombre), _pin(pin), _activo(false) {}

Sensores::~Sensores() {}

string Sensores::getNombre() const {
    return _nombre;
}
uint8_t Sensores::getPin() const {
    return _pin;
}
bool Sensores::isActivo() const {
    return _activo;
}
void Sensores::setActivo(bool estado) {
    _activo = estado;
}