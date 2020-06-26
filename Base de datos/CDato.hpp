#ifndef __CDATO_HPP__
#define __CDATO_HPP__
template<class G>
class CDato
{
public:
	CDato(G dato){
		this->dato = dato;
	}
	CDato() {
	}
	~CDato(){}
	G getdato() {
		return dato;
	}
	void setdato(G dato) {
		this->dato = dato;
	}
private:
	G dato;
};
#endif
