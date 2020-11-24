#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>

using namespace std;

class Civilizacion{
private:
    string nombre;
    float ubx;
    float uby;
    float puntuacion;

public:
    Civilizacion();

    void setNombre(const std::string &v);
    void setX(float &v);
    void setY(float &v);
    void setPuntuacion(float &v);

    std::string getNombre();
    float getX();
    float getY();
    float getPuntuacion();

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