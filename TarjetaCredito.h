#ifndef TARJETACREDITO_H
#define TARJETACREDITO_H

#include <string>

class TarjetaCredito {
public:
	TarjetaCredito();
	TarjetaCredito(std::string tipoTarjeta, double limite);
	void mostrarTarjeta();

	// Getters y Setters
	std::string getTipoTarjeta() const;
	void setTipoTarjeta(std::string tipoTarjeta);
	double getLimite() const;
	void setLimite(double limite);

private:
	std::string tipoTarjeta;  // "Credix" o "Premium"
	double limite;
};

#endif // TARJETACREDITO_H
