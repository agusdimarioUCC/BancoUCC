#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Transaccion {
public:
    string tipo;
    double monto;
    string fecha;

    Transaccion() {}

    Transaccion(string t, double m, string f) : tipo(t), monto(m), fecha(f) {}

    void mostrar() {
        cout << tipo << " de $" << monto << " en fecha " << fecha << endl;
    }
};

class Cuenta {
public:
    string tipoCuenta;
    double saldo;
    Transaccion transacciones[100];  // Máximo de 100 transacciones
    int numTransacciones;

    Cuenta() {
        saldo = 0.0;
        numTransacciones = 0;
    }

    Cuenta(string tipo, double saldoInicial) : tipoCuenta(tipo), saldo(saldoInicial) {
        numTransacciones = 0;
    }

    void realizarTransaccion(string tipo, double monto, string fecha) {
        Transaccion nuevaTransaccion(tipo, monto, fecha);
        transacciones[numTransacciones] = nuevaTransaccion;
        numTransacciones++;

        if (tipo == "Deposito") {
            saldo += monto;
        } else if (tipo == "Extraccion") {
            saldo -= monto;
        }
    }

    void mostrarTransacciones() {
        for (int i = 0; i < numTransacciones; i++) {
            transacciones[i].mostrar();
        }
    }
};

class Cliente {
public:
    string dni;
    string nombre;
    string tipoCliente;
    int anioIngreso;
    string estado;
    Cuenta cuentas[2];  // 0: Caja de Ahorro en Pesos, 1: Caja de Ahorro en Dólares
    double limiteCredito;

    Cliente() {}

    Cliente(string d, string n, string tipo, int anio) : dni(d), nombre(n), tipoCliente(tipo), anioIngreso(anio), estado("ACTIVO") {
        if (tipoCliente == "Oro") {
            limiteCredito = 250000;
        } else if (tipoCliente == "Platino") {
            limiteCredito = 500000;
        } else {
            limiteCredito = 0;  
        }
    }

    void agregarCuenta(string tipoCuenta, double saldoInicial) {
        if (tipoCuenta == "Pesos") {
            cuentas[0] = Cuenta("Caja de Ahorro en Pesos", saldoInicial);
        } else if (tipoCuenta == "Dolares") {
            cuentas[1] = Cuenta("Caja de Ahorro en Dólares", saldoInicial);
        }
    }

    void realizarTransaccion(string tipoCuenta, string tipoTransaccion, double monto, string fecha) {
        if (tipoCuenta == "Pesos") {
            cuentas[0].realizarTransaccion(tipoTransaccion, monto, fecha);
        } else if (tipoCuenta == "Dolares") {
            cuentas[1].realizarTransaccion(tipoTransaccion, monto, fecha);
        }
    }

    void mostrarInfo() {
        cout << "Cliente: " << nombre << " (" << dni << ") - Tipo: " << tipoCliente << " - Estado: " << estado << endl;
        cout << "Cuenta Pesos con saldo $" << cuentas[0].saldo << endl;
        cuentas[0].mostrarTransacciones();
        cout << "Cuenta Dólares con saldo $" << cuentas[1].saldo << endl;
        cuentas[1].mostrarTransacciones();
    }

    void cambiarEstado(string nuevoEstado) {
        estado = nuevoEstado;
    }
};

class Banco {
public:
    Cliente clientes[100];  // Máximo 100 clientes
    int numClientes;

    Banco() {
        numClientes = 0;
    }

    void agregarCliente(Cliente cliente) {
        clientes[numClientes] = cliente;
        numClientes++;
    }

    void mostrarClientes() {
        for (int i = 0; i < numClientes; i++) {
            clientes[i].mostrarInfo();
        }
    }

    Cliente* buscarClientePorDNI(string dni) {
        for (int i = 0; i < numClientes; i++) {
            if (clientes[i].dni == dni) {
                return &clientes[i];
            }
        }
        return nullptr;
    }

    void guardarClientesEnArchivo() {
        ofstream archivo("clientes.txt");
        for (int i = 0; i < numClientes; i++) {
            archivo << clientes[i].dni << "," << clientes[i].nombre << "," 
                    << clientes[i].tipoCliente << "," << clientes[i].anioIngreso 
                    << "," << clientes[i].estado << endl;
        }
        archivo.close();
    }

    void cargarClientesDesdeArchivo() {
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
};

int main() {
    Banco banco;

    // Agregar cliente
    Cliente cliente1("12345678", "Juan Perez", "Oro", 2020);
    cliente1.agregarCuenta("Pesos", 10000);
    cliente1.agregarCuenta("Dolares", 5000);
    cliente1.realizarTransaccion("Pesos", "Deposito", 2000, "2024-10-21");
    cliente1.realizarTransaccion("Dolares", "Extraccion", 1000, "2024-10-21");
    banco.agregarCliente(cliente1);

    // Agregar otro cliente
    Cliente cliente2("87654321", "Maria Gomez", "Platino", 2018);
    cliente2.agregarCuenta("Pesos", 15000);
    cliente2.agregarCuenta("Dolares", 10000);
    cliente2.realizarTransaccion("Pesos", "Deposito", 5000, "2024-10-21");
    banco.agregarCliente(cliente2);

    // Mostrar información de clientes
    banco.mostrarClientes();

    return 0;
}
