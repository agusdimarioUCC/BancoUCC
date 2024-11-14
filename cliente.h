#include <string>
#include "Cuenta.h"
#include "TarjetaCredito.h"
using namespace std;
class Cliente {
public:
	Cliente();
	Cliente(int dni, string nombre, string tipoCliente, int anioIngreso);
	void realizarTransaccion();
	void consultarTransacciones();
	void consultarCuenta();
	void asignarTarjetaCredito();
	void mostrarTarjetaCredito();
	int getDni() ;
	void setDni(int dni);
	string getNombre() ;
	void setNombre(string nombre);
	string getTipoCliente() ;
	void setTipoCliente(string tipoCliente);
	int getAnioIngreso() ;
	void setAnioIngreso(int anioIngreso);
	bool isActivo() ;
	void setActivo(bool activo);

private:
	int dni;
	string nombre;
	string tipoCliente;
	int anioIngreso;
	bool activo;
	Cuenta cajasDeAhorro[2];  // en pesos y en dolares
	TarjetaCredito tarjeta;
};
