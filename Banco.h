#ifndef BANCO_H
#define BANCO_H

#include "Cliente.h"

class Banco {
public:
	Cliente clientes[100];
	int numClientes;

	Banco();
	void agregarCliente(Cliente cliente);
	void mostrarClientes();
	Cliente* buscarClientePorDNI(string dni);
	void guardarClientesEnArchivo();
	void cargarClientesDesdeArchivo();
};

#endif
