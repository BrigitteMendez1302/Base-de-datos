#ifndef __CBASEDEDATOS_HPP__
#define __CBASEDEDATOS_HPP__
#include "CTabla.hpp"
#include <vector>
using namespace std;
class CBasededatos {
private:
	vector<CTabla*> tablas;
	CTabla* tablaauxiliar;
	int cantidaddetablas;
public:
	void agregartabla(string nombre) {
		tablas.push_back(new CTabla(nombre));
		++cantidaddetablas;
	}
	void igualartabla(CTabla* antigua){
		this->tablaauxiliar = antigua;
	}
	CTabla* gettablainpos(int pos) {
		return tablas.at(pos);
	}
	CTabla* gettablaaux() {
		return this->tablaauxiliar;
	}
	void settablaaux(CTabla* tablaauxiliar) {
		this->tablaauxiliar = tablaauxiliar;
	}
	int getcantidaddetablas() {
		return this->cantidaddetablas;
	}
	CBasededatos() {
		this->cantidaddetablas = 0;
	}
	~CBasededatos() {
		tablas.clear();
		delete tablaauxiliar;
	}
};

#endif
//disenowebakus.net / tipos - de - datos - mysql.php