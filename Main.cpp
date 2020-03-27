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
	ofstream outfile2;
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
	outfile<<nombre<<endl;
	for (int i = 0; i < relacion->getList_encabezados().size(); i++)
    {
    	outfile<<relacion->getEncabezado(i);
    	if (i<relacion->getList_encabezados().size()-1)
    	{
    		outfile<<";";
    	}
    }
    outfile<<"#"<<endl;
    //outfile<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	outfile.close();

	outfile2.open(ruta + nombre + ".txt");

	for (int i = 0; i < relacion->getList_encabezados().size(); i++)
    {
    	outfile2<<relacion->getEncabezado(i);
    	if (!relacion->getList_tuplas().empty())
    	{
    		outfile2<<"prueba "<<i<<endl;
    	}
    	else{
    		cout<<"Sin Tupla"<<endl;
    	}
    	if (i<relacion->getList_encabezados().size()-1)
    	{
    		outfile2<<";";
    	}
    }
    outfile2<<"#"<<endl;
    //outfile<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	outfile2.close();



	relaciones.push_back(relacion);
}

void VerRelaciones(){
	int pos;
	cout<<"RELACIONES DISPONIBLES\n\n";

	for (int i = 0; i < relaciones.size(); i++)
	{
		cout<<"Posicion "<<i<<" : "<<relaciones[i]->getNombre()<<endl;
	}

	cout<<"Ingrese la Posicion que Desea Ver: ";
	cin>>pos;

	while(pos<0 || pos>relaciones.size()-1){
		cout<<"POSICION NO VALIDA"<<endl;
		cout<<"Ingrese la Posicion que Desea Ver: ";
		cin>>pos;
	}

	int filas = relaciones[pos]->getList_tuplas().size();
	int columnas = relaciones[pos]->getList_encabezados().size();
	string** matriz = new string*[filas];

	for(int i=0; i<columnas; i++){
                matriz[i]=new string[columnas];
        }

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			if (i==0)
			{
				matriz[i][j]=relaciones[pos]->getEncabezado(j);
			}
			else{
				//matriz[i][j]=relaciones[pos]->getTupla(i)->getAtributo(j);
			}
		}
	}

	for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
                cout<<"a["<<i<<"]["<<j<<"]="<<setw(3)<<matriz[i][j]<<" ";
        }
        cout<<endl;

    }


	/*cout<<relaciones[pos]->getNombre()<<endl<<endl;
	int tam = relaciones->getList_encabezados().size()
	for (int i = 0; i < relaciones->getList_encabezados().size(); i++)
	{
		if (i==0)
		{
			/* code */
		//}
	//}


}


void InsertarTupla(){
	int pos;
	int id;
	int cont =1;
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
	for (int i = 0; i < relaciones[pos]->getList_encabezados().size(); i++)
	{
		cout<<"Inserte "<<relaciones[pos]->getEncabezado(cont)<<": "<<endl;
		cin>>atri;
		tupla->addList_atributos(atri);
		cont++;
	}
	relacion->addList_tuplas(tupla);
	cont=1;
}