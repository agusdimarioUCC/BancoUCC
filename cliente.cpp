#include "Cliente.h"
#include <iostream>

using namespace std;

// Constructor por defecto
Cliente::Cliente() : dni(0), nombre(""), tipoCliente(""), anioIngreso(0), activo(true) {}

// Constructor
Cliente::Cliente(int dni, string nombre, string tipoCliente, int anioIngreso)
    : dni(dni), nombre(nombre), tipoCliente(tipoCliente), anioIngreso(anioIngreso), activo(true) {
    // Inicializar las cuentas de ahorro en pesos y dolares
    cajasDeAhorro[0] = Cuenta(0.0, "Pesos");
    cajasDeAhorro[1] = Cuenta(0.0, "Dolares");
}

// Getters y Setters

int Cliente::getDni() const {
    return dni;
}

void Cliente::setDni(int dni) {
    this->dni = dni;
}

string Cliente::getNombre() const {
    return nombre;
}

void Cliente::setNombre(const string &nombre) {
    this->nombre = nombre;
}

string Cliente::getTipoCliente() const {
    return tipoCliente;
}

void Cliente::setTipoCliente(const string &tipoCliente) {
    this->tipoCliente = tipoCliente;
}

int Cliente::getAnioIngreso() const {
    return anioIngreso;
}

void Cliente::setAnioIngreso(int anioIngreso) {
    this->anioIngreso = anioIngreso;
}

bool Cliente::isActivo() const {
    return activo;
}

void Cliente::setActivo(bool activo) {
    this->activo = activo;
}

// Metodo para realizar una transaccion
void Cliente::realizarTransaccion() {
    int opcionCuenta;
    cout << "Seleccione la cuenta:" << endl;
    cout << "1. Caja de Ahorro en Pesos" << endl;
    cout << "2. Caja de Ahorro en Dolares" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcionCuenta;

    if (opcionCuenta != 1 && opcionCuenta != 2) {
        cout << "Opcion no valida." << endl;
        return;
    }

    int indiceCuenta = opcionCuenta - 1;

    int opcionTransaccion;
    cout << "Seleccione el tipo de transaccion:" << endl;
    cout << "1. Deposito" << endl;
    cout << "2. Extraccion" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcionTransaccion;

    double monto;
    cout << "Ingrese el monto: ";
    cin >> monto;

    if (monto <= 0) {
        cout << "El monto debe ser positivo." << endl;
        return;
    }

    // Obtener fecha
    string fecha;
    cout << "Ingrese la fecha (DD/MM/AAAA): ";
    cin.ignore();
    getline(cin, fecha);

    if (opcionTransaccion == 1) {
        cajasDeAhorro[indiceCuenta].depositar(monto, fecha);
        cout << "Deposito realizado exitosamente." << endl;
    } else if (opcionTransaccion == 2) {
        if (cajasDeAhorro[indiceCuenta].getSaldo() >= monto) {
            cajasDeAhorro[indiceCuenta].extraer(monto, fecha);
            cout << "Extraccion realizada exitosamente." << endl;
        } else {
            cout << "Saldo insuficiente para realizar la extraccion." << endl;
        }
    } else {
        cout << "Opcion de transaccion no valida." << endl;
    }
}

// Metodo para consultar transacciones
void Cliente::consultarTransacciones() {
    int opcionCuenta;
    cout << "Seleccione la cuenta:" << endl;
    cout << "1. Caja de Ahorro en Pesos" << endl;
    cout << "2. Caja de Ahorro en Dolares" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcionCuenta;

    if (opcionCuenta != 1 && opcionCuenta != 2) {
        cout << "Opcion no valida." << endl;
        return;
    }

    int indiceCuenta = opcionCuenta - 1;

    int criterio;
    cout << "Seleccione el criterio de consulta:" << endl;
    cout << "1. Mes especifico" << endl;
    cout << "2. Anio especifico" << endl;
    cout << "3. Todas las operaciones" << endl;
    cout << "Seleccione una opcion: ";
    cin >> criterio;

    if (criterio == 1) {
        int mes, anio;
        cout << "Ingrese el mes (1-12): ";
        cin >> mes;
        cout << "Ingrese el anio: ";
        cin >> anio;
        cajasDeAhorro[indiceCuenta].mostrarTransaccionesPorMes(mes, anio);
    } else if (criterio == 2) {
        int anio;
        cout << "Ingrese el anio: ";
        cin >> anio;
        cajasDeAhorro[indiceCuenta].mostrarTransaccionesPorAnio(anio);
    } else if (criterio == 3) {
        cajasDeAhorro[indiceCuenta].mostrarTransacciones();
    } else {
        cout << "Criterio no valido." << endl;
    }
}

// Metodo para consultar informacion de las cuentas
void Cliente::consultarCuenta() {
    for (int i = 0; i < 2; ++i) {
        cout << "Cuenta: " << cajasDeAhorro[i].getTipoCuenta() << endl;
        cout << "Saldo: $" << cajasDeAhorro[i].getSaldo() << endl;
        cout << "------------------------" << endl;
    }
}
