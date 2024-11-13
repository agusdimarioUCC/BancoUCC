#include "Cuenta.h"
#include <iostream>

using namespace std;

// Constructor por defecto
Cuenta::Cuenta() : saldo(0.0), tipoCuenta("Desconocida"), numTransacciones(0) {}

// Constructor con parametros
Cuenta::Cuenta(double saldoInicial, string tipoCuenta)
    : saldo(saldoInicial), tipoCuenta(tipoCuenta), numTransacciones(0) {}

// Metodos de operaciones con transacciones
void Cuenta::depositar(double monto, string fecha) {
    saldo += monto;
    if (numTransacciones < 100) {
        transacciones[numTransacciones++] = Transaccion("Deposito", monto, fecha);
    } else {
        cout << "No se pueden registrar mas transacciones en esta cuenta." << endl;
    }
}

void Cuenta::extraer(double monto, string fecha) {
    saldo -= monto;  // La verificacion de saldo se hace antes
    if (numTransacciones < 100) {
        transacciones[numTransacciones++] = Transaccion("Extraccion", monto, fecha);
    } else {
        cout << "No se pueden registrar mas transacciones en esta cuenta." << endl;
    }
}

void Cuenta::mostrarTransacciones() {
    if (numTransacciones == 0) {
        cout << "No hay transacciones registradas." << endl;
        return;
    }
    for (int i = 0; i < numTransacciones; ++i) {
        transacciones[i].mostrarTransaccion();
    }
}

void Cuenta::mostrarTransaccionesPorMes(int mes, int anio) {
    bool encontrado = false;
    for (int i = 0; i < numTransacciones; ++i) {
        int transMes = transacciones[i].getMes();
        int transAnio = transacciones[i].getAnio();
        if (transMes == mes && transAnio == anio) {
            transacciones[i].mostrarTransaccion();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No hay transacciones para ese mes y anio." << endl;
    }
}

void Cuenta::mostrarTransaccionesPorAnio(int anio) {
    bool encontrado = false;
    for (int i = 0; i < numTransacciones; ++i) {
        int transAnio = transacciones[i].getAnio();
        if (transAnio == anio) {
            transacciones[i].mostrarTransaccion();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No hay transacciones para ese anio." << endl;
    }
}

// Getters y Setters
string Cuenta::getTipoCuenta() const {
    return tipoCuenta;
}

void Cuenta::setTipoCuenta(const string &tipoCuenta) {
    this->tipoCuenta = tipoCuenta;
}

double Cuenta::getSaldo() const {
    return saldo;
}

void Cuenta::setSaldo(double saldo) {
    this->saldo = saldo;
}
