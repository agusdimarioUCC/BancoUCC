#include "Transaccion.h"
#include <string>

class Cuenta {
public:
	Cuenta();
	Cuenta(double saldoInicial, string tipoCuenta);
	void depositar(double monto, int dia, int mes, int anio);
	void extraer(double monto, int dia, int mes, int anio);

	void mostrarTransacciones();
	void mostrarTransaccionesPorMes(int mes, int anio);
	void mostrarTransaccionesPorAnio(int anio);

	string getTipoCuenta() ;
	void setTipoCuenta(string tipoCuenta);
	double getSaldo() ;
	void setSaldo(double saldo);

private:
	string tipoCuenta; //si son solo dos, no podria ser un bool?
	double saldo;
	Transaccion transacciones[10]; //maximo 10 para no explotar la memoria
	int numTransacciones;
};