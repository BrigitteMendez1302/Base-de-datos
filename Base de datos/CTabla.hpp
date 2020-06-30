#ifndef __CTABLA_HPP__
#define __CTABLA_HPP__
#include "CColumna.hpp"
#include "CArbol.hpp"
#include <iostream>
#include <fstream>
using namespace std;

class CTabla {
	int cantidaddecolumnas, cantidaddecolumnasesp;
	vector<vector<string>*>* datosdelatabla;
	CArbolvsl<vector<string>*>* abbF;
	vector<CColumna*>columnas;
	string nombredelatabla;
	ofstream archivo;
	CLista<vector<string>*>* lista;

public:
	void agregarcolumna(int mitipodedato, string nombre) {
		columnas.push_back(new CColumna(mitipodedato, nombre));
		cantidaddecolumnas++;
	}
	void traspasarcolumna(CColumna* antigua) {
		CColumna* nueva = antigua;
		columnas.push_back(nueva);
		cantidaddecolumnasesp++;
	}
	string getnombredelatabla() {
		return this->nombredelatabla;
	}
	void setnombredelatabla(string nombredelatabla) {
		this->nombredelatabla = nombredelatabla;
	}
	CColumna* getcolumnainpos(int pos) {
		return columnas.at(pos);
	}
	CArbolvsl<vector<string>*>* getabbF() {
		return this->abbF;
	}
	CLista<vector<string>*>* getlista() {
		return this->lista;
	}
	int getcantidaddecolumnas() {
		return this->cantidaddecolumnas;
	}
	int getcantidaddecolumnasesp() {
		return this->cantidaddecolumnasesp;
	}
	int to_int(string dato) {
		return atoi(dato.c_str());
	}
	long long to_longlong(string dato) {
		return atoll(dato.c_str());
	}
	bool to_bool(string dato) {
		return (bool)atoi(dato.c_str());
	}
	char to_char(string dato) {
		return dato.at(0);
	}
	void destructordatosdelatabla() {
		datosdelatabla->clear();
		delete datosdelatabla;
	}
	void inicializadatosdelatabla() {
		this->datosdelatabla = new  vector<vector<string>*>();
	}
	void indexar() {
		vector<string>* fila;
		inicializadatosdelatabla();
		cout << "Cantidad de datos de la columna : " << columnas.at(0)->misdatos->size() << endl;
		cout << "Cantidad de columnas : " << columnas.size() << endl << endl;
		for (short i = 0; i < columnas.at(0)->misdatos->size(); i++)
		{
			fila = new vector<string>;
			for (short j = 0; j < columnas.size(); j++)
			{
				fila->push_back(columnas.at(j)->getmisdatos()->at(i));
			}
			vector<string>* memoria = new vector<string>(*fila);
			datosdelatabla->push_back(memoria);//indexacion
			fila->clear(); delete fila;
		}
	}
	void indexararbol(int ncol) {
		int tipodedato = columnas.at(ncol)->getmitipodedato();
		vector<string>* fila;
		auto compints = [=](vector<string>* a, vector<string>* b)->bool {
			return to_int(a->at(ncol)) < to_int(b->at(ncol));
		};
		auto complongs = [=](vector<string>* a, vector<string>* b)->bool {
			return to_longlong(a->at(ncol)) < to_longlong(b->at(ncol));
		};
		auto compchars = [=](vector<string>* a, vector<string>* b)->bool {
			return a->at(ncol).at(0) < b->at(ncol).at(0);
		};
		auto compvalores = [=](vector<string>* a, vector<string>* b)->bool {
			return (a->at(ncol).compare(b->at(ncol))) < 0;
		};
		abbF = new CArbolvsl<vector<string>*>();
		for (short i = 0; i < columnas.at(0)->misdatos->size(); i++)
		{
			fila = new vector<string>;
			for (short j = 0; j < columnas.size(); j++)
			{
				fila->push_back(columnas.at(j)->getmisdatos()->at(i));
			}
			vector<string>* memoria = new vector<string>(*fila);
			if (tipodedato == 1 || tipodedato == 2 || tipodedato == 3 || tipodedato == 4) {
				abbF->insertar(memoria, compints);
			}
			if (tipodedato == 5) {
				abbF->insertar(memoria, complongs);
			}
			if (tipodedato == 6) {
				abbF->insertar(memoria, compchars);
			}
			if (tipodedato == 7 || tipodedato == 8 || tipodedato == 9 || tipodedato == 10) {
				abbF->insertar(memoria, compvalores);
			}
			fila->clear(); delete fila;
		}
	}
	void mostrarregistros() {
		for (short i = 0; i < columnas.size(); i++)
		{
			cout << columnas.at(i)->getminombre() << "\t";
		}
		cout << endl;
		for (int i = 0; i < datosdelatabla->size(); ++i) {
			for (int j = 0; j < datosdelatabla->at(0)->size(); ++j) {
				cout << datosdelatabla->at(i)->at(j) << "\t";
			}
			cout << endl;
		}
		cout << "Tamaño de la tabla (filas) " << datosdelatabla->size() << endl;
		cout << "Tamaño de la tabla (columnas) " << datosdelatabla->at(0)->size() << endl;
	}
	void crear_archivo_lista(string nombredearchivo, int opcion) {
		if (opcion == 1) {
			this->lista = new CLista<vector<string>*>();
			abbF->cargarListaConDatos(lista);
		}
		vector<string>* aux = new vector<string>();
		string csv = nombredearchivo + ".csv";
		string fila;
		archivo.open(csv);
		cout << "cantidad: " << lista->size();
		cout << endl;
		for (int i = 0; i < lista->size(); i++)
		{
			aux = lista->obtenerElemento(i);
			for (int j = 0; j < aux->size(); j++) {
				if (j == aux->size() - 1) fila += aux->at(j) + "\n";
				else fila += aux->at(j) + ",";
			}
			archivo << fila; fila = "";
			aux->clear();
		}
		archivo.close();
		this->lista->eliminarelementos();
	}

