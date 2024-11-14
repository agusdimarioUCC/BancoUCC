#include "Transaccion.h"
#include <string>

class Cuenta {
public:
	Cuenta();
	Cuenta(double saldoInicial, std::string tipoCuenta);
	void depositar(double monto, int dia, int mes, int anio);
	void extraer(double monto, int dia, int mes, int anio);

	void mostrarTransacciones();
	void mostrarTransaccionesPorMes(int mes, int anio);
	void mostrarTransaccionesPorAnio(int anio);

	// Getters y Setters
	std::string getTipoCuenta() ;
	void setTipoCuenta(std::string tipoCuenta);
	double getSaldo() ;
	void setSaldo(double saldo);

private:
	std::string tipoCuenta; // "Pesos" o "Dolares"
	double saldo;
	Transaccion transacciones[100];  // Array fijo de transacciones
	int numTransacciones; // Contador de transacciones
};

