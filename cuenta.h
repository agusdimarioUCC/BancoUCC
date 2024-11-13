#ifndef CUENTA_H
#define CUENTA_H

#include "Transaccion.h"
#include <string>

class Cuenta {
public:
	Cuenta();
	Cuenta(double saldoInicial, std::string tipoCuenta);
	void depositar(double monto, std::string fecha);
	void extraer(double monto, std::string fecha);

	void mostrarTransacciones();
	void mostrarTransaccionesPorMes(int mes, int anio);
	void mostrarTransaccionesPorAnio(int anio);

	// Getters y Setters
	std::string getTipoCuenta() const;
	void setTipoCuenta(const std::string &tipoCuenta);
	double getSaldo() const;
	void setSaldo(double saldo);

private:
	std::string tipoCuenta; // "Pesos" o "Dolares"
	double saldo;
	Transaccion transacciones[100];  // Array fijo de transacciones
	int numTransacciones; // Contador de transacciones
};

#endif // CUENTA_H
