#include "Banco.h"
#include <iostream>
using namespace std;

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
