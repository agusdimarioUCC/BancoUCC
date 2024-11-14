#include <string>
using namespace std;

class Transaccion {
private:
	string tipoTransaccion;
	double monto;
	int dia;
	int mes;
	int anio;

public:
	Transaccion();
	Transaccion(string tipo, double monto, int dia, int mes, int anio);
	void mostrarTransaccion();
	string getTipo();
	void setTipoTransaccion(string tipoTransaccion);
	double getMonto() ;
	void setMonto(double monto);
	int getDia() ;
	void setDia(int dia);
	int getMes() ;
	void setMes(int mes);
	int getAnio() ;
	void setAnio(int anio);

};