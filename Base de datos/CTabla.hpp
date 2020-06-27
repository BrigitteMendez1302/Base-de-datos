#ifndef __CTABLA_HPP__
#define __CTABLA_HPP__
#include "CColumna.hpp"
#include "CArbol.hpp"
#include <iostream>
#include <fstream>
using namespace std;
class CTabla {
	int cantidaddecolumnas;
	int ncol;
	vector<vector<string>*>* datosdelatabla;
	CArbolbb<vector<string>*>* abbF;
	vector<CColumna*>columnas;//**
	string nombredelatabla;
public:
	void agregarcolumna(int mitipodedato, string nombre) {
		columnas.push_back(new CColumna(mitipodedato, nombre));
		cantidaddecolumnas++;
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
	CArbolbb<vector<string>*>* getabbF() {
		return this->abbF;
	}
	int getcantidaddecolumnas() {
		return this->cantidaddecolumnas;
	}
	void indexar() {
		auto compvalores = [=](vector<string>* a, vector<string>* b)->bool {
			return (a->at(ncol).compare(b->at(ncol)))<0;
		};
		vector<string>* fila;
		cout << "Cantidad de datos de la columna : " << columnas.at(0)->misdatos->size() << endl;
		cout << "Cantidad de columnas : " << columnas.size() << endl;
		for (short i = 0; i < columnas.at(0)->misdatos->size(); i++)
		{
			fila = new vector<string>;
			for (short j = 0; j < columnas.size(); j++)
			{
				fila->push_back(columnas.at(j)->getmisdatos()->at(i));
			}
			cout << endl;
			vector<string>* memoria = new vector<string>(*fila);
			datosdelatabla->push_back(memoria);
			abbF->insertar(memoria, compvalores);
			fila->clear(); delete fila;
		}

	}
	void mostrarregistros() {
		for (short i = 0; i < columnas.size(); i++)
		{
			cout << columnas.at(i)->getminombre() <<"\t";
		}
		cout << endl;
		for (int i = 0; i < datosdelatabla->size(); ++i) {
			for (int j = 0; j < datosdelatabla->at(0)->size(); ++j) {
				cout << datosdelatabla->at(i)->at(j) << "\t";
			}
			cout << endl;
		}
		cout << datosdelatabla->at(0)->at(0);
		cout << "tamaño de la tabla (filas) " << datosdelatabla->size() << endl;
		cout << "tamaño de la tabla (columnas) " << datosdelatabla->at(0)->size() << endl;
	}
	void borrararbol() {
		abbF->borrar_todo();
	}
	void filtrar() {
		int nColumna = 0, tipoFiltro = 0;
		string valor = "";
		while (true)
		{
			cout << "digite la columna que quiere filtrar"; cin >> nColumna;
			if (nColumna >= 0 && nColumna <= getcantidaddecolumnas())break;
		}
		while (true)
		{
			cout << "digite el tipo de filtrado"; cin >> tipoFiltro;
			if (tipoFiltro >= 1 && tipoFiltro <= 9)break;
		}
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
		if (tipoFiltro == 8 || tipoFiltro == 9)_filtrar(nColumna, tipoFiltro);
	}
	void _filtrar(int nColumna, int opcionDeFiltrado, string valor = "") {
		//1
		auto mayorQue = [=](vector<string>* a)->void {
			if (a->at(nColumna) > valor)
				for (int i = 0; i < a->size(); i++)cout << a->at(i) << " ";
			cout << endl;
		};
		//2
		auto menorQue = [=](vector<string>* a)->void {
			if (a->at(nColumna) < valor)
				for (int i = 0; i < a->size(); i++)cout << a->at(i) << " ";
			cout << endl;
		};
		//3
		auto igualA = [=](vector<string>* a)->void {
			if (a->at(nColumna) == valor)
				for (int i = 0; i < a->size(); i++)cout << a->at(i) << " ";
			cout << endl;
		};
		//4
		auto iniciaCon = [=](vector<string>* a)->void {
			if (a->at(nColumna).at(0) == valor.at(0))
				for (int i = 0; i < a->size(); i++)cout << a->at(i) << " ";
			cout << endl;
		};
		//5
		auto terminaCon = [=](vector<string>* a)->void {
			if (a->at(nColumna).at(a->at(nColumna).size() - 1) == valor.at(0))
				for (int i = 0; i < a->size(); i++)cout << a->at(i) << " ";
			cout << endl;
		};
		//6
		auto estaContenidoEn = [=](vector<string>* a)->void {
			if (a->at(nColumna).find(valor)< string::npos)
				for (int i = 0; i < a->size(); i++)cout << a->at(i) << " ";
			cout << endl;
		};
		//7
		auto noEstaContenidoEn = [=](vector<string>* a)->void {
			if (a->at(nColumna).find(valor) == string::npos)
				for (int i = 0; i < a->size(); i++)cout << a->at(i) << " ";
			cout << endl;
		};
		//8
		auto imprimir = [=](vector<string>* a)->void {
			for (int i = 0; i < a->size(); i++)cout << a->at(i) << " ";
			cout << endl;
		};

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
		default:
			break;
		}
	}
	CTabla(string nombre) {
		this->cantidaddecolumnas = 0;
		datosdelatabla = new  vector<vector<string>*>();
		abbF = new CArbolbb<vector<string>*>();
		this->ncol = 0;
		this->nombredelatabla = nombre;
	}
	~CTabla() {
		columnas.clear();
	}
	friend class Database;
};
#endif
