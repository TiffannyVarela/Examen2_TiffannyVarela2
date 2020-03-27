#pragma once 
#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include "Tupla.h"
class Relacion
{
private:
	vector <string> list_encabezados;
	string nombre;
	vector <Tupla*> list_tuplas;
public:
	Relacion();
	Relacion(string);

	void setNombre(string);
	string getNombre();

	void setList_encabezados(vector <string> );
	vector <string> getList_encabezados();
	string getEncabezado(int);
	vector <string> addList_encabezados(string);
	vector <string> removeList_encabezados(int);


	void setList_tuplas(vector <Tupla*> );
	vector <Tupla*> getList_tuplas();
	Tupla* getTupla(int);
	vector <Tupla*> addList_tuplas(Tupla*);
	vector <Tupla*> removeList_tuplas(int);

	~Relacion();
	
};