#pragma once
#include <iostream>

/*

// Insipirado no codigo do monitor Burda, apresentado no vídeo:
// https://www.youtube.com/watch?v=xD3A4CDlwpI&t=167s

*/

template<class T>

class Coordinate
{
public:
	T x;
	T y;
public:
	Coordinate();
	Coordinate(T xc, T yc);
	~Coordinate() { };
	Coordinate<T> operator+ (Coordinate<T> vector2);
	void operator- (Coordinate<T> vector2);
	void operator= (Coordinate<T> vector2);
	void operator+= (Coordinate<T> vector2);
	Coordinate<T> operator* (T escalar);;
	Coordinate<T> operator/ (T escalar);
	//std::ostream& operator<<(std::ostream& COUT, Coordinate<T>& c);
};

template<class T>
Coordinate<T>::Coordinate()
{
	x = 0;
	y = 0;
}

template<class T>
Coordinate<T>::Coordinate(T xc, T yc) // x coordenada e y coordenada
{
	x = xc;
	y = yc;
}

template<class T>
Coordinate<T> Coordinate<T>::operator+ (Coordinate<T> vector2)
{
	Coordinate<T> result;
	x += vector2.x;
	y += vector2.y;
	result.x = x, result.y = y;
	return result;
}

template<class T>
void Coordinate<T>::operator- (Coordinate<T> vector2)
{
	x -= vector2.x;
	y -= vector2.y;
}

template<class T>
void Coordinate<T>::operator= (Coordinate<T> vector2)
{
	x = vector2.x;
	y = vector2.y;
}

template<class T>
void Coordinate<T>::operator+= (Coordinate<T> vector2)
{
	x += vector2.x;
	y += vector2.y;
}

template<class T>
Coordinate<T> Coordinate<T>::operator* (T escalar)
{
	Coordinate<T> coord(x * escalar, y * escalar);
	return coord;
}

template<class T>
Coordinate<T> Coordinate<T>::operator/ (T escalar)
{
	Coordinate<T> coord(x /= escalar, y /= escalar);
	return coord;
}

template<class T>
std::ostream& operator<<(std::ostream& COUT, Coordinate<T>& c)
{
	COUT << "x: " << c.x << " y: " << c.y << std::endl;
	return COUT;
}