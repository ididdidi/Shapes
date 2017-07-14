#include "ShapesDll.h"
	// Методы базлового классса Shape
Shape::~Shape() 
{ }
	// вывести параметры фигуры на экран
void Shape::showSets()const
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
{ 
	if(lengthAB<0 || lengthAC<0)
		throw SizeError("Initialization error", "Side must be greater than zero!");
	else{
		if (aBAC <= 0 || aBAC >= 180)
			throw SizeError("Initialization error",
				"The angle must be greater than zero and less than 180!");
		else{
			sideAB = lengthAB; 
			sideAC = lengthAC; 
			anglBAC = aBAC;
		}
	}
}
	// посчитать и вернуть площадь фигуры
double Triangle::getArea()const
{
	return (sideAB*sideAC*sin(anglBAC*3.14159265/180))/2;
}
	// вывести параметры фигуры на экран
void Triangle::showSets()const
{
	Shape::showSets();
	std::cout << ":\tSide AB = " << sideAB << ",\tSide AC = " << sideAC 
		<< ",\tAngl BAC = " << anglBAC << ";";
}
	// редактировать параметры фигуры
void Triangle::editShape()
{
	Shape::editShape(); // редактирование полей базового класса
	float tmpAB, tmpAC, tmpBAC;
	std::cout << " Enter the side AB... ";	std::cin >> tmpAB;
	std::cout << " Enter the side AC... ";	std::cin >> tmpAC;
	std::cout << " Enter the angl BAC... ";	std::cin >> tmpBAC;
	if (tmpAB<0 || tmpAC<0)
		throw SizeError("Edit Shape error", "Side must be greater than zero!");
	else {
		if (tmpBAC <= 0 || tmpBAC >= 180)
			throw SizeError("Edit Shape error", "The angle must be greater than zero and less than 180!");
		else {
			sideAB = tmpAB;
			sideAC = tmpAC;
			anglBAC = tmpBAC;
		}
	}
}

	// Методы классса Rectangle
Rectangle::Rectangle(float lengthA, float lengthB)
{ 
	if (lengthA<0 || lengthB<0)
		throw SizeError("Initialization error", "Side must be greater than zero!");
	else {
		sideA = lengthA;
		sideB = lengthB;
	}
}
	// посчитать и вернуть площадь фигуры
double Rectangle::getArea()const
{
	return sideA * sideB;
}
	// вывести параметры фигуры на экран
void Rectangle::showSets()const
{
	Shape::showSets();
	std::cout << ":\tWidth = " << sideA << ",\tHeight = " << sideB << ";";
}
	// редактировать параметры фигуры
void Rectangle::editShape()
{
	Shape::editShape(); // редактирование полей базового класса
	float lengthA, lengthB;
	std::cout << " Enter the width... ";	std::cin >> lengthA;
	std::cout << " Enter the height... ";	std::cin >> lengthB;
	if (sideA<0 || sideB<0)
		throw SizeError("Edit Shape error", "Side must be greater than zero!");
	else {
		sideA = lengthA;
		sideB = lengthB;
	}
}

	// Методы классса RegularPolygons
RegPolygons::RegPolygons(int nAngles, float lSide)
{
	if (nAngles<3)
		throw SizeError("Initialization error", "The number of angles must be greater than three!");
	else {
		if (lSide<0)
			throw SizeError("Initialization error", "Side must be greater than zero!");
		else {
			numAngles = nAngles;
			side = lSide;
		}
	}
}
	// посчитать и вернуть площадь фигуры
double RegPolygons::getArea()const
{
	return  (numAngles * side*side) / (4 * tan(3.14159265 / numAngles));
}
	// вывести параметры фигуры на экран
void RegPolygons::showSets()const
{
	Shape::showSets();
	std::cout << ":\tNumber of sides = " << numAngles << ",\tlength of the sides = " << side << ";";
}
	// редактировать параметры фигуры
void RegPolygons::editShape()
{
	Shape::editShape(); // редактирование полей базового класса
	float nAngles, lSide;
	std::cout << " Enter the number of sides... ";	std::cin >> nAngles;
	std::cout << " Enter the length of the side... ";	std::cin >> lSide;
	if (nAngles<3)
		throw SizeError("Edit Shape error", "The number of angles must be greater than three!");
	else {
		if (lSide < 0)
			throw SizeError("Edit Shape error", "Side must be greater than zero!");
		else {
			numAngles = nAngles;
			side = lSide;
		}
	}
}

	// функция форматирования строки вывода
const char* formatS(const char* strs)
{
	return strs + 6;		// смещаем указатель на шесьт символов впарво
}