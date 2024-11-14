#include "Cliente.h"

class Banco {
public:
	Banco();
	void registrarCliente();
	void cambiarEstadoCliente();
	void mostrarCliente();
	void listarClientes();

	void realizarTransaccion();
	void consultarTransacciones();

private:
	Cliente clientes[10];  //10 clientes para que no explote la memoria
	int numClientes;        //contador de clientes

	int buscarClientePorDNI(int dni);
};