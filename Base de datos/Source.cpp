#include<iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <functional>
#include<stack>
//#include "CBasededatos.hpp"
#include "CMenu.h"
using namespace std;
using namespace System;
int main() {
	setlocale(LC_ALL, "Spanish");
	//Console::BackgroundColor = ConsoleColor::White;
	//Console::ForegroundColor = ConsoleColor::Black;
	CMenu* nuevo = new CMenu();
	/*DataBase *basededatos = new DataBase();
	string paracolumna;
	basededatos->agregartabla("Hola");
	cout << basededatos->gettablainpos(0)->getnombredelatabla()<<endl;
	basededatos->gettablainpos(0)->agregarcolumna(1);
	basededatos->gettablainpos(0)->agregarcolumna(2);
	cout << "Nombre : \n" << endl;cin >> paracolumna;
	basededatos->gettablainpos(0)->getcolumnainpos(0)->agregardato(paracolumna);
	cout << "Apellido : \n" << endl;cin >> paracolumna; 
	basededatos->gettablainpos(0)->getcolumnainpos(1)->agregardato(paracolumna);
	cout << "Nombre : \n" << endl;cin >> paracolumna;
	basededatos->gettablainpos(0)->getcolumnainpos(0)->agregardato(paracolumna);
	cout << "Apellido : \n" << endl;cin >> paracolumna;
	basededatos->gettablainpos(0)->getcolumnainpos(1)->agregardato(paracolumna);
	cout << "Nombre : \n" << endl;cin >> paracolumna; 
	basededatos->gettablainpos(0)->getcolumnainpos(0)->agregardato(paracolumna);
	cout << "Apellido : \n" << endl;cin >> paracolumna;
	basededatos->gettablainpos(0)->getcolumnainpos(1)->agregardato(paracolumna);
	cout << "Nombre : \n" << endl;cin >> paracolumna;
	basededatos->gettablainpos(0)->getcolumnainpos(0)->agregardato(paracolumna);
	cout << "Apellido : \n" << endl;cin >> paracolumna;
	basededatos->gettablainpos(0)->getcolumnainpos(1)->agregardato(paracolumna);

	cout << "Numero de columnas : " << basededatos->gettablainpos(0)->getcantidaddecolumnas() << endl;
	cout << "Cantidad de datos de la primera columna : " << basededatos->gettablainpos(0)->getcolumnainpos(0)->getcant();
	cout << "Cantidad de datos de la segunda columna : " << basededatos->gettablainpos(0)->getcolumnainpos(1)->getcant();
	cout << "Esta es la manera en la cual hasta por el momento el programa recopilaria los datos\n";
	cout << "Dato de la columna 1: " << basededatos->gettablainpos(0)->getcolumnainpos(0)->getmidatoinpos(0) << endl;
	cout << "Dato de la columna 2: " << basededatos->gettablainpos(0)->getcolumnainpos(1)->getmidatoinpos(0) << endl;

	basededatos->gettablainpos(0)->indexar();
	basededatos->gettablainpos(0)->mostrarregistros();
	auto lambda0 = [=](vector<string>* a) {
		cout << a->at(0)<<endl;
	};
	basededatos->gettablainpos(0)->getabbF()->enorden(lambda0);
	basededatos->gettablainpos(0)->filtrar();
	delete basededatos;*/
	_getch();
	return 0;
}