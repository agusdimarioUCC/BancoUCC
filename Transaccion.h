#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>
using namespace std;

class Transaccion {
public:
	string tipo;
	double monto;
	string fecha;

	Transaccion();
	Transaccion(string t, double m, string f);
	void mostrar();
};

#endif
