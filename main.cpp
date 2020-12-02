#include <iostream>
#include "videogame.h"

using namespace std;

void aldeanosEnCiv(Civilizacion *);

int main(){
    Videogame game;
   
    string opc;
    while(true){
        cout << "Menu de opciones" << endl;
        cout << "\t1. Nombre de usuario" << endl;
        cout << "\t2. Agregar civilizacion" << endl;
        cout << "\t3. Insertar civilizacion" << endl;
        cout << "\t4. Crear civilizaciones" << endl;
        cout << "\t5. Primera civilizacion" << endl;
        cout << "\t6. Ultima civilizacion" << endl;
        cout << "\t7. Ordenar" << endl;
        cout << "\t8. Eliminar civilizacion" << endl;
        cout << "\t9. Buscar civilizacion" << endl;
        cout << "\t10. Modificar" << endl;
        cout << "\t11. Resumen" << endl;
        cout << "\t12. Salir" << endl;
        cout << "Ingrese el numero de opcion a realizar: ";
        getline(cin, opc);
        
        if (opc == "1"){
            string cadena;
            cout << "Nombre del usuario: ";
            getline(cin, cadena);
            game.setUsuario(cadena);
            cout << "Usuario " << game.getUsuario() << " registrado" << endl;
        }
        else if (opc == "2")
        {
            Civilizacion civ;
            cin >> civ;
            cin.ignore();
            game.agregar(civ);
        }
        else if (opc == "3")
        {
            Civilizacion civ;

            cin >> civ;
            cin.ignore();

            size_t pos;
            cout << "Posicion: ";
            cin >> pos;
            cin.ignore();

            if (pos >= game.total()) 
            {
                cout << "Poscion invalida " << endl;
            }
            else
            {
                game.insertar(civ, pos);
            }
        }
        else if (opc == "4")
        {
            Civilizacion civ;

            cin >> civ;
            cin.ignore();

            size_t tam;
            cout << "Tamanio: ";
            cin >> tam;
            cin.ignore();
            game.inicializar(civ, tam);
        }
        else if (opc == "5")
        {
            if (game.vacio())
            {
                cout << "El vector esta vacio" << endl;
            }
            else
            {
                game.primera();
            }
        }
        else if (opc == "6")
        {
            if (game.vacio())
            {
                cout << "El vector esta vacio" << endl;
            }
            else
            {
                game.ultima();
            }
        }
        else if (opc == "7")
        {
            cout << "Ordenar por: " << endl;
            cout << "\t1. Nombre" << endl;
            cout << "\t2. Ubicacion en X" << endl;
            cout << "\t3. Ubicacion en Y" << endl;
            cout << "\t4. Puntacion" << endl;
            cout << "Ingrese el numero de la opcion deseada: ";
            getline(cin, opc);
            if (opc == "1")
            {
                game.ordenarNombre();
                cout << "Vector ordenado por nombre" << endl;
            }
            else if (opc == "2")
            {
                game.ordenarX();
                cout << "Vector ordenado por ubicacion en X" << endl;
            }
            else if (opc == "3")
            {
                game.ordenarY();
                cout << "Vector ordenado por ubicacion en Y" << endl;
            }
            else if (opc == "4")
            {
                game.ordenarPuntuacion();
                cout << "Vector ordenado por puntuacion" << endl;
            }
            else
            {
                cout << "Opcion invalida" << endl;
            }
        }
        else if (opc == "8")
        {
            Civilizacion civ;
            string nombre;
            cout << "Ingrese el nombre de la civilizacion a eliminar: ";
            getline(cin, nombre);
            civ.setNombre(nombre);
            game.eliminar(civ);
        }
        else if (opc == "9")
        {
            Civilizacion civ;
            string nombre;
            cout << "Ingrese el nombre de la civilizacion a buscar: ";
            getline(cin, nombre);
            civ.setNombre(nombre);
            Civilizacion *ptr = game.buscar(civ);

            if (ptr == nullptr)
            {
                cout << "Civilizacion no encontrada" << endl;
            }
            else
            {
                aldeanosEnCiv(ptr);
            }
            
        }
        else if (opc == "10")
        {
            Civilizacion civ;
            string aux;
            float auxf;

            cout << "Ingrese el nombre de la civilizacion a modificar: ";
            getline(cin, aux);
            civ.setNombre(aux);
            Civilizacion *ptr = game.buscar(civ);

            if (ptr == nullptr)
            {
                cout << "Civilizacion no encontrada" << endl;
            }
            else
            {
                cout << "Civilizacion encontrado con los siguientes datos " << endl;
                cout << *ptr << endl;
                cout << "Menu de cambios: " << endl;
                cout << "\t1. Nombre" << endl;
                cout << "\t2. Ubicacion en X" << endl;
                cout << "\t3. Ubicacion en Y" << endl;
                cout << "\t4. Puntuacion" << endl;
                cout << "Ingrese el numero que quiere modificar: ";
                getline(cin, opc);
                if (opc == "1")
                {
                    cout << "Ingrese el nuevo nombre: ";
                    getline(cin, aux);
                    ptr->setNombre(aux);
                    cout << "Nombre cambiado con exito" << endl;
                }
                else if (opc == "2")
                {
                    cout << "Ingrese la nueva ubicacion en X: ";
                    cin >> auxf;
                    cin.ignore();
                    ptr->setX(auxf);
                    cout << "Ubicacion en X cambiado con exito" << endl;
                }
                else if (opc == "3")
                {
                    cout << "Ingrese la nueva ubicacion en Y: ";
                    cin >> auxf;
                    cin.ignore();
                    ptr->setY(auxf);
                    cout << "Ubicacion en Y cambiado con exito" << endl;
                }
                else if (opc == "4")
                {
                    cout << "Ingrese la nueva puntuacion: ";
                    cin >> auxf;
                    cin.ignore();
                    ptr->setY(auxf);
                    cout << "Puntuacion cambiada con exito" << endl;
                }
                else
                {
                    cout << "Opcion no valida" << endl;
                }
                cout << "Civilizacion ya modificada: " << endl;
                cout << *ptr << endl;
            }
        }
        else if(opc == "11"){
            if (game.vacio())
            {
                cout << "El vector esta vacio" << endl;
            }
            else
            {
                game.resumen();
            }
        }
        else if (opc == "12")
        {
            system("cls");
            cout << "Hasta luego" << endl;
            break;
        }
        else
        {
            cout << "Opcion no valida " << endl;
        }
    }
    return 0;
}

