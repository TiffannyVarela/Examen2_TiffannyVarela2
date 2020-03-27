#pragma once 
#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>

class Tupla
{
private:
	int id;
	vector <string> list_atributos;
public:
	Tupla();
	Tupla(int);

	void setId(int);
	int getId();

	void setList_atributos(vector <string> );
	vector <string> getList_atributos();
	string getAtributo(int);
	vector <string> addList_atributos(string);
	vector <string> removeList_atributos(int);

	~Tupla();
	
};