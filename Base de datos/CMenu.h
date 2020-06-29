#ifndef __CMENU_HPP__
#define __CMENU_HPP__
#include<iostream>
#include<string>
#include<functional>
#include "CBasededatos.hpp"
using namespace std;
auto lambda0 = [=](vector<string>* a) {
	for (short i = 0; i < a->size(); i++) cout << a->at(i) << " ";
	cout << endl;
};

class CMenu
{
	int numvecesquepuedesvisualizar;
public:
	CMenu() {
		setlocale(LC_ALL, "Spanish");
		basededatos = new CBasededatos();
		this->numvecesquepuedesvisualizar = 0;
		registroinicializado();
		main();
	}
	~CMenu() {
		delete basededatos;
	}
	void registroinicializado() {
		this->basededatos->agregartabla("YUTE");
		this->basededatos->gettablainpos(0)->agregarcolumna(1, "Short");
		this->basededatos->gettablainpos(0)->agregarcolumna(2, "Inti");
		this->basededatos->gettablainpos(0)->agregarcolumna(6, "Chars");
		this->basededatos->gettablainpos(0)->agregarcolumna(7, "String");
		this->basededatos->gettablainpos(0)->getcolumnainpos(0)->agregardato("14");
		this->basededatos->gettablainpos(0)->getcolumnainpos(0)->agregardato("12");
		this->basededatos->gettablainpos(0)->getcolumnainpos(0)->agregardato("44");
		this->basededatos->gettablainpos(0)->getcolumnainpos(0)->agregardato("44");
		this->basededatos->gettablainpos(0)->getcolumnainpos(1)->agregardato("569");
		this->basededatos->gettablainpos(0)->getcolumnainpos(1)->agregardato("145");
		this->basededatos->gettablainpos(0)->getcolumnainpos(1)->agregardato("652");
		this->basededatos->gettablainpos(0)->getcolumnainpos(1)->agregardato("63");
		this->basededatos->gettablainpos(0)->getcolumnainpos(2)->agregardato("D");
		this->basededatos->gettablainpos(0)->getcolumnainpos(2)->agregardato("a");
		this->basededatos->gettablainpos(0)->getcolumnainpos(2)->agregardato("f");
		this->basededatos->gettablainpos(0)->getcolumnainpos(2)->agregardato("C");
		this->basededatos->gettablainpos(0)->getcolumnainpos(3)->agregardato("Brigitte");
		this->basededatos->gettablainpos(0)->getcolumnainpos(3)->agregardato("Anita");
		this->basededatos->gettablainpos(0)->getcolumnainpos(3)->agregardato("fernanda");
		this->basededatos->gettablainpos(0)->getcolumnainpos(3)->agregardato("Claudio");
	}
		
		//Fase 0

	void main() {
		system("cls");
		cout << "\n\t\tBienvenido a Jutte\n\n";
		cout << "Qué desea hacer?\n\n";
		cout << "1) Agregar nueva tabla\n";
		cout << "2) Visualizar alguna tabla\n";
		cout << "3) Mas opciones\n";
		cout << "4) Salir\n";
		short opcion = 0;
		while (true)
		{
			cin >> opcion;
			if (opcion > 0 && opcion <= 4)break;
		}
		switch (opcion)
		{
		case 1:
			agregar_Nueva_Tabla(); break;
		case 2:
			visualizar_Alguna_Tabla(); break;
		case 3:
			mas_Opciones(); break;
		case 4:
			salir(); break;
		default:
			break;
		}
	}
private:
	CBasededatos *basededatos;
	string paracolumna;
	
	//Fase 1

	void agregar_Nueva_Tabla() {
		system("cls");
		cout << "\n\t\tAgregar nueva tabla:\n\n";
		string nombre = "";
		cout << "Ingrese el nombre de esta nueva tabla:\n";
		cin >> nombre;
		basededatos->agregartabla(nombre);
		cout << "Creando tabla...\n\n";
		cout << "Tabla creado con exito.\n\n";
		char opcion = ' ';
		cout << "Presione B para regresar...\n";
		while (true)
		{
			cin >> opcion;
			if (opcion == 'B' || opcion == 'b')break;
		}
		main();
	}

