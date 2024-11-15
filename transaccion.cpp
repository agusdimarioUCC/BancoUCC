#include "Transaccion.h"
#include <iostream>

using namespace std;

Transaccion::Transaccion() : tipo(""), monto(0.0), dia(0), mes(0), anio(0) {}

Transaccion::Transaccion(string tipo, double monto, int dia, int mes, int anio)
	: tipo(tipo), monto(monto), dia(dia), mes(mes), anio(anio) {}

void Transaccion::mostrarTransaccion() {
	cout << tipo << " de $" << monto << " el dia " << dia << "/" << mes << "/" << anio << endl;
}

string Transaccion::getTipo()  {
	return tipo;
}

void Transaccion::setTipoTransaccion(string tipoTransaccion) {
	this->tipo = tipoTransaccion;
}

double Transaccion::getMonto()  {
	return monto;
}

void Transaccion::setMonto(double monto) {
	this->monto = monto;
}

int Transaccion::getDia()  {
	return dia;
}

void Transaccion::setDia(int dia) {
	this->dia = dia;
}

int Transaccion::getMes()  {
	return mes;
}

void Transaccion::setMes(int mes) {
	this->mes = mes;
}

int Transaccion::getAnio()  {
	return anio;
}

void Transaccion::setAnio(int anio) {
	this->anio = anio;
}
