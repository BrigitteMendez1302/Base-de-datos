#ifndef CARBOL_HPP
#define CARBOL_HPP
#include "CListadoble.hpp"
template <class G>
class CArbolavl
{
	template <class G>
	class CNodoavl {
	public:
		G valor;
		CNodoavl<G>* izquierda;
		CNodoavl<G>* derecha;
		int h;
		CNodoavl(G v) {
			this->valor = v;
			izquierda = derecha = nullptr;
			h = 0;
		}
		~CNodoavl() {
			delete izquierda;
			delete derecha;
		}
	};
	CNodoavl<G> * raiz;
	long long cantidad;

	void _eliminarTodo(CNodoavl<G>* node) {
		if (node != nullptr) {
			_eliminarTodo(node->izquierda);
			_eliminarTodo(node->derecha);
			balance(node);
			delete node;
		}
	}

	void _buscarMayor(function <void(G)>criterio_impresion) {
		CNodoavl<G>* mayor = raiz;
		while (mayor->derecha != nullptr) {
			mayor = mayor->derecha;
		}
		criterio_impresion(mayor->valor);
	}
	void _buscarMenor(function <void(G)>criterio_impresion) {
		CNodoavl<G>* menor = raiz;
		while (menor->izquierda != nullptr) {
			menor = menor->izquierda;
		}
		criterio_impresion(menor->valor);
	}

	void _enOrden(CNodoavl<G>* nodo, function<void(G)> criterio_impresion) {
		if (nodo != nullptr) {
			_enOrden(nodo->izquierda, criterio_impresion);
			criterio_impresion(nodo->valor);
			_enOrden(nodo->derecha,criterio_impresion);
		}
	}

	void _rotacionizq(CNodoavl<G>* x, CNodoavl<G>* y, CNodoavl<G>*&r) {
		r = y;
		x->derecha = y->izquierda;
		x->h = _altura(x);
		y->izquierda = x;
		y->h = _altura(r);
	}

	void _rotacionder(CNodoavl<G>* x, CNodoavl<G>* y, CNodoavl<G>*&r) {
		r = x;
		y->izquierda = x->derecha;
		y->h = _altura(y);
		x->derecha = y;
		x->h = _altura(r);
	}

	int _altura(CNodoavl<G>* node) {
		if (node == nullptr) {
			return -1;
		}
		int hl = _altura(node->izquierda);
		int hr = _altura(node->derecha);
		return 1 + (hl > hr ? hl : hr);
	}

	void balance(CNodoavl<G>*& node) {
		int hl = _altura(node->izquierda);
		int hr = _altura(node->derecha);
		int dif = hr - hl;
		if (dif > 1) {
			int hrr = _altura(node->derecha->derecha);
			int hrl = _altura(node->derecha->izquierda);
			if (hrl > hrr) {
				_rotacionder(node->derecha->izquierda, node->derecha, node->derecha);
			}
			_rotacionizq(node, node->derecha, node);
		}
		else if (dif < -1) {
			int hlr = _altura(node->izquierda->derecha);
			int hll = _altura(node->izquierda->izquierda);
			if (hll < hlr) {
				_rotacionizq(node->izquierda, node->izquierda->derecha, node->izquierda);
			}
			_rotacionder(node->izquierda, node, node);

		}
	}
	void _agregar(CNodoavl<G>*& node, G& value, function<bool(G, G)> criterio) {
		if (node == nullptr) {
			node = new CNodoavl<G>(value);
			++cantidad;
		}
		else if (criterio(value, node->valor)) {
			_agregar(node->izquierda, value, criterio);
		}
		else {
			_agregar(node->derecha, value, criterio);
		}

		balance(node);
		node->h = _altura(node);
	}
	void _guardarDatosEnLista(CNodoavl<G>* nodo, CLista<G>*& lista) {
		if (nodo == nullptr)return;
		else {
			_guardarDatosEnLista(nodo->izquierda, lista);
			lista->insertarAlFinal(nodo->valor);
			_guardarDatosEnLista(nodo->derecha, lista);
		}
	}
public:
	CArbolavl() {
		raiz = nullptr;
		this->cantidad = 0;
	}
	~CArbolavl() {
		delete this->raiz;
	}
	void eliminarTodo() {
		_eliminarTodo(raiz);
	}
	void enorden(function <void(G)>criterio_impresion) {
		_enOrden(raiz, criterio_impresion);
	}
	void insertar(G value, function<bool(G, G)> criterio) {
		_agregar(raiz, value, criterio);
	}
	int Altura() {
		return _altura(raiz);
	}
	int getsize() {
		return this->cantidad;
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
