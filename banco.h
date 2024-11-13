#ifndef BANCO_H
#define BANCO_H

#include "Cliente.h"

class Banco {
public:
	Banco();
	void registrarCliente();      // Alta de cliente
	void cambiarEstadoCliente();  // Cambiar estado del cliente (Activo a Baja)
	void mostrarCliente();        // Detalle de un cliente por su numero
	void listarClientes();        // Listado de todos los clientes

	// Metodos para gestionar transacciones
	void realizarTransaccion();    // Registrar una transaccion para un cliente
	void consultarTransacciones(); // Consultar transacciones segun criterios

private:
	Cliente clientes[100];  // Array fijo para almacenar clientes
	int numClientes;        // Contador de clientes

	int buscarClientePorDNI(int dni);  // Metodo auxiliar para buscar un cliente
};

#endif // BANCO_H
