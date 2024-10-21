#include "Cuenta.h"
#include <iostream>
using namespace std;

Cuenta::Cuenta() {
	saldo = 0.0;
	numTransacciones = 0;
}

Cuenta::Cuenta(string tipo, double saldoInicial) : tipoCuenta(tipo), saldo(saldoInicial) {
	numTransacciones = 0;
}

void Cuenta::realizarTransaccion(string tipo, double monto, string fecha) {
	Transaccion nuevaTransaccion(tipo, monto, fecha);
	transacciones[numTransacciones] = nuevaTransaccion;
	numTransacciones++;

	if (tipo == "Deposito") {
		saldo += monto;
	} else if (tipo == "Extraccion") {
		saldo -= monto;
	}
}

void Cuenta::mostrarTransacciones() {
	for (int i = 0; i < numTransacciones; i++) {
		transacciones[i].mostrar();
	}
}
