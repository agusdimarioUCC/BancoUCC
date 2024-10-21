#ifndef CLIENTE_H
#define CLIENTE_H

#include "Cuenta.h"

class Cliente {
public:
	string dni;
	string nombre;
	string tipoCliente;
	int anioIngreso;
	string estado;
	Cuenta cuentas[2];
	double limiteCredito;

	Cliente();
	Cliente(string d, string n, string tipo, int anio);
	void agregarCuenta(string tipoCuenta, double saldoInicial);
	void realizarTransaccion(string tipoCuenta, string tipoTransaccion, double monto, string fecha);
	void mostrarInfo();
	void cambiarEstado(string nuevoEstado);
};

#endif
