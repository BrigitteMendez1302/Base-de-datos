#ifndef __CBASEDEDATOS_HPP__
#define __CBASEDEDATOS_HPP__
#include "CTabla.hpp"
#include <vector>
using namespace std;
class CBasededatos
{
public:
	CBasededatos(){
		numerodetablas = 0;
		tablas = new vector <CTabla*>();
	}
	~CBasededatos(){}
	void agregartabla() {
		tablas->push_back(new CTabla());
		this->numerodetablas++;
	}
	CTabla* gettablainpos(int pos) {
		return tablas->at(pos);
	}
	vector<CTabla*>* gettablas() {
		return this->tablas;
	}
	int getnumerodetablas() {
		return this->numerodetablas;
	}
private:
	vector<CTabla*>* tablas;
	int numerodetablas;
};
class DataBase {
private:
	vector<CTabla*> tablas;
public:
	void agregartabla() {
		tablas.push_back(new CTabla());
	}
	CTabla* gettablainpos(int pos) {
		return tablas.at(pos);
	}
	DataBase() {}
	~DataBase() {
		tablas.clear();
	}
};

#endif
//disenowebakus.net / tipos - de - datos - mysql.php