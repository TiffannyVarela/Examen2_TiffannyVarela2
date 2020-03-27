#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include "Tupla.h"
#include "Relacion.h"
using namespace std;

int menu();

void CrearRelacion();
vecttor <Relacion*> relaciones;

int main(int argc, char const *argv[])
{
	int resp =0;
	int opc =0;

	do{//inicio do while

		switch(opc=menu()){//inicio switch

			case 1://inicio case 1
				CrearRelacion();
				break;//fin case 1

			case 2://inicio case 2
				break;//fin case 2

			case 3://inicio case 3
				break;//fin case 3

		}//fin switch

		cout<<"Desea continuar?\n 1.Si\n 2.No\n:";
		cin>>resp;
	}while(resp!=2);//fin do while
	cout<<"Programa Terminado"<<endl;
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

void CrearRelacion(){
	Relacion* relacion;
	string nombre;
	string encabezado;
	int resp;
	int cont=0;
	cout<<"Ingrese el Nombre de la Relacion: ";
	cin>> nombre;
	relacion = new Relacion(nombre);
	while(resp!=2){
		cout<<"Ingrese el Encabezado "<<cont<<" : ";
		cin>> encabezado;
		relacion->addList_encabezados(encabezado);
		cont++;
		cout<<"Desea continuar?\n 1.Si\n 2.No\n:";
		cin>>resp;
	}

	relaciones.push_back(relacion);
}