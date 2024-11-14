#include "Cuenta.h"
#include <iostream>

using namespace std;


//bob el constructor
Cuenta::Cuenta() : saldo(0.0), tipoCuenta("Desconocida"), numTransacciones(0) {}
Cuenta::Cuenta(double saldoInicial, string tipoCuenta)
    : saldo(saldoInicial), tipoCuenta(tipoCuenta), numTransacciones(0) {}


// Métodos de operaciones con transacciones
void Cuenta::depositar(double monto, int dia, int mes, int anio) {
    saldo += monto;
    if (numTransacciones < 100) {
        transacciones[numTransacciones++] = Transaccion("Deposito", monto, dia, mes, anio);
    } else {
        cout << "No se pueden registrar mas transacciones en esta cuenta." << endl;
    }
}

void Cuenta::extraer(double monto, int dia, int mes, int anio) {
    saldo -= monto;  // La verificación de saldo se hace antes
    if (numTransacciones < 100) {
        transacciones[numTransacciones++] = Transaccion("Extraccion", monto, dia, mes, anio);
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
        if (transacciones[i].getMes() == mes && transacciones[i].getAnio() == anio) {
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
        if (transacciones[i].getAnio() == anio) {
            transacciones[i].mostrarTransaccion();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No hay transacciones para ese anio." << endl;
    }
}

string Cuenta::getTipoCuenta()  {
    return tipoCuenta;
}

void Cuenta::setTipoCuenta(string tipoCuenta) {
    this->tipoCuenta = tipoCuenta;
}

double Cuenta::getSaldo()  {
    return saldo;
}

void Cuenta::setSaldo(double saldo) {
    this->saldo = saldo;
}
