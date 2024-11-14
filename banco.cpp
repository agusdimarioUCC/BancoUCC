#include "Banco.h"
#include <iostream>

using namespace std;
//aca hacemos basicamente lo divertido
Banco::Banco() : numClientes(0) {}//cero porque es el constructor por defecto

void Banco::registrarCliente() {
    if (numClientes >= 100) {//aca creo que deberiamos poner la longitud del array en vez de hardcodearlo pero bueno
        cout << "No se pueden registrar mas clientes." << endl;
        return;
    }

    int dniINGRESADO, anioIngreso;
    string nombre, tipoCliente;

    cout << "Ingrese DNI: ";
    cin >> dniINGRESADO;

    if (buscarClientePorDNI(dniINGRESADO) != -1) {
        cout << "El cliente con DNI " << dniINGRESADO << " ya esta registrado." << endl;
        return;
    }

    cout << "Ingrese Nombre: ";
    getline(cin, nombre);

    cout << "Ingrese Tipo de Cliente (PLATA, ORO, PLATINO): ";
    getline(cin, tipoCliente);

    //validamos tipo de cliente
    if (tipoCliente != "PLATA" && tipoCliente != "ORO" && tipoCliente != "PLATINO") {
        cout << "Tipo de cliente no valido. Debe ser PLATA, ORO o PLATINO." << endl;
        return;
    }

    cout << "Ingrese Anio de Ingreso: ";
    cin >> anioIngreso;

    clientes[numClientes++] = Cliente(dniINGRESADO, nombre, tipoCliente, anioIngreso);
    cout << "Cliente registrado exitosamente." << endl;
}

void Banco::cambiarEstadoCliente() {
    int dni;
    cout << "Ingrese el DNI del cliente a dar de baja: ";
    cin >> dni;

    int indice = buscarClientePorDNI(dni);
    if (indice != -1) {//tremendo bardo para buscar por dni
        if (!clientes[indice].isActivo()) {
            cout << "El cliente ya esta dado de baja." << endl;
            return;
        }
        clientes[indice].setActivo(false);//usamos el setter para cambiar el estado
        cout << "El cliente ha sido dado de baja." << endl;
    } else {
        cout << "Cliente no encontrado." << endl;
    }
}

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
        cout << "Estado: " << (cliente.isActivo() ? "Activo" : "Baja") << endl;//esto es un operador ternario para simplificar un if-else en una linea
        cliente.consultarCuenta();
        cliente.mostrarTarjetaCredito();
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

int Banco::buscarClientePorDNI(int dni) {
    for (int i = 0; i < numClientes; ++i) {
        if (clientes[i].getDni() == dni) {
            return i;
        }
    }
    return -1;  // No encontrado
}
