#ifndef __CCOLUMNA_HPP__
#define __CCOLUMNA_HPP__
#include<string>
#include <vector>
using namespace std;
class CColumna {
	vector<string>*misdatos;
	int mitipodedato;
	int cant;
	string nombre;
public:
	CColumna(int mitipodedato, string nombre) {
		this->mitipodedato = mitipodedato;
		this->misdatos = new vector<string>();
		this->cant = 0;
		this->nombre = nombre;
	}
	~CColumna() {
		misdatos->clear();
		delete misdatos;
	}
	int getmitipodedato() {
		return this->mitipodedato;
	}
	void agregardato(string dato) {
		this->misdatos->push_back(dato);
		++cant;
		cout << "\nAgregado\n";
	}
	string getminombre() {
		return this->nombre;
	}
	string getmidatoinpos(int pos) {
		return this->misdatos->at(pos);
	}
	int getcant() {
		return this->cant;
	}
	vector<string>* getmisdatos() {
		return this->misdatos;
	}
	void setmisdatos(vector<string>* misdatos) {
		this->misdatos = misdatos;
	}
	friend class CTabla;
};
#endif