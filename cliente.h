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
	int getDni() ;
	void setDni(int dni);
	std::string getNombre() ;
	void setNombre(std::string nombre);
	std::string getTipoCliente() ;
	void setTipoCliente(std::string tipoCliente);
	int getAnioIngreso() ;
	void setAnioIngreso(int anioIngreso);
	bool isActivo() ;
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
