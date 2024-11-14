#include <iostream>
#include "Cliente.h"

using namespace std;

Cliente::Cliente() : dni(0), nombre(""), tipoCliente(""), anioIngreso(0), activo(true), tarjeta()
{
}

Cliente::Cliente(int dni, string nombre, string tipoCliente, int anioIngreso)
    : dni(dni), nombre(nombre), tipoCliente(tipoCliente), anioIngreso(anioIngreso), activo(true), tarjeta()
{
    // Inicializar las cuentas de ahorro en pesos y dolares
    cajasDeAhorro[0] = Cuenta(0.0, "Pesos");
    cajasDeAhorro[1] = Cuenta(0.0, "Dolares");
    asignarTarjetaCredito();
}

int Cliente::getDni()
{
    return dni;
}

void Cliente::setDni(int dni)
{
    this->dni = dni;
}

string Cliente::getNombre()
{
    return nombre;
}

void Cliente::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Cliente::getTipoCliente()
{
    return tipoCliente;
}

void Cliente::setTipoCliente(string tipoCliente)
{
    this->tipoCliente = tipoCliente;
}

int Cliente::getAnioIngreso()
{
    return anioIngreso;
}

void Cliente::setAnioIngreso(int anioIngreso)
{
    this->anioIngreso = anioIngreso;
}

bool Cliente::isActivo()
{
    return activo;
}

void Cliente::setActivo(bool activo)
{
    this->activo = activo;
}

void Cliente::realizarTransaccion()
{
    int opcionCuenta;
    cout << "Seleccione la cuenta:" << endl;
    cout << "1. Caja de Ahorro en Pesos" << endl;
    cout << "2. Caja de Ahorro en Dolares" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcionCuenta;

    if (opcionCuenta != 1 && opcionCuenta != 2)
    {
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

    if (monto <= 0)
    {
        cout << "El monto debe ser positivo." << endl;
        return;
    }

    // Obtener fecha
    int dia, mes, anio;
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el mes: ";
    cin >> mes;
    cout << "Ingrese el anio: ";
    cin >> anio;

    if (opcionTransaccion == 1)
    {
        cajasDeAhorro[indiceCuenta].depositar(monto, dia, mes, anio);
        cout << "Deposito realizado exitosamente." << endl;
    }
    else if (opcionTransaccion == 2)
    {
        if (cajasDeAhorro[indiceCuenta].getSaldo() >= monto)
        {
            cajasDeAhorro[indiceCuenta].extraer(monto, dia, mes, anio);
            cout << "Extraccion realizada exitosamente." << endl;
        }
        else
        {
            cout << "Saldo insuficiente para realizar la extraccion." << endl;
        }
    }
    else
    {
        cout << "Opcion de transaccion no valida." << endl;
    }
}

void Cliente::consultarTransacciones()
{
    int opcionCuenta;
    cout << "Seleccione la cuenta:" << endl;
    cout << "1. Caja de Ahorro en Pesos" << endl;
    cout << "2. Caja de Ahorro en Dólares" << endl;
    cout << "Seleccione una opción: ";
    cin >> opcionCuenta;

    if (opcionCuenta != 1 && opcionCuenta != 2)
    {
        cout << "Opción no válida." << endl;
        return;
    }

    Cuenta cuenta = cajasDeAhorro[opcionCuenta - 1];

    int criterio;
    cout << "Seleccione el criterio de consulta:\n";
    cout << "1. Mes específico\n";
    cout << "2. Anio especifico\n";
    cout << "3. Todas las operaciones\n";
    cout << "Seleccione una opcion: ";
    cin >> criterio;

    if (criterio == 1)
    {
        int mes, anio;
        cout << "Ingrese el mes (1-12): ";
        cin >> mes;
        cout << "Ingrese el anio: ";
        cin >> anio;
        cuenta.mostrarTransaccionesPorMes(mes, anio);
    }
    else if (criterio == 2)
    {
        int anio;
        cout << "Ingrese el año: ";
        cin >> anio;
        cuenta.mostrarTransaccionesPorAnio(anio);
    }
    else if (criterio == 3)
    {
        cuenta.mostrarTransacciones();
    }
    else
    {
        cout << "Criterio no valido.\n";
    }
}

void Cliente::consultarCuenta()
{
    for (int i = 0; i < 2; ++i)
    {
        Cuenta cuenta = cajasDeAhorro[i];
        cout << "Cuenta: " << cuenta.getTipoCuenta() << endl;
        cout << "Saldo: $" << cuenta.getSaldo() << endl;
        cout << "------------------------" << endl;
        //mostrartarjeta no deberia estar aca?
    }
}

void Cliente::asignarTarjetaCredito()
{
    if (tipoCliente == "ORO")
    {
        tarjeta = TarjetaCredito("Credix", 250000.0);
    }
    else if (tipoCliente == "PLATINO")
    {
        tarjeta = TarjetaCredito("Premium", 500000.0);
    }
    else
    {
        tarjeta = TarjetaCredito(); // "Ninguna" y límite 0
    }
}

void Cliente::mostrarTarjetaCredito()
{
    cout << "Tarjeta de Credito:" << endl;
    tarjeta.mostrarTarjeta();
    cout << "------------------------" << endl;
}
