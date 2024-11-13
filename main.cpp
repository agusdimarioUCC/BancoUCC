#include <iostream>
#include "Banco.h"

using namespace std;

int main() {
	Banco bancoUCC;
	int opcion;

	do {
		cout << "--- Menu de Gestion Banco UCC ---" << endl;
		cout << "1. Registrar Cliente" << endl;
		cout << "2. Cambiar Estado Cliente" << endl;
		cout << "3. Mostrar Detalle Cliente" << endl;
		cout << "4. Listar Clientes" << endl;
		cout << "5. Realizar Transaccion" << endl;
		cout << "6. Consultar Transacciones" << endl;
		cout << "0. Salir" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			bancoUCC.registrarCliente();
			break;
		case 2:
			bancoUCC.cambiarEstadoCliente();
			break;
		case 3:
			bancoUCC.mostrarCliente();
			break;
		case 4:
			bancoUCC.listarClientes();
			break;
		case 5:
			bancoUCC.realizarTransaccion();
			break;
		case 6:
			bancoUCC.consultarTransacciones();
			break;
		case 0:
			cout << "Saliendo del sistema..." << endl;
			break;
		default:
			cout << "Opcion no valida." << endl;
			break;
		}
		cout << endl;
	} while (opcion != 0);

	return 0;
}
