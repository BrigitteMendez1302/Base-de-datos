#ifndef __CBASEDEDATOS_HPP__
#define __CBASEDEDATOS_HPP__
#include "CTabla.hpp"
#include <vector>
using namespace std;
class CBasededatos {
private:
	vector<CTabla*> tablas;
	CTabla* tablaauxiliardefinida;
	CTabla* tablaauxiliarnodefinida;
	int cantidaddetablas;
public:
	void agregartabla(string nombre) {
		tablas.push_back(new CTabla(nombre));
		++cantidaddetablas;
	}
	void igualartabla(CTabla* antigua){
		this->tablaauxiliardefinida = antigua;
	}
	CTabla* gettablainpos(int pos) {
		return tablas.at(pos);
	}
	CTabla* gettablaauxdefinida() {
		return this->tablaauxiliardefinida;
	}
	void settablaauxdefinida(CTabla* tablaauxiliar) {
		this->tablaauxiliardefinida = tablaauxiliar;
	}
	CTabla* gettablaauxnodefinida() {
		return this->tablaauxiliarnodefinida;
	}
	int getcantidaddetablas() {
		return this->cantidaddetablas;
	}
	void constructortablanodefinida() {
		this->tablaauxiliarnodefinida = new CTabla("");
	}
	void destructortablanodefinida() {
		delete this->tablaauxiliarnodefinida;
	}
	CBasededatos() {
		this->cantidaddetablas = 0;
		constructortablanodefinida();
	}
	~CBasededatos() {
		tablas.clear();
		delete tablaauxiliardefinida;
		delete tablaauxiliarnodefinida;
	}
};

#endif
//disenowebakus.net / tipos - de - datos - mysql.php