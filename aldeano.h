#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <iomanip>
using namespace std;

class Aldeano{
private:
    std::string nombre;
    int edad;
    std::string genero;
    int salud;

    

public:
    Aldeano();
    Aldeano(const std::string &nombre, int edad, const std::string &genero, int salud);

    void setNombre(const std::string &v);
    void setEdad(int &v);
    void setGenero(const std::string &v);
    void setSalud(int &v);

    std::string getNombre() const;
    int getEdad() const;
    std::string getGenero();
    int getSalud() const;

    friend ostream &operator<<(ostream &out, const Aldeano &a)
    {
        out << left;
        out << setw(15) << a.nombre;
        out << setw(8) << a.edad;
        out << setw(15) << a.genero;
        out << setw(8) << a.salud;
        return out;
    }

    friend istream &operator>>(istream &in, Aldeano &a)
    {
        cout << "Nombre: ";
        getline(cin, a.nombre);
        cout << "Edad: ";
        cin >> a.edad;
        cin.ignore();
        cout << "Genero: ";
        getline(cin, a.genero);
        cout << "Salud: ";
        cin >> a.salud;

        return in;
    }

    bool operator<(const Aldeano &a)
    {
        return nombre < a.getNombre();
    }
    bool operator==(const Aldeano &a)
    {
        return nombre == a.nombre;
    }
    bool operator==(const Aldeano &a) const
    {
        return nombre == a.nombre;
    }
};

#endif