#ifndef QUAD_HPP
#define QUAD_HPP

#include <iostream>
#include <tuple>
#include <vector>

template<class T>
struct Quad {
	std::pair<T, T> Cord;
	T Side;

	Quad(const std::pair<T, T> & cord, T side) : Cord(cord), Side(side) {}
};

template<class T>
T CalcSquare(const Quad<T> & Sq) {
	return Sq.Side * Sq.Side;
}

template<class T>
std::ostream & operator << (std::ostream & out, const Quad<T> & sq) {
	out << "Quadrate {";
	out << std::pair<T, T>(sq.Cord.first, sq.Cord.second) << ", ";
	out << std::pair<T, T>(sq.Cord.first, sq.Cord.second + sq.Side) << ", ";
	out << std::pair<T, T>(sq.Cord.first + sq.Side, sq.Cord.second + sq.Side) << ", ";
	out << std::pair<T, T>(sq.Cord.first + sq.Side, sq.Cord.second);
	out << "}";
	return out;
}

#endif
