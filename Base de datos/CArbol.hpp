#pragma once
#ifndef CARBOL_HPP
#define CARBOL_HPP
#include "CNodoindex.hpp"
template<class T>
class Arbol
{
private:

	template <class T>

	class NodoArbol
	{
	public:
		NodoArbol() {
			this->izquierda = this->derecha = nullptr;
		}
		~NodoArbol() {
			delete this->izquierda;
			delete this->derecha;
		}
		T elemento;
		NodoArbol<T>* izquierda;
		NodoArbol<T>* derecha;
	};

	NodoArbol<T>* raiz;

	void _insertar(NodoArbol<T>*& nodo, T e) {
		if (nodo == nullptr) {
			nodo = new NodoArbol<T>();
			nodo->elemento = e;
		}
		else if (e < nodo->elemento) {
			_insertar(nodo->izquierda, e);
		}
		else if (e >= nodo->elemento) {
			_insertar(nodo->derecha, e);
		}
	}

	void _enOrden(NodoArbol<T>* nodo) {
		if (nodo == nullptr) return;
		_enOrden(nodo->izquierda);
		cout << nodo->elemento << " ";
		_enOrden(nodo->derecha);
	}

	bool _buscar(NodoArbol<T>* nodo, T e) {
		if (nodo == nullptr) return false;
		else {
			if (e == nodo->elemento) return true;
			else if (e >= nodo->elemento) {
				return _buscar(nodo->derecha, e);
			}
			else {
				return _buscar(nodo->izquierda, e);
			}
		}
	}

	NodoArbol<T>* _obtener(NodoArbol<T>* nodo, T e) {
		if (nodo == nullptr) return false;
		else {
			if (e == nodo->elemento) return nodo;
			else if (e >= nodo->elemento) {
				return _buscar(nodo->derecha, e);
			}
			else {
				return _buscar(nodo->izquierda, e);
			}
		}
	}

	int _cantidad(NodoArbol<T>* nodo) {
		if (nodo == nullptr) return 0;
		else {
			int cantidad_izquierda, cantidad_derecha;
			cantidad_izquierda = _cantidad(nodo->izquierda);
			cantidad_derecha = _cantidad(nodo->derecha);
			//Se le suma 1: incluímos al nodo actual
			return 1 + cantidad_izquierda + cantidad_derecha;
		}
	}

	int _altura(NodoArbol<T>* nodo) {
		//Al llegar a los "extremos" de las hojas
		if (nodo == nullptr) return 0;
		else {
			int altura_izquierda, altura_derecha;
			//Obtener la altura de nodos hijos de la izquierda
			altura_izquierda = 1 + _altura(nodo->izquierda);
			//Obtener la alutra de nodos hijos de la derecha
			altura_derecha = 1 + _altura(nodo->derecha);
			//Se le suma 1: incluímos al nodo actual
			return altura_izquierda > altura_derecha ? altura_izquierda : altura_derecha;
		}
	}

	T _minimo(NodoArbol<T>* nodo) {
		if (nodo->izquierda == nullptr) return nodo->elemento;
		else {
			return _minimo(nodo->izquierda);
		}
	}

	T _maximo(NodoArbol<T>* nodo) {
		if (nodo->derecha == nullptr) return nodo->elemento;
		else {
			return _maximo(nodo->derecha);
		}
	}
	T _buscarMayor() {
		NodoArbol<T>* mayor = raiz;
		while (mayor->derecha != nullptr) {
			mayor = mayor->derecha;
		}
		return mayor->elemento;
	}

	void _buscarMenor(function <void(T)>criterio_impresion) {
		NodoArbol<T>* menor = raiz;
		while (menor->izquierda != nullptr) {
			menor = menor->izquierda;
		}
		criterio_impresion(menor->elemento);
	}
public:
	Arbol() {
		this->raiz = nullptr;
	}
	~Arbol() {
		delete this->raiz;
	}
	void insertar(T e) {
		_insertar(raiz, e);
	}
	void enOrden() {
		_enOrden(raiz);
	}
	bool buscar(T e) {
		return _buscar(raiz, e);
	}
	NodoArbol<T>* obtener(T e) {
		return _obtener(raiz, e);
	}

	int cantidad() {
		return _cantidad(raiz);
	}
	int altura() {
		return _altura(raiz);
	}
	int minimo() {
		return _minimo(raiz);
	}
	int maximo() {
		return _maximo(raiz);
	}
	void buscarMayor(function <void(T)>criterio_impresion) {
		stack<T> mayores;
		T mayor = _buscarMayor();
		NodoArbol<T>* aux = raiz;
		while (aux->derecha != nullptr) {
			if (aux->elemento == mayor) mayores.push(aux->elemento);
			aux = aux->derecha;
			mayores.pop();
		}
		mayores.push(mayor);
		while (!mayores.empty()) {
			criterio_impresion(mayores.top());
			mayores.pop();
		}
	}

