#ifndef __CFILA_HPP__
#define __CFILA_HPP__
#include<string>
using namespace std;

class CFila
{
public:
	CFila(string mivalor) {
		this->mivalor = mivalor;
	}
	CFila() {}
	~CFila(){}
	void setvalor(string mivalor) {
		this->mivalor = mivalor;
	}
	string getvalor() {
		return this->mivalor;
	}
private:
	string mivalor;
};
#endif