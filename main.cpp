#include "quad.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

using IntVertex = std::pair<int, int>;

using DoubleVertex = std::pair<long double, long double>;

template<class T1, class T2>
std::ostream & operator << (std::ostream & out, const std::pair<T1, T2> & p) {
	out << "(" << p.first << ", " << p.second << ")";
	return out;
}

template<class T, size_t index = 0>
void PrintTuple(T & tup) {
	if constexpr(index < std::tuple_size<T>::value) {
		std::cout << std::get<index>(tup) << std::endl;
		PrintTuple<T, index + 1>(tup);
	}
}

template<class T, size_t index = 0>
long double TotalSquare(T & tup) {
	if constexpr(index < std::tuple_size<T>::value) {
		return (long double)CalcSquare(std::get<index>(tup)) + TotalSquare<T, index + 1>(tup);
	} else {
		return 0;
	}
}

int main() {
	Quad<int> quadInt(IntVertex(0, 0), 1);
	Rectangle<int> rectangleInt(DoubleVertex(5, 5), 2, 3);
	Triangle<int> triangleInt(IntVertex(1, 1), 6);

	Quad<long double> quadDouble = {DoubleVertex(-0.5, -0.5), 2};
	Rectangle<long double> rectangleDouble(DoubleVertex(-5.0, -2.5), 5.0, 2.5);
	Triangle<long double> triangleDouble(DoubleVertex(-10.0, -10.0), 5.5);

	auto tup = std::make_tuple(quadInt, rectangleInt, triangleInt, quadDouble, rectangleDouble, triangleDouble);
	PrintTuple(tup);
	std::cout << "Total square is " << TotalSquare(tup) << std::endl;
	return 0;
}
