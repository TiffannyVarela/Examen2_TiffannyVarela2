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
	void addList_encabezados(string);
	void removeList_encabezados(int);


	void setList_tuplas(vector <Tupla*> );
	vector <Tupla*> getList_tuplas();
	Tupla* getTupla(int);
	void addList_tuplas(Tupla*);
	void removeList_tuplas(int);

	~Relacion();
	
};