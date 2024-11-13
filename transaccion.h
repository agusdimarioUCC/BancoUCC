#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>

class Transaccion {
public:
	Transaccion();
	Transaccion(std::string tipo, double monto, std::string fecha);
	void mostrarTransaccion();

	// Getters y Setters
	std::string getTipo() const;
	void setTipo(const std::string &tipo);
	double getMonto() const;
	void setMonto(double monto);
	std::string getFecha() const;
	void setFecha(const std::string &fecha);

	int getMes() const;
	int getAnio() const;

private:
	std::string tipo;  // "Deposito" o "Extraccion"
	double monto;
	std::string fecha;  // Formato "DD/MM/AAAA"
};

#endif // TRANSACCION_H
