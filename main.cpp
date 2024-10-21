#include "Banco.h"
using namespace std;

int main() {
    Banco banco;

    //TODO reemplazar todo ésto por una interfaz de consola en la que pedimos datos al usuario

    Cliente cliente1("12345678", "Juan Perez", "Oro", 2020);
    cliente1.agregarCuenta("Pesos", 10000);
    cliente1.agregarCuenta("Dolares", 5000);
    cliente1.realizarTransaccion("Pesos", "Deposito", 2000, "2024-10-21");
    cliente1.realizarTransaccion("Dolares", "Extraccion", 1000, "2024-10-21");
    banco.agregarCliente(cliente1);

    Cliente cliente2("87654321", "Maria Gomez", "Platino", 2018);
    cliente2.agregarCuenta("Pesos", 15000);
    cliente2.agregarCuenta("Dolares", 10000);
    cliente2.realizarTransaccion("Pesos", "Deposito", 5000, "2024-10-21");
    banco.agregarCliente(cliente2);

    banco.mostrarClientes();

    return 0;
}
