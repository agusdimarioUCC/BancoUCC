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
	Cliente clientes[10];//10 clientes para no explotar la ram
	int numClientes;
	int buscarClientePorDNI(int dni);//odio este metodo
};