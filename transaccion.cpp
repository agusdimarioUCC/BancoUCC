#include "Transaccion.h"
#include <iostream>
#include <sstream>

using namespace std;

// Constructor por defecto
Transaccion::Transaccion() : tipo(""), monto(0.0), fecha("") {}

// Constructor con parametros
Transaccion::Transaccion(string tipo, double monto, string fecha)
	: tipo(tipo), monto(monto), fecha(fecha) {}

// Metodo para mostrar la transaccion
void Transaccion::mostrarTransaccion() {
	cout << tipo << " de $" << monto << " el dia " << fecha << endl;
}

// Getters y Setters
string Transaccion::getTipo() const {
	return tipo;
}

void Transaccion::setTipo(const string &tipo) {
	this->tipo = tipo;
}

double Transaccion::getMonto() const {
	return monto;
}

void Transaccion::setMonto(double monto) {
	this->monto = monto;
}

string Transaccion::getFecha() const {
	return fecha;
}

void Transaccion::setFecha(const string &fecha) {
	this->fecha = fecha;
}

int Transaccion::getMes() const {
	int dia, mes, anio;
	char sep;
	istringstream iss(fecha);
	iss >> dia >> sep >> mes >> sep >> anio;
	return mes;
}

int Transaccion::getAnio() const {
	int dia, mes, anio;
	char sep;
	istringstream iss(fecha);
	iss >> dia >> sep >> mes >> sep >> anio;
	return anio;
}
