#include "Banco.h"
#include <fstream>
#include <iostream>
using namespace std;

Banco::Banco() {
	numClientes = 0;
}

void Banco::agregarCliente(Cliente cliente) {
	clientes[numClientes] = cliente;
	numClientes++;
}

void Banco::mostrarClientes() {
	for (int i = 0; i < numClientes; i++) {
		clientes[i].mostrarInfo();
	}
}

Cliente* Banco::buscarClientePorDNI(string dni) {
	for (int i = 0; i < numClientes; i++) {
		if (clientes[i].dni == dni) {
			return &clientes[i];
		}
	}
	return nullptr;
}

void Banco::guardarClientesEnArchivo() {
	ofstream archivo("clientes.txt");
	for (int i = 0; i < numClientes; i++) {
		archivo << clientes[i].dni << "," << clientes[i].nombre << ","
				<< clientes[i].tipoCliente << "," << clientes[i].anioIngreso
				<< "," << clientes[i].estado << endl;
	}
	archivo.close();
}

void Banco::cargarClientesDesdeArchivo() {
	ifstream archivo("clientes.txt");
	string dni, nombre, tipoCliente, estado;
	int anioIngreso;
	while (archivo >> dni >> nombre >> tipoCliente >> anioIngreso >> estado) {
		Cliente cliente(dni, nombre, tipoCliente, anioIngreso);
		cliente.cambiarEstado(estado);
		agregarCliente(cliente);
	}
	archivo.close();
}
