#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <vector>
#include <algorithm>

class Videogame{
    private:
        std::string usuario;
        vector<Civilizacion> civilizaciones;
    public:
        Videogame();

        void setUsuario(const std::string &v);
        std::string getUsuario();

        void agregar(const Civilizacion &c);
        size_t total();
        void insertar(const Civilizacion &c, size_t pos);
        void inicializar(const Civilizacion &c, size_t tam);
        void resumen();

        bool vacio();
        void primera();
        void ultima();

        void eliminar(const Civilizacion &c);
        void ordenarNombre();
        void ordenarX();
        void ordenarY();
        void ordenarPuntuacion();

        Civilizacion* buscar(const Civilizacion &c);

        friend Videogame &operator<<(Videogame &v, const Civilizacion &c)
        {
            v.agregar(c);

            return v;
        }
};


#endif