#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include "Tupla.h"
#include "Relacion.h"
using namespace std;

int menu();

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

int menu()
{
    while (true)
    {
        cout << "MENU" << endl
             << "1.- Crear Relacion" << endl
             << "2.- Ver Relaciones" << endl
             << "3.- Insertar Tupla" << endl;
        cout << "Ingrese una opcion: ";
        int opcion = 0;
        cin >> opcion;
        if (opcion >= 1 && opcion <= 3)
        {
            return opcion;
        }
        else
        {

            cout << "La opcion elegida no es valida, ingrese 1 o 3" << endl;
        }
    } //end del while
    return 0;
}