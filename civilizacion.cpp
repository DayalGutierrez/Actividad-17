#include "civilizacion.h"


Civilizacion::Civilizacion() { }

Civilizacion::Civilizacion(const std::string &nombre, float &ubx, float &uby, float &puntuacion) : nombre(nombre), ubx(ubx), uby(uby), puntuacion(puntuacion) { }

void Civilizacion::setNombre(const string &v)
{
    nombre = v;
}

void Civilizacion::setX(float &v){
    ubx = v;
}


void Civilizacion::setY(float &v){
    uby = v;
}

void Civilizacion::setPuntuacion(float &v){
    puntuacion = v;
}

string Civilizacion::getNombre(){
    return nombre;
}

float Civilizacion::getX(){
    return ubx;
}

float Civilizacion::getY(){
    return uby;
}

float Civilizacion::getPuntuacion(){
    return puntuacion;
}

//métedos de la lista 
void Civilizacion::agregarFinal(const Aldeano& a){
    aldeanos.push_back(a);
}

void Civilizacion::agregarInicio(const Aldeano& a){
    aldeanos.push_front(a);
}

void Civilizacion::print(){
    cout << left;
    cout << setw(15) <<"Nombre";
    cout << setw(8) << "Edad";
    cout << setw(15) << "Genero";
    cout << setw(8) << "Salud" << endl;
    
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        cout << *it << endl;
    }
}

void Civilizacion::eliminarNombre(const string &nombre){
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;

        if (nombre == a.getNombre())
        {
            aldeanos.erase(it);
            break;
        }
        
    }
}

void Civilizacion::eliminarSalud(int &salud){
    aldeanos.remove_if([salud](const Aldeano &a) { return a.getSalud() < salud; } );
}

bool comparaEdad(const Aldeano &a)
{
    return a.getEdad() >= 60 ;
}
void Civilizacion::eliminarEdad()
{
    aldeanos.remove_if(comparaEdad);
}

void Civilizacion::ordenarNombre(){
    aldeanos.sort();
}

void Civilizacion::ordenarEdad()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2) { return a1.getEdad() > a2.getEdad(); });
}

void Civilizacion::ordenarSalud()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2) { return a1.getSalud() > a2.getSalud(); });
}

Aldeano * Civilizacion::buscar(const Aldeano &a){
    auto it = find(aldeanos.begin(), aldeanos.end(), a);

    if (it == aldeanos.end())
    {
        return nullptr;
    }
    else
    {
        return &(*it);
    }
}

void Civilizacion::respaldar_aldeanos(){
    ofstream archivo(getNombre() + ".txt", ios::out);
    for (auto it = aldeanos.begin(); it != aldeanos.end(); ++it)
    {
        Aldeano &aldeano = *it;
        archivo << aldeano.getNombre() << endl;
        archivo << aldeano.getEdad() << endl;
        archivo << aldeano.getGenero() << endl;
        archivo << aldeano.getSalud() << endl;
    }
    archivo.close();
}

void Civilizacion::recuperar_aldeanos(){
    ifstream archivo(getNombre() + ".txt", ios::out);
    if (archivo.is_open())
    {
        string auxs;
        int auxi;
        Aldeano alde;

        while (true)
        {
            getline(archivo, auxs);
            if (archivo.eof())
            {
                break;
            }

            alde.setNombre(auxs);

            getline(archivo, auxs);
            auxi = stoi(auxs);
            alde.setEdad(auxi);

            getline(archivo, auxs);
            alde.setGenero(auxs);

            getline(archivo, auxs);
            auxi = stoi(auxs);
            alde.setSalud(auxi);

            agregarFinal(alde);
        }
        
    }
    archivo.close();
}