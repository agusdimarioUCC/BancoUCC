#include "Transaccion.h"
#include <iostream>
using namespace std;

Transaccion::Transaccion() {}

Transaccion::Transaccion(string t, double m, string f) : tipo(t), monto(m), fecha(f) {}

void Transaccion::mostrar() {
	cout << tipo << " de $" << monto << " en fecha " << fecha << endl;
}
