#pragma once
#include <iostream>

template<class T>

class Coordenada
{
public:
	T x;
	T y;
public:
	Coordenada();
	Coordenada(T xc, T yc);
	~Coordenada() { };
	Coordenada<T> operator+ (Coordenada<T> vector2);
	void operator- (Coordenada<T> vector2);
	void operator= (Coordenada<T> vector2);
	void operator+= (Coordenada<T> vector2);
	Coordenada<T> operator* (T escalar);
	//Coordenada<TYPE> operator* (TYPE number);
	//Coordenada<TYPE> operator/ (TYPE number);
};

template<class T>
Coordenada<T>::Coordenada()
{
	x = 0;
	y = 0;
}

template<class T>
Coordenada<T>::Coordenada(T xc, T yc) // x coordenada e y coordenada
{
	x = xc;
	y = yc;
}

template<class T>
Coordenada<T> Coordenada<T>::operator+ (Coordenada<T> vector2)
{
	Coordenada<T> result;
	x += vector2.x;
	y += vector2.y;
	result.x = x, result.y = y;
	return result;
}

template<class T>
void Coordenada<T>::operator- (Coordenada<T> vector2)
{
	x -= vector2.x;
	y -= vector2.y;
}

template<class T>
void Coordenada<T>::operator= (Coordenada<T> vector2)
{
	x = vector2.x;
	y = vector2.y;
}

template<class T>
void Coordenada<T>::operator+= (Coordenada<T> vector2)
{
	x += vector2.x;
	y += vector2.y;
}

template<class T>
Coordenada<T> Coordenada<T>::operator* (T escalar)
{
	Coordenada<T> coord(x *= escalar, y *= escalar);
	return coord;
}