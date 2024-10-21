#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente() {}

Cliente::Cliente(string d, string n, string tipo, int anio) : dni(d), nombre(n), tipoCliente(tipo), anioIngreso(anio), estado("ACTIVO") {
	if (tipoCliente == "Oro") {
		limiteCredito = 250000;
	} else if (tipoCliente == "Platino") {
		limiteCredito = 500000;
	} else {
		limiteCredito = 0;
	}
}

void Cliente::agregarCuenta(string tipoCuenta, double saldoInicial) {
	if (tipoCuenta == "Pesos") {
		cuentas[0] = Cuenta("Caja de Ahorro en Pesos", saldoInicial);
	} else if (tipoCuenta == "Dolares") {
		cuentas[1] = Cuenta("Caja de Ahorro en Dólares", saldoInicial);
	}
}

void Cliente::realizarTransaccion(string tipoCuenta, string tipoTransaccion, double monto, string fecha) {
	if (tipoCuenta == "Pesos") {
		cuentas[0].realizarTransaccion(tipoTransaccion, monto, fecha);
	} else if (tipoCuenta == "Dolares") {
		cuentas[1].realizarTransaccion(tipoTransaccion, monto, fecha);
	}
}

void Cliente::mostrarInfo() {
	cout << "Cliente: " << nombre << " (" << dni << ") - Tipo: " << tipoCliente << " - Estado: " << estado << endl;
	cout << "Cuenta Pesos con saldo $" << cuentas[0].saldo << endl;
	cuentas[0].mostrarTransacciones();
	cout << "Cuenta Dólares con saldo $" << cuentas[1].saldo << endl;
	cuentas[1].mostrarTransacciones();
}

void Cliente::cambiarEstado(string nuevoEstado) {
	estado = nuevoEstado;
}
