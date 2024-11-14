#include <string>
using namespace std;

class TarjetaCredito {
private:
	string tipoTarjeta;  // "Credix" o "Premium"
	double limite;
public:
	TarjetaCredito();
	TarjetaCredito(string tipoTarjeta, double limite);
	void mostrarTarjeta();

	// Getters y Setters
	string getTipoTarjeta() ;
	void setTipoTarjeta(string tipoTarjeta);
	double getLimite() ;
	void setLimite(double limite);
};
