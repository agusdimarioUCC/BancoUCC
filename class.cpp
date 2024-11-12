#include <iostream>
#include "class.h"
using namespace std;

persona::persona() {}

persona::persona(long _dni, string _nombre)
{
    dni = _dni;
    nombre = _nombre;
}
void persona::setdni(long _dni)
{
    dni = _dni;
}
long persona::getdni()
{
    return dni;
}
void persona::setnombre(string _nombre)
{
    nombre = _nombre;
}
string persona::getnombre()
{
    return nombre;
}

cliente::cliente() {}

cliente::cliente(long _dni, string _nombre, string _tipo, int _anio, string _estado, long _pesos, long _dolares)
{
    tipo = _tipo;
    anio = _anio;
    estado = _estado;
    pesos = _pesos;
    dolares = _dolares;
}

void cliente::settipo(string _tipo)
{
    tipo = _tipo;
}
string cliente::gettipo()
{
    return tipo;
}
void cliente::setanio(int _anio)
{
    anio = _anio;
}
int cliente::getanio()
{
    return anio;
}
void cliente::setestado(string _estado)
{
    estado = _estado;
}
string cliente::getestado()
{
    return estado;
}
void cliente::setpesos(long _pesos)
{
    pesos = _pesos;
}
long cliente::getpesos()
{
    return pesos;
}
void cliente::setdolares(long _dolares)
{
    dolares = _dolares;
}
long cliente::getdolares()
{
    return dolares;
}
void cliente::depositopesos(float _ingreso)
{
    pesos = pesos + _ingreso;
}
void cliente::depositodolares(float _ingreso)
{
    dolares = dolares + _ingreso;
}
void cliente::estraccionpesos(float _retiro)
{
    if (_retiro < pesos)
    {
        pesos = pesos - _retiro;
        cout << "El nuevo saldo es: " << pesos << endl;
    }
    else
    {
        cout << "No es posible extraer el importe ingresado" << endl;
    }
}
void cliente::estracciondolares(float _retiro)
{
    if (_retiro < dolares)
    {
        dolares = dolares - _retiro;
        cout << "El nuevo saldo es: " << dolares << endl;
    }
    else
    {
        cout << "No es posible extraer el importe ingresado" << endl;
    }
}

empleado::empleado(){}
empleado::empleado(long _dni, string _nombre){
}