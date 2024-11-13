#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include "Cuenta.h"

class Cliente {
public:
	Cliente();
	Cliente(int dni, std::string nombre, std::string tipoCliente, int anioIngreso);
	void realizarTransaccion();
	void consultarTransacciones();
	void consultarCuenta();

	// Getters y Setters
	int getDni() const;
	void setDni(int dni);
	std::string getNombre() const;
	void setNombre(const std::string &nombre);
	std::string getTipoCliente() const;
	void setTipoCliente(const std::string &tipoCliente);
	int getAnioIngreso() const;
	void setAnioIngreso(int anioIngreso);
	bool isActivo() const;
	void setActivo(bool activo);

private:
	int dni;
	std::string nombre;
	std::string tipoCliente; // "PLATA", "ORO", "PLATINO"
	int anioIngreso;
	bool activo;
	Cuenta cajasDeAhorro[2];  // Dos cuentas, en pesos y en dolares
};

#endif // CLIENTE_H
