#ifndef CUENTA_H
#define CUENTA_H

#include "Transaccion.h"

class Cuenta {
public:
	string tipoCuenta;
	double saldo;
	Transaccion transacciones[100];
	int numTransacciones;

	Cuenta();
	Cuenta(string tipo, double saldoInicial);
	void realizarTransaccion(string tipo, double monto, string fecha);
	void mostrarTransacciones();
};

#endif
