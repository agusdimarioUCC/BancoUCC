#include "TarjetaCredito.h"
#include <iostream>
using namespace std;

TarjetaCredito::TarjetaCredito() : tipoTarjeta("Ninguna"), limite(0.0)
{
}

TarjetaCredito::TarjetaCredito(string tipoTarjeta, double limite)
	: tipoTarjeta(tipoTarjeta), limite(limite)
{
}

string TarjetaCredito::getTipoTarjeta()
{
	return tipoTarjeta;
}

void TarjetaCredito::setTipoTarjeta(string tipoTarjeta)
{
	this->tipoTarjeta = tipoTarjeta;
}

double TarjetaCredito::getLimite()
{
	return limite;
}

void TarjetaCredito::setLimite(double limite)
{
	this->limite = limite;
}

void TarjetaCredito::mostrarTarjeta()
{
	cout << "Tipo de Tarjeta: " << tipoTarjeta << endl;
	cout << "Limite de Credito: $" << limite << endl;
}
