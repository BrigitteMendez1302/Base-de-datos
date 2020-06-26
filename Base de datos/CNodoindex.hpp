#ifndef __CNODOINDEX_HPP__
#define __CNODOINDEX_HPP__
#include <vector>
using namespace std;
class CNodoindex
{
public:
	CNodoindex(string mivalor, string apuntoamifila) {
		this->mivalor = mivalor;
		this->apuntoamifila = apuntoamifila;
	}
	CNodoindex() {}
	~CNodoindex() {
		apuntoamifila.clear();
	}
	void setvalor(string mivalor) {
		this->mivalor = mivalor;
	}

private:
	string mivalor;
	string apuntoamifila; 
};
#endif // !__CNODOINDEX_HPP
