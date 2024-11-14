#include <string>
#include "Transaccion.h"
using namespace std;
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
	string tipoCuenta;
	double saldo;
	Transaccion transacciones[10]; //10 transacciones max para que no explote la ram
	int numTransacciones;
};

