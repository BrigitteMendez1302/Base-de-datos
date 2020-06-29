#pragma once
#ifndef CLISTA_HPP
#define CLISTA_HPP
template<class T>
class CLista
{
private:

	template <class T>

	class CNodo
	{
	public:
		CNodo() {
			this->anterior = this->siguiente = nullptr;
		}
		~CNodo() {
			delete this->anterior;
			delete this->siguiente;
		}
		T elemento;
		CNodo<T>* anterior;
		CNodo<T>* siguiente;
	};

	CNodo<T>* inicio;
	CNodo<T>* fin;
	long long cantidad;

public:
	CLista() {
		this->inicio = this->fin = nullptr;
		cantidad = 0;
	}
	~CLista() {
		delete this->inicio;
		delete this->fin;
	}

	void insertarAlInicio(T e) {
		CNodo<T>* nuevo = new CNodo<T>();
		nuevo->elemento = e;
		if (cantidad > 0) {
			nuevo->siguiente = inicio;
			inicio->anterior = nuevo;
			inicio = nuevo;
		}
		else {
			inicio = fin = nuevo;
		}
		cantidad++;
	}
	void insertarAlFinal(T e) {
		if (cantidad > 0) {
			CNodo<T>* nuevo = new CNodo<T>();
			nuevo->elemento = e;
			fin->siguiente = nuevo;
			nuevo->anterior = fin;
			fin = nuevo;
			cantidad++;
		}
		else {
			insertarAlInicio(e);
		}
	}
	void insertarEnPosicion(long long posicion, T e) {
		if (posicion >= 0) {
			if (posicion == 0) {
				insertarAlInicio(e);
			}
			else if (posicion >= cantidad - 1) {
				insertarAlFinal(e);
			}
			else {
				CNodo<T> *nuevo = new CNodo<T>();
				nuevo->elemento = e;
				CNodo<T>* auxiliar = inicio;
				long long contador = 0;
				while (contador != posicion - 1) {
					auxiliar = auxiliar->siguiente;
					contador++;
				}
				auxiliar->siguiente->anterior = nuevo;
				nuevo->siguiente = auxiliar->siguiente;
				nuevo->anterior = auxiliar;
				auxiliar->siguiente = nuevo;
				cantidad++;
			}
		}
	}

	void eliminarAlPrincipio() {
		if (cantidad > 0) {
			if (cantidad == 1) {
				inicio = fin = nullptr;
			}
			else {
				CNodo<T>* porEliminar = inicio;
				inicio = porEliminar->siguiente;
				porEliminar->siguiente->anterior = nullptr;
				porEliminar->siguiente = nullptr;
				delete porEliminar;
			}
			cantidad--;
		}
	}
	void eliminarAlFinal() {
		if (cantidad > 0) {
			if (cantidad == 1) {
				eliminarAlPrincipio();
			}
			else {
				CNodo<T>* porEliminar = fin;
				porEliminar->anterior->siguiente = nullptr;
				fin = porEliminar->anterior;
				porEliminar->anterior = nullptr;
				delete porEliminar;
				cantidad--;
			}
		}
	}
	void eliminarEnPosicion(long long posicion) {
		if (posicion < cantidad && posicion >= 0) {
			if (posicion == 0) {
				eliminarAlPrincipio();
			}
			else if (posicion == cantidad - 1) {
				eliminarAlFinal();
			}
			else {
				CNodo<T>* auxiliar = inicio;
				long long contador = 0;
				while (contador != posicion - 1) {
					auxiliar = auxiliar->siguiente;
					contador++;
				}
				CNodo<T>* porEliminar = auxiliar->siguiente;
				auxiliar->siguiente = porEliminar->siguiente;
				porEliminar->siguiente->anterior = auxiliar;
				porEliminar->anterior = nullptr;
				porEliminar->siguiente = nullptr;
				delete porEliminar;
				cantidad--;
			}
		}
	}

	T obtenerElemento(long long posicion) {
		if (posicion < cantidad && posicion >= 0) {
			CNodo<T>* auxiliar = inicio;
			long long contador = 0;
			while (contador != posicion) {
				auxiliar = auxiliar->siguiente;
				contador++;
			}
			return auxiliar->elemento;
		}
	}
	void eliminarelementos() {
		while (!esVacio())
		{
			this->eliminarAlFinal();
		}
	}
	bool esVacio() { return cantidad == 0; }

	short size() { return cantidad; }
};
#endif