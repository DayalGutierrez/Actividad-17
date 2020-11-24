#include "videogame.h"

using namespace std;

Videogame::Videogame() { }

void Videogame::setUsuario(const string &v){
    usuario = v;
}

string Videogame::getUsuario()
{
    return usuario;
}

void Videogame::agregar(const Civilizacion &c){
    civilizaciones.push_back(c);
}

size_t Videogame::total(){
    return civilizaciones.size();
}

void Videogame::insertar(const Civilizacion &c, size_t pos){
    civilizaciones.insert(civilizaciones.begin() + pos, c);
}

void Videogame::inicializar(const Civilizacion &c, size_t tam){
    civilizaciones = vector<Civilizacion>(tam,c);
}

void Videogame::resumen()
{
    cout << "*****Civilizaciones de " << usuario << "*****" << endl;
    cout << left;
    cout << setw(15) << "Nombre";
    cout << setw(8) << "X";
    cout << setw(8) << "Y";
    cout << setw(15) << "Puntuacion" << endl;
    for (size_t i = 0; i < civilizaciones.size(); i++)
    {
        cout << civilizaciones[i] << endl;
    }
}

bool Videogame::vacio(){
    return civilizaciones.empty();
}

void Videogame::primera(){
    cout << civilizaciones.front() << endl;
}

void Videogame::ultima()
{
    cout << civilizaciones.back() << endl;
}

void Videogame::eliminar(const Civilizacion &c)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if (it == civilizaciones.end())
    {
        cout << "Civilizacion no encontrada" << endl;
        return;
    }
    else
    {
        civilizaciones.erase(it);
        cout << "Civilizacion eliminada" << endl;
        return;
    }
}

void Videogame::ordenarNombre(){
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getNombre() > c2.getNombre(); });
}
void Videogame::ordenarX()
{
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getX() > c2.getX(); });
}
void Videogame::ordenarY()
{
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getY() > c2.getY(); });
}
void Videogame::ordenarPuntuacion()
{
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getPuntuacion() > c2.getPuntuacion(); });
}

Civilizacion *Videogame::buscar(const Civilizacion &c){
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if (it == civilizaciones.end())
    {
        return nullptr;
    }
    else
    {
        return &(*it);
    }
    
    
}