void aldeanosEnCiv(Civilizacion *civ){
    string opc;
    cout << "Civilizacion encontrado con los siguientes datos " << endl;
    cout << *civ;
    cout << endl << endl;
    while (true)
    {
        cout << "Menu de civilizacion " << civ->getNombre() << endl;
        cout << "\t1. Agregar aldeano" << endl;
        cout << "\t2. Eliminar aldeano" << endl;
        cout << "\t3. Clasificar aldeanos" << endl;
        cout << "\t4. Buscar aldeano" << endl;
        cout << "\t5. Modificar aldeano" << endl;
        cout << "\t6. Mostrar aldeanos" << endl;
        cout << "\t7. Volver al menu principal" << endl;
        cout << "Ingrese el numero de la opcion que quiere realizar: ";
        getline(cin, opc);
        if (opc == "1")
        {
            Aldeano ald;
            cin >> ald;
            cout << endl;
            cin.ignore();
            cout << "Opciones a realizar" << endl;
            cout << "\t1. Agregar al inicio" << endl;
            cout << "\t2. Agregar al final" << endl;
            cout << "Ingrese el numero de la opcion que quiere realizar: ";
            getline(cin, opc);
            if (opc == "1")
            {
                civ->agregarInicio(ald);
                cout << "Aldeano agregado al inicio" << endl;
            }
            else if (opc == "2")
            {
                civ->agregarFinal(ald);
                cout << "Aldeano agregado al final" << endl;
            }
            else
            {
                cout << "Opcion no valida" << endl;
            }
        }
        else if (opc == "2")
        {
            cout << "Opciones a realizar" << endl;
            cout << "\t1. Eliminar por nombre" << endl;
            cout << "\t2. Eliminar por salud" << endl;
            cout << "\t3. Eliminar donde la edad sea mayor igual a 60" << endl;
            cout << "Ingrese el numero de la opcion que quiere realizar: ";
            getline(cin, opc);
            if (opc == "1")
            {
                string aux;
                cout << "Ingrese el nombre del aldeano a eliminar: ";
                getline(cin, aux);
                civ->eliminarNombre(aux);
            }
            else if (opc == "2")
            {
                int auxint;
                cout << "Ingrese la cantidad minima de salud para que no sean borrados: ";
                cin >> auxint;
                cin.ignore();
                civ->eliminarSalud(auxint);
                cout << "Ya no ha aldeanos con salud menor a " << auxint << endl;
            }
            else if (opc == "3")
            {
                civ->eliminarEdad();
                cout << "Ya no ha aldeanos de 60 o mas anios " << endl;
            }
            else
            {
                cout << "Opcion no valida" << endl;
            }
        }
        else if (opc == "3")
        {
            cout << "Opciones a realizar" << endl;
            cout << "\t1. Clasificar la lista de aldeanos por nombre (ascendente)" << endl;
            cout << "\t2. Clasificar la lista de aldeanos por edad (descendente)" << endl;
            cout << "\t3. Ordenar la lista de aldeanos por salud (descendente)" << endl;
            cout << "Ingrese el numero de la opcion que quiere realizar: ";
            getline(cin, opc);
            if (opc == "1")
            {
                civ->ordenarNombre();
                cout << "Aldeanos ordenados por nombre" << endl;
            }
            else if (opc == "2")
            {
                civ->ordenarEdad();
                cout << "Aldeanos ordenados por edad" << endl;
            }
            else if (opc == "3")
            {
                civ->ordenarSalud();
                cout << "Aldeanos ordenados por salud" << endl;
            }
            else
            {
                cout << "Opcion no valida" << endl;
            }
        }
        else if (opc == "4")
        {
            Aldeano ald;
            string nombre;
            cout << "Ingrese el nombre de el aldeano a buscar: ";
            getline(cin, nombre);
            ald.setNombre(nombre);
            Aldeano *ptr = civ->buscar(ald);

            if (ptr == nullptr)
            {
                cout << "Aldeano no encontrado" << endl;
            }
            else
            {
                cout << "Aldeano ecnotrado con la siguiente iformacion" << endl;
                cout << *ptr;
                cout << endl;
            }
        }
        else if (opc == "5")
        {
            Aldeano ald;
            string aux;
            int auxi;

            cout << "Ingrese el nombre de la civilizacion a buscar: ";
            getline(cin, aux);
            ald.setNombre(aux);
            Aldeano *ptr = civ->buscar(ald);

            if (ptr == nullptr)
            {
                cout << "Aldeano no encontrado" << endl;
            }
            else
            {
                cout << "Aldeano encontrado con la siguiente iformacion" << endl;
                cout << *ptr;
                cout << endl <<  "Menu de cambios: " << endl;
                cout << "\t1. Nombre" << endl;
                cout << "\t2. Edad" << endl;
                cout << "\t3. Genero" << endl;
                cout << "\t4. Salud" << endl;
                cout << "Ingrese el numero que quiere modificar: ";
                getline(cin, opc);
                if (opc == "1")
                {
                    cout << "Ingrese el nuevo nombre: ";
                    getline(cin, aux);
                    ptr->setNombre(aux);
                    cout << "Nombre cambiado con exito" << endl;
                }
                else if (opc == "2")
                {
                    cout << "Ingrese la nueva edad: ";
                    cin >> auxi;
                    cin.ignore();
                    ptr->setEdad(auxi);
                    cout << "Edad cambiada con exito" << endl;
                }
                else if (opc == "3")
                {
                    cout << "Ingrese el nuevo genero: ";
                    getline(cin, aux);
                    ptr->setGenero(aux);
                    cout << "Genero cambiado con exito" << endl;
                }
                else if (opc == "4")
                {
                    cout << "Ingrese la nueva salud: ";
                    cin >> auxi;
                    cin.ignore();
                    ptr->setSalud(auxi);
                    cout << "Salud cambiada con exito" << endl;
                }
                else
                {
                    cout << "Opcion no valida" << endl;
                }
                cout << "Civilizacion ya modificada: " << endl;
                cout << *ptr << endl;
            }
        }
        
        else if (opc == "6")
        {
            cout << "Aldeanos de la civilizacion " << civ->getNombre() << endl;
            civ->print();
        }
        else if (opc == "7"){
            break;
        }
        else
        {
            system("cls");
            cout << "Opcion no valida " << endl;
        }
    }
}