	void visualizar_Alguna_Tabla() {//mejorar porque estamos limitados a 3 tablas
		system("cls");
		cout << "\n\t\tVisualizar alguna tabla\n\n";
		for (short i = 0; i < basededatos->getcantidaddetablas(); i++)
		{
			cout << i+1 << ") Tabla "<<i+1 << " : " << basededatos->gettablainpos(i)->getnombredelatabla()<<" \n";
		}
		cout << "\nIngrese el número de tabla que desea ver o\n";
		cout << "Presione B para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == '1' || opcion == '2' || opcion == '3' || opcion == 'B' || opcion == 'b')break;
		}
		switch (opcion)
		{
		case '1':	visualizar_Tabla(1); break;//cambiar
		case '2':	visualizar_Tabla(2); break;//cambiar
		case '3':	visualizar_Tabla(3); break;//cambiar
		case 'B' || 'b':
			break;
		default:
			break;
		}
		main();
	}

	void mas_Opciones() {
		system("cls");
		cout << "\n\t\tMas opciones\n\n";
		cout << "1) Modificar tabla\n";
		cout << "2) Filtrar tabla\n";
		cout << "3) Mandar el registro a un archivo plano\n";
		cout << "Presione B para regresar...\n";

		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == '1' || opcion == '2' || opcion == '3' || opcion == 'B' || opcion == 'b')break;
		}
		switch (opcion)
		{
		case '1':	modificar_Alguna_Tabla(); break;
		case '2':	filtrar_Alguna_Tabla(); break;
		case '3':	mandar_El_Regitro_A_Un_Archivo_Plano(); break;
		case 'B' || 'b': 
			break;
		default:
			break;
		}
		main();
	}

	void salir() {
		system("cls");
		cout << "\nMuchas gracias por usar Jutte, hasta la proxima.";
		_sleep(3000);
		exit(0);
	}

	//Fase 2
	void visualizar_Tabla(int n) {
		system("cls");
		cout << "1. Ver tabla completa\n";
		cout << "2. Ver tabla ordenada de acuerdo a los valores de una columna\n";
		cout << "3. Ver tabla por campos seleccionados\n\n";
		cout << "Ingrese el modo visualización de tabla que desea o\n";
		cout << "Presione B para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == '1' || opcion == '2' || opcion == '3' || opcion == 'B' || opcion == 'b')break;
		}
		switch (opcion)
		{
		case '1':	visualizar_Tabla_Completa(n); break;//siguen llegando como n
		case '2':	visualizar_Tabla_Ordenada_Por_Columna(n); break;
		case '3':	visualizar_Tabla_Por_Columna_Seleccionadas(n); break;
		case 'B' || 'b': break;
		default: break;
		}
		//cout << "Presione B para regresar...\n";
		//opcion = ' ';
		//while (true)
		//{
		//	cin >> opcion;
		//	if (opcion == 'B' || opcion == 'b')break;
		//}
		visualizar_Alguna_Tabla();
	}
	void visualizar_Tabla_Completa(short n) {
		system("cls");
		numvecesquepuedesvisualizar++;
		if (n-1 >= 0 && n-1 <= basededatos->gettablainpos(n-1)->getcantidaddecolumnas()) {
			cout <<"\t" << basededatos->gettablainpos(n-1)->getnombredelatabla() << endl<<endl;
			for (short i = 0; i < basededatos->gettablainpos(n-1)->getcantidaddecolumnas(); i++)
			{
				basededatos->gettablainpos(n - 1)->getcolumnainpos(i)->getminombre();
			}
			if (this->numvecesquepuedesvisualizar == 1) basededatos->gettablainpos(n - 1)->indexar();
			basededatos->gettablainpos(n-1)->mostrarregistros();
			cout << endl;
	}
		cout << "Presione B para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == 'B' || opcion == 'b')break;
		}
		visualizar_Tabla(n);
	}
	void visualizar_Tabla_Ordenada_Por_Columna(int n) {
		int columna = 0;
		while (true)
		{
			system("cls");
			cout << "Tabla " << basededatos->gettablainpos(n - 1)->getnombredelatabla() << endl;
			cout << "Ingrese el numero de columna con el cual se ordenará la tabla \n";
			cin >> columna;
			if (columna > 0 && columna <= basededatos->gettablainpos(n - 1)->getcantidaddecolumnas()) break;
		}
		basededatos->gettablainpos(n - 1)->indexararbol(columna - 1);
		basededatos->gettablainpos(n - 1)->getabbF()->enorden(lambda0);
		string nombrearchivo; bool yes = false;
		cout << "Desea exportar esta tabla a un archivo plano ?(1: sí, 0: no) : ";
		while (true)
		{
			cin >> yes;
			if (yes == 0 || yes == 1)break;
		}
		if (yes) {
			cout << "Nombre para su archivo : ";cin >> nombrearchivo;
			cout << "Recordatorio:\n\n";
			cout << "El archivo que generará este programa, separará las columnas por una ',' y las filas por un '\\n'.\n\n";
			cout << "Transfiriendo datos...\n";
			basededatos->gettablainpos(n - 1)->crear_archivo_lista(nombrearchivo);
			cout << "Tabla pasada a texto plano con exito.\n";
			cout << "Ubicación: Carpeta JUTTE en el disco D\n\n";
		}
		cout << "Presione B para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == 'B' || opcion == 'b')break;
		}
		visualizar_Tabla(n);
	}
	void visualizar_Tabla_Por_Columna_Seleccionadas(int n) {
		int columna1=0,cantidad = 0;
		string nombrearchivo;
		bool yes;
		while (true)
		{
			system("cls");
			cout << "Tabla " << basededatos->gettablainpos(n-1)->getnombredelatabla() << endl;
			cout << "Ingrese cuantas columnas desea ver: \n";
			cin >> cantidad;
			if (cantidad > 0 && cantidad <= basededatos->gettablainpos(n-1)->getcantidaddecolumnas()) break;
		}
		cout << "Columnas:\n";
		for (int i = 0; i < basededatos->gettablainpos(n - 1)->getcantidaddecolumnas(); i++) cout << "Columna " << i + 1 << ": " << basededatos->gettablainpos(n - 1)->getcolumnainpos(i)->getminombre() << "\n";cout << "\n";
		basededatos->constructortablanodefinida();
		for (short i = 0; i < cantidad; i++)
		{
			cout << "Digito de la columna que desea ver : " << endl;cin >> columna1;
			basededatos->gettablaauxnodefinida()->traspasarcolumna(basededatos->gettablainpos(n - 1)->getcolumnainpos(columna1 - 1));
		}
		basededatos->gettablaauxnodefinida()->indexar();
		basededatos->gettablaauxnodefinida()->mostrarregistros();
		cout << "Desea exportar esta tabla a un archivo plano ?(1: sí, 0: no) : ";
		while (true)
		{
			cin >> yes;
			if (yes == 0 || yes == 1)break;
		}
		if (yes) {
			cout << "Nombre para su archivo : ";cin >> nombrearchivo;
			cout << "Recordatorio:\n\n";
			cout << "El archivo que generará este programa, separará las columnas por una ',' y las filas por un '\\n'.\n\n";
			cout << "Transfiriendo datos...\n";
			this->basededatos->gettablaauxnodefinida()->mandaraarchivotxt(nombrearchivo);
			cout << "Tabla pasada a texto plano con exito.\n";
			cout << "Ubicación: Carpeta JUTTE en el disco D\n\n";
		}

		basededatos->destructortablanodefinida();
		cout << "Presione B para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == 'B' || opcion == 'b')break;
		}
		visualizar_Tabla(n);
	}
	void modificar_Alguna_Tabla() {
		system("cls");
		cout << "\n\t\tModificar tabla\n\n";
		cout << "Qué tabla desea modificar?\n\n";
		for (short i = 0; i < basededatos->getcantidaddetablas(); i++)
		{
			cout << i + 1 << ") Tabla " << i + 1 << " : " << basededatos->gettablainpos(i)->getnombredelatabla() << " \n";
		}
		cout << "Ingrese el número de tabla que desea modifcar o\n";
		cout << "Presione B para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == '1' || opcion == '2' || opcion == '3' || opcion == 'B' || opcion == 'b')break;
		}
		switch (opcion)
		{
		case '1':	modificar_Tabla(1); break;
		case '2':	modificar_Tabla(2); break;
		case '3':	modificar_Tabla(3); break;
		case 'B' || 'b':
			break;
		default:
			break;
		}
		mas_Opciones();
	}

	void filtrar_Alguna_Tabla() {
		system("cls");
		cout << "\n\t\tFiltrar tabla\n\n";
		cout << "Qué tabla desea filtrar?\n\n";
		for (short i = 0; i < basededatos->getcantidaddetablas(); i++)
		{
			cout << i + 1 << ") Tabla " << i + 1 << " : " << basededatos->gettablainpos(i)->getnombredelatabla() << " \n";
		}
		cout << "Ingrese el número de tabla que desea filtrar o\n";
		cout << "Presione B para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == '1' || opcion == '2' || opcion == '3' || opcion == 'B' || opcion == 'b')break;
		}
		switch (opcion)
		{
		case '1':	filtrar_Tabla(1); break;
		case '2':	filtrar_Tabla(2); break;
		case '3':	filtrar_Tabla(3); break;
		case 'B' || 'b':
			break;
		default:
			break;
		}
		mas_Opciones();
	}

	void mandar_El_Regitro_A_Un_Archivo_Plano() {
		system("cls");
		string nombrearchivo;
		cout << "\n\t\tMandar el registro a archivo plano\n\n";
		cout << "Nombre del archivo : ";cin >> nombrearchivo;
		cout << "Recordatorio:\n\n";
		cout << "El archivo que generará este programa, separará las columnas por una ',' y las filas por un '\n'.\n\n";
		cout << "Transfiriendo datos...\n";
		_sleep(300);
		//aqui se modificaria para cualquier tabla
		this->basededatos->gettablainpos(0)->mandaraarchivotxt(nombrearchivo);
		cout << "Tabla pasada a texto plano con exito.\n";
		cout << "Ubicación: Carpeta JUTTE en el disco D\n\n";
		cout << "Presione B para regresar...\n";
		char opcion;
		while (true)
		{
			cin >> opcion;
			if (opcion == 'B' || opcion == 'b')break;
		}
		mas_Opciones();
	}

	//Fse 3

	void modificar_Tabla(short n) {
		system("cls");
		cout << "\t" << this->basededatos->gettablainpos(n - 1)->getnombredelatabla() << endl<<endl;
		cout << "1) Agregar columna a la tabla\n";
		cout << "2) Agregar fila o nuevo registro a la tabla\n\n";
		cout << "Ingrese el número de la opcion quec desee ejecutar o\n";
		cout << "Presione B para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == '1' || opcion == '2' || opcion == 'B' || opcion == 'b')break;
		}
		switch (opcion)
		{
		case '1':	agregar_Columna(n); break;//modificar para pasar referencia a tabla
		case '2':	agregar_Fila_O_Registro(n); break;//modificar para pasar referencia a tabla
		case 'B' || 'b':
			break;
		default:
			break;
		}
		modificar_Alguna_Tabla();
	}

	void filtrar_Tabla(short n) {
		system("cls");
		//crear un objeto tabla dinamica...
		//Ctabla* nuevo;
		//inicializar objeto tabla dinamica..
		//nuevo= obtener_tabla(n);
		//cout<<nuevo->getNombre();
		cout << "Cuál es el criterio con el que filtrará su tabla?\n\n";
		cout << "a. Deseo ver el registro del mayor elemento\n";
		cout << "b. Deseo ver el registro del menor elemento\n";
		cout << "c. Deseo ver el registro del/de los elementos que sean iguales al elemento que yo ingrese\n";
		cout << "d. Deseo ver el registro del/de los elementos que inicien con el caracter que yo ingrese\n";
		cout << "e. Deseo ver el registro del/de los elementos que finalicen con el caracter que yo ingrese\n";
		cout << "f. Deseo ver el registro del/de los elementos que contengan el caracter que yo ingrese\n";
		cout << "g. Deseo ver el registro del/de los elementos que no contengan el caracter que yo ingrese\n\n";
		cout << "Ingrese la letra de la opcion quec desee ejecutar o\n";
		cout << "Presione X para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == 'a' || opcion == 'b' || opcion == 'c' || opcion == 'd' || opcion == 'e' ||
				opcion == 'f' || opcion == 'g' || opcion == 'X' || opcion == 'x')break;
		}
		switch (opcion)
		{
		case 'a':	filtrar_Tabla_Por_Criterio(n,9); break;//el n es el numero de la tabla a filtrar
		case 'b':	filtrar_Tabla_Por_Criterio(n,8); break;
		case 'c':	filtrar_Tabla_Por_Criterio(n,3); break;
		case 'd':	filtrar_Tabla_Por_Criterio(n,4); break;
		case 'e':	filtrar_Tabla_Por_Criterio(n,5); break;
		case 'f':	filtrar_Tabla_Por_Criterio(n,6); break;
		case 'g':	filtrar_Tabla_Por_Criterio(n,7); break;// 1 y 2 no están porque no tienen concordancia con el menu de opciones
		case 'X' || 'x':
			break;
		default:
			break;
		}
		filtrar_Alguna_Tabla();
	}

	//Fase 4

	void agregar_Columna(int n) {
		system("cls");
		cout << "\n\t\tAgregar columna\n\n";
		cout << "Defina el tipo de dato de la columna\n\n";
		cout << "Numéricos\t\tAlfanuméricos\n";
		cout << "1) Tinyint\t\t6) Char\n";
		cout << "2) Smallint\t\t7) Varchar\n";
		cout << "3) Mediumint\t\t8) Tinytext\n";
		cout << "4) Integer\t\t9) Mediumtext\n";
		cout << "5) Bigint\t\t10) Text\n\n";
		cout << "Ingrese la opcion quec desee ejecutar:\n";
		cout << "Presione X para regresar...\n\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == '1' || opcion == '2' || opcion == '3' || opcion == '4' || opcion == '5' || opcion == '10' ||
				opcion == '6' || opcion == '7' || opcion == '8' || opcion == '9' || opcion == 'X' || opcion == 'x')break;
		}
		switch (opcion)
		{
		case '1':	agregar_Columna_Tipo(1,n); break;
		case '2':	agregar_Columna_Tipo(2,n); break;
		case '3':	agregar_Columna_Tipo(3,n); break;
		case '4':	agregar_Columna_Tipo(4,n); break;
		case '5':	agregar_Columna_Tipo(5,n); break;
		case '6':	agregar_Columna_Tipo(6, n); break;
		case '7':	agregar_Columna_Tipo(7, n); break;
		case '8':	agregar_Columna_Tipo(8, n); break;
		case '9':	agregar_Columna_Tipo(9, n); break;
		case '10':	agregar_Columna_Tipo(10, n); break;
		case 'X' || 'x':
			break;
		default:
			break;
		}
		modificar_Tabla(n);
	}

	void agregar_Fila_O_Registro(int numtabla) {
		system("cls");
		cout << "\n\t\tAgregar fila o nuevo registro a la tabla\n\n";
		//crear un objeto CRegitro o Cfila 
		//obtener numero de columnas de la tabla
		short n = basededatos->gettablainpos(numtabla - 1)->getcantidaddecolumnas();
		//una varible temporal
		string temp;
		this->numvecesquepuedesvisualizar = 0;
		basededatos->gettablainpos(numtabla - 1)->destructordatosdelatabla();
		for (size_t i = 0; i < n; i++)
		{
			cout << "Dato para la columna " << basededatos->gettablainpos(numtabla - 1)->getcolumnainpos(i)->getminombre() << ":\n";
			cin >> temp;
			basededatos->gettablainpos(numtabla - 1)->getcolumnainpos(i)->agregardato(temp);
			temp = "";
		}
		cout << "Agregando registro a la tabla...\n\n";
		_sleep(3000);
		cout << "Presione B para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == 'B' || opcion == 'b')break;
		}
		modificar_Tabla(numtabla);
	}

	void filtrar_Tabla_Por_Criterio(int n, int opcionafiltrar) {
		basededatos->settablaauxdefinida(basededatos->gettablainpos(n - 1));
		basededatos->gettablaauxdefinida()->filtrar(opcionafiltrar);
		
		//validar que sea hasta 2 filtrados
		bool yes;
		cout << "Desea seguir filtrando ?(Esta sería la última vez, max:2) : ";cin >> yes;
	/*	if (yes) {
			basededatos->gettablaauxdefinida()->filtrar(opcionafiltrar);
		}*/
		cout << "Presione B para regresar...\n";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == 'B' || opcion == 'b')break;
		}
		filtrar_Tabla(n);
	}

	void agregar_Columna_Tipo(int n, int quetablaes) {
		this->numvecesquepuedesvisualizar = 0;
		basededatos->gettablainpos(quetablaes - 1)->destructordatosdelatabla();
		string nombre = "";
		cout << "Ingrese nombre de la columna:\n";
		cin >> nombre;
		cout << "\nCreando columna en la tabla...\n";
		this->basededatos->gettablainpos(quetablaes-1)->agregarcolumna(n,nombre);

		cout << "\nCreación de columna completa.\n\n";
		cout << "Presione B para regresar...";
		char opcion = ' ';
		while (true)
		{
			cin >> opcion;
			if (opcion == 'B' || opcion == 'b')break;
		}
		agregar_Columna(quetablaes);
	}
};
#endif
