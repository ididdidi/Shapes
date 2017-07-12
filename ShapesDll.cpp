#include "ShapesDll.h"
	// ������ ��������� ������� Shape
Shape::~Shape() 
{ }
	// ������� ��������� ������ �� �����
void Shape::display()
{
	std::cout << formatS(typeid(*this).name()); // ����� �������� ����� � ����� �������� ������
}
	// ������������� ��������� ������
void Shape::editShape()
{
	std::cout << "\tEdit the " << formatS(typeid(*this).name()) << std::endl;
	// �������������� ����� �������� ������
}

	// ������ ������� Triangle
Triangle::Triangle(float lengthAB, float lengthAC, float aBAC) 
	: sideAB(lengthAB), sideAC(lengthAC), anglBAC(aBAC)
{ }
	// ��������� � ������� ������� ������
double Triangle::getArea()
{
	return (sideAB*sideAC*sin(anglBAC*3.14159265/180))/2;
}
	// ������� ��������� ������ �� �����
void Triangle::display()
{
	Shape::display();
	std::cout << " - Side AB: " << sideAB << ", Side AC: " << sideAC 
		<< ", Angl BAC:" << anglBAC << ";";
}
	// ������������� ��������� ������
void Triangle::editShape()
{
	Shape::editShape(); // �������������� ����� �������� ������
	std::cout << " Enter the side AB... ";	std::cin >> sideAB;
	std::cout << " Enter the side AC... ";	std::cin >> sideAC;
	std::cout << " Enter the angl BAC... ";	std::cin >> anglBAC;
}

	// ������ ������� Rectangle
Rectangle::Rectangle(float lengthA, float lengthB) : sideA(lengthA), sideB(lengthB)
{ }
	// ��������� � ������� ������� ������
double Rectangle::getArea()
{
	return sideA * sideB;
}
	// ������� ��������� ������ �� �����
void Rectangle::display()
{
	Shape::display();
	std::cout << " - Width: " << sideA << ", Height: " << sideB << ";";
}
	// ������������� ��������� ������
void Rectangle::editShape()
{
	Shape::editShape(); // �������������� ����� �������� ������
	std::cout << " Enter the width... ";	std::cin >> sideA;
	std::cout << " Enter the height... ";	std::cin >> sideB;
}

	// ������ ������� RegularPolygons
RegularPolygons::RegularPolygons(int nAngles, float lSide) : numAngles(nAngles), side(lSide)
{ }
	// ��������� � ������� ������� ������
double RegularPolygons::getArea()
{
	return  (numAngles * side*side) / (4 * tan(3.14159265 / numAngles));
}
	// ������� ��������� ������ �� �����
void RegularPolygons::display()
{
	Shape::display();
	std::cout << " - Number of sides: " << numAngles << ", length of the sides: " << side << ";";
}
	// ������������� ��������� ������
void RegularPolygons::editShape()
{
	Shape::editShape(); // �������������� ����� �������� ������
	std::cout << " Enter the number of sides... ";	std::cin >> numAngles;
	std::cout << " Enter the length of the side... ";	std::cin >> side;
}

	// ������� �������������� ������ ������
const char* formatS(const char* strs)
{
	return strs + 6;		// ������� ��������� �� ����� �������� ������
}