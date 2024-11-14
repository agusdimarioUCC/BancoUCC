#include <iostream>
#include "Transaccion.h"
using namespace std;
Transaccion::Transaccion() : tipoTransaccion(""), monto(0.0), dia(0), mes(0), anio(0) {}

Transaccion::Transaccion(string tipo, double monto, int dia, int mes, int anio)
	: tipoTransaccion(tipo), monto(monto), dia(dia), mes(mes), anio(anio) {}

void Transaccion::mostrarTransaccion() {
	cout << tipoTransaccion << " de $" << monto << " el dia " << dia << "/" << mes << "/" << anio << endl;
}

string Transaccion::getTipo()  {
	return tipoTransaccion;
}

void Transaccion::setTipoTransaccion(string tipoTransaccion) {
	this->tipoTransaccion = tipoTransaccion;
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
