#ifndef __CCOLUMNA_HPP__
#define __CCOLUMNA_HPP__
#include<string>
#include <vector>
using namespace std;
class CColumna {
	vector<string>*misdatos;
	int mitipodedato;
	//1 short
	//2 int
	//3 long long
	//4 char
	//5 string
	int cant;
public:
	CColumna(int mitipodedato) {
		this->mitipodedato = mitipodedato;
		this->misdatos = new vector<string>();
		this->cant = 0;
	}
	void agregardato(string dato) {
		this->misdatos->push_back(dato);
		++cant;
		cout << "\nAgregado\n";
	}
	string getmidatoinpos(int pos) {
		return this->misdatos->at(pos);
	}
	int getcant() {
		return this->cant;
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
	vector<string>* getmisdatos() {
		return this->misdatos;
	}

	friend class CTabla;
	friend class Database;
};
#endif