#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>

template<class T>
struct Triangle {
	std::pair<T, T> Cord;
	T Side;

	Triangle(const std::pair<T, T> & cord, T side) : Cord(cord), Side(side) {}
};

template<class T>
T CalcSquare(const Triangle<T> & Tri) {
	return Tri.Side * Tri.Side * (std::pow(3, 0.5) / 4);
}

template<class T>
std::ostream & operator << (std::ostream & out, const Triangle<T> & tri) {
	out << "Triangle {";
	out << std::pair<T, T>(tri.Cord.first, tri.Cord.second) << ", ";
	out << std::pair<T, T>(tri.Cord.first + 0.5 * tri.Side, tri.Cord.second + tri.Side * (std::pow(3, 0.5) / 2)) << ", ";
	out << std::pair<T, T>(tri.Cord.first + tri.Side, tri.Cord.second);
	out << "}";
	return out;
}

#endif
