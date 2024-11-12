#include <iostream>
using namespace std;
class persona
{
private:
    long dni;
    string nombre;

public:
    persona();
    persona(long _dni, string _nombre);
    void setdni(long _dni);
    long getdni();
    void setnombre(string _nombre);
    string getnombre();
};

class cliente : public persona
{
private:
    string tipo;
    int anio;
    string estado;
    long pesos;
    long dolares;

public:
    cliente();
    cliente(long _dni, string _nombre, string _tipo, int _anio, string _estado, long _pesos, long _dolares);
    void settipo(string _tipo);
    string gettipo();
    void setanio(int _anio);
    int getanio();
    void setestado(string _estado);
    string getestado();
    void setpesos(long _pesos);
    long getpesos();
    void setdolares(long _dolares);
    long getdolares();
    void depositopesos(float _ingreso);
    void depositodolares(float _ingreso);
    void estraccionpesos(float _retiro);
    void estracciondolares(float _retiro);
};

class empleado : public persona
{
public:
    empleado();
    empleado(long _dni, string _nombre);
};