	void buscarMenor(function <void(T)>criterio_impresion) {
		_buscarMenor(criterio_impresion);
	}
};
template <class G>
class CArbolbb {
private:
	template <class G>
	class CNodoarbol {
	public:
		CNodoarbol<G> * derecha;
		CNodoarbol<G> * izquierda;
		G valor;
		CNodoarbol(G v) {
			valor = v;
			derecha = izquierda = nullptr;
		}
	};
	CNodoarbol<G> *raiz;
	long cantidad;
private:
	G _buscarMayor() {
		CNodoarbol<G>* mayor = raiz;
		while (mayor->derecha != nullptr) {
			mayor = mayor->derecha;
		}
		return mayor->valor;
	}

	void _buscarMenor(function <void(G)>criterio_impresion) {
		CNodoarbol<G>* menor = raiz;
		while (menor->izquierda != nullptr) {
			menor = menor->izquierda;
		}
		criterio_impresion(menor->valor);
	}

	void _insertar(CNodoarbol<G> *& nodo, G& valor, function<bool(G, G)> criterio) {
		if (nodo == nullptr) {
			nodo = new CNodoarbol<G>(valor);
			++cantidad;
		}
		else if (criterio(valor, nodo->valor)) {
			_insertar(nodo->izquierda, valor, criterio);
		}
		else {
			_insertar(nodo->derecha, valor, criterio);
		}

	}
	void _buscar(CNodoarbol<G> * nodo, G valor, bool& encontrar) {
		if (nodo == nullptr) {
			encontrar = false;
		}
		else {
			if (nodo->valor == valor) {
				encontrar = true; return;
			}
			if (valor <= nodo->valor) {
				_buscar(nodo->izquierda, valor, encontrar);
			}
			else {
				_buscar(nodo->derecha, valor, encontrar);
			}
		}
	}

	void _mostrar_orden(CNodoarbol<G> * nodo) {
		if (nodo == nullptr)return;
		else {
			_mostrar_orden(nodo->derecha);
			cout << nodo->valor << " ";
			_mostrar_orden(nodo->izquierda);
		}
	}

	void _enorden(CNodoarbol<G> * nodo, function<void(G)> criterio_impresion) {
		if (nodo == nullptr)return;
		else {
			_enorden(nodo->izquierda, criterio_impresion);
			criterio_impresion(nodo->valor);
			_enorden(nodo->derecha, criterio_impresion);
		}
	}

	void _preorden(CNodoarbol<G> * nodo, function<void(G)> criterio_impresion) {
		if (nodo == nullptr)return;
		else {
			criterio_impresion(nodo->valor);
			_preorden(nodo->izquierda, criterio_impresion);
			_preorden(nodo->derecha, criterio_impresion);
		}
	}


	void _posorden(CNodoarbol<G> * nodo, function<void(G)> criterio_impresion) {
		if (nodo == nullptr)return;
		else {
			_posorden(nodo->izquierda, criterio_impresion);
			_posorden(nodo->derecha, criterio_impresion);
			criterio_impresion(nodo->valor);
		}
	}

	void _borrar_todo(CNodoarbol<G> * nodo) {
		if (nodo != nullptr) {
			_borrar_todo(nodo->izquierda);
			_borrar_todo(nodo->derecha);
			delete nodo;
		}
	}
public:
	CArbolbb() { raiz = nullptr; cantidad = 0; }
	~CArbolbb() {}
	void insertar(G v, function<bool(G, G)> criterio) {
		_insertar(raiz, v, criterio);
	}
	bool buscar(G v) {
		bool encontrado = false;
		_buscar(raiz, v, encontrado);
		return encontrado;
	}
	void borrar_todo() {
		_borrar_todo(raiz);
	}
	void mostrar_orden() {
		_mostrar_orden(raiz);
	}
	void enorden(function <void(G)>criterio_impresion) {
		_enorden(raiz, criterio_impresion);
	}
	void preorden(function <void(G)>criterio_impresion) {
		_preorden(raiz, criterio_impresion);
	}
	void posorden(function <void(G)>criterio_impresion) {
		_posorden(raiz, criterio_impresion);
	}
	void buscarMayor(function <void(G)>criterio_impresion) {
		stack<G> mayores;
		G mayor = _buscarMayor();
		CNodoarbol<G>* aux = raiz;
		while (aux->derecha != nullptr) {
			if (aux->valor == mayor) mayores.push(aux->valor);
			aux = aux->derecha;
			mayores.pop();
		}
		mayores.push(mayor);
		while (!mayores.empty()) {
			criterio_impresion(mayores.top());
			mayores.pop();
		}
	}
	void buscarMenor(function <void(G)>criterio_impresion) {
		_buscarMenor(criterio_impresion);
	}
};

#endif