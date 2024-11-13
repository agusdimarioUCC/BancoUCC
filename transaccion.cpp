#include "Transaccion.h"
#include <iostream>

using namespace std;

// Constructor por defecto
Transaccion::Transaccion() : tipo(""), monto(0.0), dia(0), mes(0), anio(0) {}

// Constructor con parámetros
Transaccion::Transaccion(std::string tipo, double monto, int dia, int mes, int anio)
	: tipo(tipo), monto(monto), dia(dia), mes(mes), anio(anio) {}

void Transaccion::mostrarTransaccion() {
	cout << tipo << " de $" << monto << " el dia " << dia << "/" << mes << "/" << anio << endl;
}

// Getters y Setters
std::string Transaccion::getTipo() const {
	return tipo;
}

void Transaccion::setTipoTransaccion(std::string tipoTransaccion) {
	this->tipo = tipoTransaccion;
}

double Transaccion::getMonto() const {
	return monto;
}

void Transaccion::setMonto(double monto) {
	this->monto = monto;
}

int Transaccion::getDia() const {
	return dia;
}

void Transaccion::setDia(int dia) {
	this->dia = dia;
}

int Transaccion::getMes() const {
	return mes;
}

void Transaccion::setMes(int mes) {
	this->mes = mes;
}

int Transaccion::getAnio() const {
	return anio;
}

void Transaccion::setAnio(int anio) {
	this->anio = anio;
}
