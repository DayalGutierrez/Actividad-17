#include "civilizacion.h"


Civilizacion::Civilizacion() { } 

void Civilizacion::setNombre(const string &v){
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