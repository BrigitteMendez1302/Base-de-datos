#pragma once
#ifndef CARBOL_HPP
#define CARBOL_HPP
#include "CListadoble.hpp"
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
	void _buscarMayor(function <void(G)>criterio_impresion) {
		CNodoarbol<G>* mayor = raiz;
		while (mayor->derecha != nullptr) {
			mayor = mayor->derecha;
		}
		criterio_impresion(mayor->valor);
	}

	void _buscarMenor(function <void(G)>criterio_impresion) {
		CNodoarbol<G>* menor = raiz;
		while (menor->izquierda != nullptr) {
			menor = menor->izquierda;
		}
		criterio_impresion(menor->valor);
	}
	int _cantidad(CNodoarbol<G>* nodo) {
		if (nodo == nullptr) return 0;
		else {
			int cantidad_izquierda, cantidad_derecha;
			cantidad_izquierda = _cantidad(nodo->izquierda);
			cantidad_derecha = _cantidad(nodo->derecha);
			//Se le suma 1: incluímos al nodo actual
			return 1 + cantidad_izquierda + cantidad_derecha;
		}
	}
	int _altura(CNodoarbol<G>* nodo) {
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
	void _guardarDatosEnLista(CNodoarbol<G>* nodo, CLista<G>*& lista) {
		if (nodo == nullptr)return;
		else {
			_guardarDatosEnLista(nodo->izquierda, lista);
			lista->insertarAlFinal(nodo->valor);
			_guardarDatosEnLista(nodo->derecha, lista);
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
		_buscarMayor(criterio_impresion);
	}
	void cargarListaConDatos(CLista<G>*& lista) {
		_guardarDatosEnLista(raiz, lista);
	}
	void buscarMenor(function <void(G)>criterio_impresion) {
		_buscarMenor(criterio_impresion);
	}
};

#endif