#include <string>
#include "Cuenta.h"
#include "TarjetaCredito.h"

class Cliente {
public:
	Cliente();
	Cliente(int dni, std::string nombre, string tipoCliente, int anioIngreso);
	void realizarTransaccion();
	void consultarTransacciones();
	void consultarCuenta();
	void asignarTarjetaCredito();
	void mostrarTarjetaCredito();

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
	std::string tipoCliente;
	int anioIngreso;
	bool activo;
	Cuenta cajasDeAhorro[2];  // en pesos y en dolares
	TarjetaCredito tarjeta;
};
