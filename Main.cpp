#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include "Tupla.h"
#include "Relacion.h"
#include <fstream>
#include <iomanip>
#include<stdlib.h>
#include<time.h>
using namespace std;

int menu();

void CrearRelacion();
Relacion* relacion;
vector <Relacion*> relaciones;
string ruta = "Relaciones/";
ofstream outfile;

void VerRelaciones();

void InsertarTupla();
Tupla* tupla;

int main(int argc, char const *argv[])
{
	int resp =0;
	int opc =0;
	string cadena;
	ifstream leer("Relaciones.txt");
	while(!leer.eof()){
		leer>>cadena;
		cout<<"Cadena "<<cadena<<endl;
	}
	leer.close();

	do{//inicio do while

		switch(opc=menu()){//inicio switch

			case 1://inicio case 1
				CrearRelacion();
				break;//fin case 1

			case 2://inicio case 2
				VerRelaciones();
				break;//fin case 2

			case 3://inicio case 3
				InsertarTupla();
				break;//fin case 3

		}//fin switch

		cout<<"Desea continuar dentro del programa?\n 1.Si\n 2.No\n:";
		cin>>resp;
	}while(resp!=2);//fin do while
	
	for (int i = 0; i < relaciones.size(); i++)
    {
        delete relaciones[i];
        relaciones[i] = NULL;
    }
    relaciones.clear();
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
	string nombre;
	string encabezado;
	string nombreArchivo = "Relaciones";
	int resp;
	int cont=1;
	cout<<"Ingrese el Nombre de la Relacion: ";
	cin>> nombre;
	relacion = new Relacion(nombre);
	relacion->addList_encabezados("ID");
	while(resp!=2){
		cout<<"Ingrese el Encabezado "<<cont<<" : ";
		cin>> encabezado;
		relacion->addList_encabezados(encabezado);
		cont++;
		cout<<"Desea continuar ingresando encabezados?\n 1.Si\n 2.No\n:";
		cin>>resp;
	}
	outfile.open(nombreArchivo+".txt", std::ios::app);
	outfile<<nombre<<";";
	for (int i = 0; i < relacion->getList_encabezados().size(); i++)
    {
    	outfile<<relacion->getEncabezado(i);
    	if (i<relacion->getList_encabezados().size()-1)
    	{
    		outfile<<",";
    	}
    }
    outfile<<endl;
	outfile.close();
	relaciones.push_back(relacion);
}

void VerRelaciones(){
	int pos;
	cout<<"RELACIONES DISPONIBLES\n\n";

	for (int i = 0; i < relaciones.size(); i++)
	{
		cout<<"Posicion "<<i<<" : "<<relaciones[i]->getNombre()<<endl;
	}
	cout<<"\nIngrese la Posicion que Desea Ver: ";
	cin>>pos;

	while(pos<0 || pos>relaciones.size()-1){
		cout<<"POSICION NO VALIDA"<<endl;
		cout<<"Ingrese la Posicion que Desea Ver: ";
		cin>>pos;
	}

	cout<<relaciones[pos]->getNombre()<<endl<<endl;
	int tam = relaciones[pos]->getList_encabezados().size();
	for (int i = 0; i < tam; i++)
	{
		cout<<relaciones[pos]->getEncabezado(i)<<setw(12);
	}
	cout<<endl;


	for (int i = 0; i < relaciones[pos]->getList_tuplas().size(); i++)
	{
		for (int j = 0; j < relaciones[pos]->getList_tuplas().size(); j++)
		{
			if (i==0)
			{
				cout<<relaciones[pos]->getTupla(i)->getId()<<setw(12);
			}
			else{
				cout<<relaciones[pos]->getTupla(i)->getAtributo(j)<<setw(12);
			}
		}
		cout<<endl;
	}
}


void InsertarTupla(){
	int pos;
	int id;
	string atri;
	srand(time(NULL));
	cout<<"RELACIONES DISPONIBLES\n\n";

	for (int i = 0; i < relaciones.size(); i++)
	{
		cout<<"Posicion "<<i<<" : "<<relaciones[i]->getNombre()<<endl;
	}

	cout<<"Ingrese la Posicion de la Relacion en la Cual Quiera Insertar: ";
	cin>>pos;

	while(pos<0 || pos>relaciones.size()-1){
		cout<<"POSICION NO VALIDA"<<endl;
		cout<<"Ingrese la Posicion de la Relacion en la Cual Quiera Insertar: ";
		cin>>pos;
	}
	id = 1000+rand()%(10000-1000);
	tupla = new Tupla(id);
	for (int i = 1; i < relaciones[pos]->getList_encabezados().size(); i++)
	{
		cout<<"Inserte "<<relaciones[pos]->getEncabezado(i)<<": "<<endl;
		cin>>atri;
		tupla->addList_atributos(atri);
	}
	relaciones[pos]->addList_tuplas(tupla);

	ofstream outfile2;
	string nombre = relaciones[pos]->getNombre();

	outfile2.open(ruta + nombre + ".txt");
	if (!relaciones[pos]->getList_tuplas().empty())
    {
    	for (int i = 0; i < relaciones[pos]->getList_tuplas().size(); i++)
    	{
			for (int j = 0; j < relaciones[pos]->getTupla(i)->getList_atributos().size(); j++)
			{
				outfile2<<relaciones[pos]->getTupla(i)->getAtributo(j);
				if (j<relaciones[pos]->getTupla(i)->getList_atributos().size()-1)
		    	{
		    		outfile2<<";";
		    	}
			}
			outfile2<<endl;
    	}
    }
    else{
    	cout<<"Sin Tupla"<<endl;
    }
	outfile2.close();
}