#include "ShapesDll.h"
	// Методы базлового классса Shape
Shape::~Shape() 
{ }
	// вывести параметры фигуры на экран
void Shape::display()
{
	std::cout << formatS(typeid(*this).name()); // вывод названия фигур и полей базового класса
}
	// редактировать параметры фигуры
void Shape::editShape()
{
	std::cout << "\tEdit the " << formatS(typeid(*this).name()) << std::endl;
	// редактирование полей базового класса
}

	// Методы классса Triangle
Triangle::Triangle(float lengthAB, float lengthAC, float aBAC) 
	: sideAB(lengthAB), sideAC(lengthAC), anglBAC(aBAC)
{ }
	// посчитать и вернуть площадь фигуры
double Triangle::getArea()
{
	return (sideAB*sideAC*sin(anglBAC*3.14159265/180))/2;
}
	// вывести параметры фигуры на экран
void Triangle::display()
{
	Shape::display();
	std::cout << " - Side AB: " << sideAB << ", Side AC: " << sideAC 
		<< ", Angl BAC:" << anglBAC << ";";
}
	// редактировать параметры фигуры
void Triangle::editShape()
{
	Shape::editShape(); // редактирование полей базового класса
	std::cout << " Enter the side AB... ";	std::cin >> sideAB;
	std::cout << " Enter the side AC... ";	std::cin >> sideAC;
	std::cout << " Enter the angl BAC... ";	std::cin >> anglBAC;
}

	// Методы классса Rectangle
Rectangle::Rectangle(float lengthA, float lengthB) : sideA(lengthA), sideB(lengthB)
{ }
	// посчитать и вернуть площадь фигуры
double Rectangle::getArea()
{
	return sideA * sideB;
}
	// вывести параметры фигуры на экран
void Rectangle::display()
{
	Shape::display();
	std::cout << " - Width: " << sideA << ", Height: " << sideB << ";";
}
	// редактировать параметры фигуры
void Rectangle::editShape()
{
	Shape::editShape(); // редактирование полей базового класса
	std::cout << " Enter the width... ";	std::cin >> sideA;
	std::cout << " Enter the height... ";	std::cin >> sideB;
}

	// Методы классса RegularPolygons
RegularPolygons::RegularPolygons(int nAngles, float lSide) : numAngles(nAngles), side(lSide)
{ }
	// посчитать и вернуть площадь фигуры
double RegularPolygons::getArea()
{
	return  (numAngles * side*side) / (4 * tan(3.14159265 / numAngles));
}
	// вывести параметры фигуры на экран
void RegularPolygons::display()
{
	Shape::display();
	std::cout << " - Number of sides: " << numAngles << ", length of the sides: " << side << ";";
}
	// редактировать параметры фигуры
void RegularPolygons::editShape()
{
	Shape::editShape(); // редактирование полей базового класса
	std::cout << " Enter the number of sides... ";	std::cin >> numAngles;
	std::cout << " Enter the length of the side... ";	std::cin >> side;
}

	// функция форматирования строки вывода
const char* formatS(const char* strs)
{
	return strs + 6;		// смещаем указатель на шесьт символов впарво
}