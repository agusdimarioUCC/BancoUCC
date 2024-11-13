#ifndef TRANSACCION_H
#define TRANSACCION_H
#include <string>

class Transaccion {
public:
	Transaccion();
	Transaccion(std::string tipo, double monto, int dia, int mes, int anio);
	void mostrarTransaccion();

	// Getters y Setters
	std::string getTipo() const;
	void setTipoTransaccion(std::string tipoTransaccion);
	double getMonto() const;
	void setMonto(double monto);
	int getDia() const;
	void setDia(int dia);
	int getMes() const;
	void setMes(int mes);
	int getAnio() const;
	void setAnio(int anio);

private:
	std::string tipo;  // "Deposito" o "Extraccion"
	double monto;
	int dia;
	int mes;
	int anio;
};

#endif // TRANSACCION_H
