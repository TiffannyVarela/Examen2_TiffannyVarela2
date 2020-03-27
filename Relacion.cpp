#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include "Tupla.h"
#include "Relacion.h"
using namespace std;

Relacion::Relacion(){
	nombre ="";
	vector <string> list_encabezados;
	vector <Tupla*> list_tuplas;
}

Relacion::Relacion(string nombre){
	this->nombre=nombre;
}

void Relacion::setNombre(string x){
	nombre=x;
} 

string Relacion::getNombre(){
	return nombre;
}

void Relacion::setList_encabezados(vector <string> x){
	list_encabezados = x;
}

vector <string> Relacion::getList_encabezados(){
	 return list_encabezados;
}

string Relacion::getEncabezado(int pos){
	string r;
	for (int i = 0; i < list_encabezados.size(); i++)
	{
		if (i==pos)
		{
			r=list_encabezados[i];
		}
	}
	return r;
}

void Relacion::addList_encabezados(string x){
	list_encabezados.push_back(x);
}

void Relacion::removeList_encabezados(int pos){
	list_encabezados.erase(list_encabezados.begin()+pos);
}


void Relacion::setList_tuplas(vector <Tupla*> x){
	list_tuplas = x;
}

vector <Tupla*> Relacion::getList_tuplas(){
	 return list_tuplas;
}

Tupla* Relacion::getTupla(int pos){
	Tupla* r;
	for (int i = 0; i < list_tuplas.size(); i++)
	{
		if (i==pos)
		{
			r=list_tuplas[i];
		}
	}
	return r;
}

void Relacion::addList_tuplas(Tupla* x){
	list_tuplas.push_back(x);
}

void Relacion::removeList_tuplas(int pos){
	list_tuplas.erase(list_tuplas.begin()+pos);
}

Relacion::~Relacion(){
	cout<<"Relacion Eliminada"<<endl;
}