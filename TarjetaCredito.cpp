#include "TarjetaCredito.h"
#include <iostream>

using namespace std;

// Constructor por defecto
TarjetaCredito::TarjetaCredito() : tipoTarjeta("Ninguna"), limite(0.0) {}

// Constructor con parametros
TarjetaCredito::TarjetaCredito(string tipoTarjeta, double limite)
	: tipoTarjeta(tipoTarjeta), limite(limite) {}

// Metodo para mostrar la tarjeta
void TarjetaCredito::mostrarTarjeta() {
	cout << "Tarjeta: " << tipoTarjeta << ", Limite: $" << limite << endl;
}

// Getters y Setters
string TarjetaCredito::getTipoTarjeta()  {
	return tipoTarjeta;
}

void TarjetaCredito::setTipoTarjeta(string tipoTarjeta) {
	this->tipoTarjeta = tipoTarjeta;
}

double TarjetaCredito::getLimite()  {
	return limite;
}

void TarjetaCredito::setLimite(double limite) {
	this->limite = limite;
}