	void mandaraarchivotxt(string nombredearchivo) {
		string csv = nombredearchivo + ".csv";
		string txt = nombredearchivo + ".txt";
		archivo.open(csv);
		string fila;
		for (short i = 0; i < columnas.size(); i++)
		{
			if (i == columnas.size() - 1) fila += columnas.at(i)->getminombre() + "\n";
			else fila += columnas.at(i)->getminombre() + ",";
		}
		archivo << fila;
		fila = "";
		for (short i = 0; i < columnas.at(0)->misdatos->size(); i++)
		{
			for (short j = 0; j < columnas.size(); j++)
			{
				if (j == columnas.size() - 1) fila += columnas.at(j)->getmisdatos()->at(i) + "\n";
				else fila += columnas.at(j)->getmisdatos()->at(i) + ",";
			}
			archivo << fila; fila = "";
		}
		archivo.close();
	}

	void filtrar(int tipoFiltro, short cantidad) {
		int nColumna, nColumna1;
		string valor = "";
		cout << "\nColumnas con las que contamos hasta el momento\n";
		for (short i = 0; i < getcantidaddecolumnas(); i++)
		{
			cout << i + 1 << ") " << getcolumnainpos(i)->getminombre() << endl;
		}
		while (true)
		{
			cout << "Digite la columna que quiere filtrar : "; cin >> nColumna;
			if (nColumna >= 1 && nColumna <= getcantidaddecolumnas())break;
		}
		indexararbol(nColumna - 1);
		cout << "Filtrar por...\n";
		if (tipoFiltro >= 1 && tipoFiltro <= 7) {
			if (tipoFiltro == 1)cout << "valores mayores que: ";
			if (tipoFiltro == 2)cout << "valores menores que: ";
			if (tipoFiltro == 3)cout << "valores iguales a: ";
			if (tipoFiltro == 4)cout << "valores que inician con: ";
			if (tipoFiltro == 5)cout << "valores que terminan con: ";
			if (tipoFiltro == 6)cout << "valores que contienen: ";
			if (tipoFiltro == 7)cout << "valores que no contienen: ";
			cin >> valor;
			_filtrar(nColumna, tipoFiltro, valor);
		}
		else _filtrar(nColumna, tipoFiltro);//int
	}
	//void delistaaarbol(int ncolumna, int tipodefiltrado) {
	//	for (short i = 0; i < lista->size(); i++)
	//	{
	//		abbF->insertar(this->lista->obtenerElemento(i),;
	//	}
	//}
	void _filtrar(int nColumna, int opcionDeFiltrado, string valor = "", int ncolumna = 1, int opcionDeFiltrado1 = 1) {
		//incluir el "Mayor que todo" y el menor que todo
		this->lista = new CLista<vector<string>*>();
		//1
		auto mayorQue = [=](vector<string>* a)->void {
			if (to_int(a->at(nColumna - 1)) > to_int(valor)) {
				lista->insertarAlFinal(a);
				for (int i = 0; i < a->size(); i++)cout << a->at(i) << " ";
			}
			cout << endl;
		};
		//2
		auto menorQue = [=](vector<string>* a)->void {
			if (to_int(a->at(nColumna - 1)) < to_int(valor)) {
				lista->insertarAlFinal(a);
				for (int i = 0; i < a->size(); i++)cout << a->at(i) << " ";
			}
			cout << endl;
		};
		//3
		auto igualA = [=](vector<string>* a)->void {
			if (a->at(nColumna - 1) == valor) {
				lista->insertarAlFinal(a);
				for (int i = 0; i < a->size(); i++)cout << a->at(i) << " ";
			}
			cout << endl;
		};
		//4
		auto iniciaCon = [=](vector<string>* a)->void {
			if (a->at(nColumna - 1).at(0) == valor.at(0)) {
				lista->insertarAlFinal(a);
				for (int i = 0; i < a->size(); i++)cout << a->at(i) << " ";
			};
			cout << endl;
		};
		//5
		auto terminaCon = [=](vector<string>* a)->void {
			if (a->at(nColumna - 1).at(a->at(nColumna - 1).size() - 1) == valor.at(0)) {
				lista->insertarAlFinal(a);
				for (int i = 0; i < a->size(); i++)cout << a->at(i) << " ";
			}
			cout << endl;
		};
		//6
		auto estaContenidoEn = [=](vector<string>* a)->void {
			lista->insertarAlFinal(a);
			if (a->at(nColumna - 1).find(valor) < string::npos) {
				for (int i = 0; i < a->size(); i++)cout << a->at(i) << " ";
			}
			cout << endl;
		};
		//7
		auto noEstaContenidoEn = [=](vector<string>* a)->void {
			if (a->at(nColumna - 1).find(valor) == string::npos) {
				lista->insertarAlFinal(a);
				for (int i = 0; i < a->size(); i++)cout << a->at(i) << " ";
			} 
			cout << endl;
		};
		//8
		auto imprimir = [=](vector<string>* a)->void {
			for (int i = 0; i < a->size(); i++)cout << a->at(i) << " ";
			cout << endl;
		};
		//filtrar hasta 2 columnas
		system("cls");
		cout << "\n\t\tFiltrado\n\n";
		cout << "Su tabla con los filtros correspondientes:\n";
		switch (opcionDeFiltrado)
		{
		case 1:	abbF->enorden(mayorQue); break;
		case 2:	abbF->enorden(menorQue); break;
		case 3: abbF->enorden(igualA); break;
		case 4:	abbF->enorden(iniciaCon); break;
		case 5:	abbF->enorden(terminaCon); break;
		case 6:	abbF->enorden(estaContenidoEn); break;
		case 7: abbF->enorden(noEstaContenidoEn); break;
		case 8: abbF->buscarMenor(imprimir); break;
		case 9: abbF->buscarMayor(imprimir); break;
		default: break;
		}
	}
	CTabla(string nombre) {
		this->cantidaddecolumnas = 0;
		this-> cantidaddecolumnasesp = 0;
		this->nombredelatabla = nombre;
	}
	~CTabla() {
		columnas.clear();
		this->datosdelatabla->clear();
		delete datosdelatabla;
	}
	friend class Database;
};
#endif
