#include <string>
using namespace std;

class Transaccion {
private:
	string tipo;  // "Deposito" o "Extraccion"
	double monto;
	int dia;
	int mes;
	int anio;

public:
	Transaccion();
	Transaccion(string tipo, double monto, int dia, int mes, int anio);
	void mostrarTransaccion();

	// Getters y Setters
	string getTipo() const;
	void setTipoTransaccion(string tipoTransaccion);
	double getMonto() const;
	void setMonto(double monto);
	int getDia() const;
	void setDia(int dia);
	int getMes() const;
	void setMes(int mes);
	int getAnio() const;
	void setAnio(int anio);

};