#include "Banco.h"
#include <iostream>

using namespace std;

Banco::Banco() : numClientes(0) {}

// Metodo para registrar un nuevo cliente
void Banco::registrarCliente() {
    if (numClientes >= 100) {
        cout << "No se pueden registrar mas clientes." << endl;
        return;
    }

    int dni, anioIngreso;
    string nombre, tipoCliente;

    cout << "Ingrese DNI: ";
    cin >> dni;
    cin.ignore();  // Limpiar el buffer de entrada

    // Verificar si el cliente ya existe
    if (buscarClientePorDNI(dni) != -1) {
        cout << "El cliente con DNI " << dni << " ya esta registrado." << endl;
        return;
    }

    cout << "Ingrese Nombre: ";
    getline(cin, nombre);

    cout << "Ingrese Tipo de Cliente (PLATA, ORO, PLATINO): ";
    getline(cin, tipoCliente);

    // Validar tipo de cliente
    if (tipoCliente != "PLATA" && tipoCliente != "ORO" && tipoCliente != "PLATINO") {
        cout << "Tipo de cliente no valido. Debe ser PLATA, ORO o PLATINO." << endl;
        return;
    }

    cout << "Ingrese Anio de Ingreso: ";
    cin >> anioIngreso;

    clientes[numClientes++] = Cliente(dni, nombre, tipoCliente, anioIngreso);
    cout << "Cliente registrado exitosamente." << endl;
}

// Metodo para cambiar el estado de un cliente (Activo a Baja)
void Banco::cambiarEstadoCliente() {
    int dni;
    cout << "Ingrese el DNI del cliente a dar de baja: ";
    cin >> dni;

    int indice = buscarClientePorDNI(dni);
    if (indice != -1) {
        if (!clientes[indice].isActivo()) {
            cout << "El cliente ya esta dado de baja." << endl;
            return;
        }
        clientes[indice].setActivo(false);
        cout << "El cliente ha sido dado de baja." << endl;
    } else {
        cout << "Cliente no encontrado." << endl;
    }
}

// Metodo para mostrar detalles de un cliente
void Banco::mostrarCliente() {
    int dni;
    cout << "Ingrese el DNI del cliente: ";
    cin >> dni;

    int indice = buscarClientePorDNI(dni);
    if (indice != -1) {
        Cliente cliente = clientes[indice];
        cout << "DNI: " << cliente.getDni() << endl;
        cout << "Nombre: " << cliente.getNombre() << endl;
        cout << "Tipo de Cliente: " << cliente.getTipoCliente() << endl;
        cout << "Anio de Ingreso: " << cliente.getAnioIngreso() << endl;
        cout << "Estado: " << (cliente.isActivo() ? "Activo" : "Baja") << endl;
        cliente.consultarCuenta();  // Mostrar informacion de las cuentas
    } else {
        cout << "Cliente no encontrado." << endl;
    }
}

// Metodo para listar todos los clientes
void Banco::listarClientes() {
    if (numClientes == 0) {
        cout << "No hay clientes registrados." << endl;
        return;
    }

    for (int i = 0; i < numClientes; ++i) {
        cout << "Cliente " << i + 1 << ":" << endl;
        cout << "DNI: " << clientes[i].getDni() << endl;
        cout << "Nombre: " << clientes[i].getNombre() << endl;
        cout << "Tipo de Cliente: " << clientes[i].getTipoCliente() << endl;
        cout << "Estado: " << (clientes[i].isActivo() ? "Activo" : "Baja") << endl;
        cout << "------------------------" << endl;
    }
}

// Metodo para realizar una transaccion para un cliente
void Banco::realizarTransaccion() {
    int dni;
    cout << "Ingrese el DNI del cliente: ";
    cin >> dni;

    int indice = buscarClientePorDNI(dni);
    if (indice != -1) {
        if (!clientes[indice].isActivo()) {
            cout << "El cliente esta dado de baja y no puede realizar transacciones." << endl;
            return;
        }
        clientes[indice].realizarTransaccion();
    } else {
        cout << "Cliente no encontrado." << endl;
    }
}

// Metodo para consultar transacciones de un cliente
void Banco::consultarTransacciones() {
    int dni;
    cout << "Ingrese el DNI del cliente: ";
    cin >> dni;

    int indice = buscarClientePorDNI(dni);
    if (indice != -1) {
        clientes[indice].consultarTransacciones();
    } else {
        cout << "Cliente no encontrado." << endl;
    }
}

// Metodo auxiliar para buscar un cliente por DNI
int Banco::buscarClientePorDNI(int dni) {
    for (int i = 0; i < numClientes; ++i) {
        if (clientes[i].getDni() == dni) {
            return i;
        }
    }
    return -1;  // No encontrado
}
