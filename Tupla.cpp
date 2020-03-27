#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
#include "Tupla.h"
using namespace std;

Tupla::Tupla(){
	id =0;
	vector <string> list_atributos;
}

Tupla::Tupla(int id){
	this->id=id;
}

void Tupla::setId(int x){
	id=x;
} 

int Tupla::getId(){
	return id;
}

void Tupla::setList_atributos(vector <string> x){
	list_atributos = x;
}

vector <string> Tupla::getList_atributos(){
	 return list_atributos;
}

string Tupla::getAtributo(int pos){
	string r;
	for (int i = 0; i < list_atributos.size(); i++)
	{
		if (i==pos)
		{
			r=list_atributos[i];
		}
	}
	return r;
}

void Tupla::addList_atributos(string x){
	list_atributos.push_back(x);
}

void Tupla::removeList_atributos(int pos){
	list_atributos.erase(list_atributos.begin()+pos);
}

Tupla::~Tupla(){
	cout<<"Tupla Eliminada"<<endl;
}