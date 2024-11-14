#include <string>
using namespace std;

class TarjetaCredito {
private:
	string tipoTarjeta;
	double limite;
public:
	TarjetaCredito();
	TarjetaCredito(string tipoTarjeta, double limite);
	void mostrarTarjeta();
	string getTipoTarjeta() ;
	void setTipoTarjeta(string tipoTarjeta);
	double getLimite() ;
	void setLimite(double limite);
};
