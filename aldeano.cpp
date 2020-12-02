#include "aldeano.h"


Aldeano::Aldeano() { }

Aldeano::Aldeano(const string &nombre, int edad, const string &genero, int salud) : nombre(nombre), edad(edad), genero(genero), salud(salud) {}

void Aldeano::setNombre(const string &v)
{
    nombre = v;
}

void Aldeano::setEdad(int &v) 
{
    edad = v;
}

void Aldeano::setGenero(const string &v)
{
    genero = v;
}

void Aldeano::setSalud(int& v){
    salud = v;
}

string Aldeano::getNombre() const
{
    return nombre;
}

int Aldeano::getEdad() const
{
    return edad;
}

string Aldeano::getGenero()
{
    return genero;
}

int Aldeano::getSalud() const
{
    return salud;
}