#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include "aldeano.h"

#include <iostream>
#include <iomanip>
#include <list>
#include <algorithm>


class Civilizacion{
private:
    std::string nombre;
    float ubx;
    float uby;
    float puntuacion;
    list<Aldeano> aldeanos;

public:
    Civilizacion();
    Civilizacion(const std::string &nombre, float &ubx, float &uby, float &puntuacion);

    void setNombre(const std::string &v);
    void setX(float &v);
    void setY(float &v);
    void setPuntuacion(float &v);

    std::string getNombre();
    float getX();
    float getY();
    float getPuntuacion();

    //Metodos de la lista
    void agregarFinal(const Aldeano &a);
    void agregarInicio(const Aldeano &a);

    void print();

    void eliminarNombre(const std::string &nombre);
    void eliminarSalud(int &salud);
    void eliminarEdad();

    void ordenarNombre();
    void ordenarEdad();
    void ordenarSalud();

    Aldeano *buscar(const Aldeano &a);

    //fin metodos de la lista

    bool operator ==(const Civilizacion & c){
        return nombre == c.nombre;
    }
    bool operator==(const Civilizacion &c) const
    {
        return nombre == c.nombre;
    }

    bool operator<(const Civilizacion &c){
        return nombre < c.nombre;
    }
    bool operator<(const Civilizacion &c) const
    {
        return nombre < c.nombre;
    }

    friend ostream &operator<<(ostream &out, const Civilizacion &c){
        out << left;
        out << setw(15) << c.nombre;
        out << setw(8) << c.ubx;
        out << setw(8) << c.uby;
        out << setw(15) << c.puntuacion;
        return out;
    }

    friend istream &operator>>(istream &in, Civilizacion &c){
        cout << "Nombre: ";
        getline(cin, c.nombre);
        cout << "Ubicacion en X: ";
        cin >> c.ubx;
        cout << "Ubicacion en Y: ";
        cin >> c.uby;
        cout << "Puntuacion: ";
        cin >> c.puntuacion;

        return in;
    }
};


#endif