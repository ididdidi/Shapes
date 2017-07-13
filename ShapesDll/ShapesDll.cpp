#include "ShapesDll.h"
	// ������ ��������� ������� Shape
Shape::~Shape() 
{ }
	// ������� ��������� ������ �� �����
void Shape::display()const
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
double Triangle::getArea()const
{
	return (sideAB*sideAC*sin(anglBAC*3.14159265/180))/2;
}
	// ������� ��������� ������ �� �����
void Triangle::display()const
{
	Shape::display();
	std::cout << ":\tSide AB = " << sideAB << ",\tSide AC = " << sideAC 
		<< ",\tAngl BAC = " << anglBAC << ";";
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
double Rectangle::getArea()const
{
	return sideA * sideB;
}
	// ������� ��������� ������ �� �����
void Rectangle::display()const
{
	Shape::display();
	std::cout << ":\tWidth = " << sideA << ",\tHeight = " << sideB << ";";
}
	// ������������� ��������� ������
void Rectangle::editShape()
{
	Shape::editShape(); // �������������� ����� �������� ������
	std::cout << " Enter the width... ";	std::cin >> sideA;
	std::cout << " Enter the height... ";	std::cin >> sideB;
}

	// ������ ������� RegularPolygons
RegPolygons::RegPolygons(int nAngles, float lSide) : numAngles(nAngles), side(lSide)
{ }
	// ��������� � ������� ������� ������
double RegPolygons::getArea()const
{
	return  (numAngles * side*side) / (4 * tan(3.14159265 / numAngles));
}
	// ������� ��������� ������ �� �����
void RegPolygons::display()const
{
	Shape::display();
	std::cout << ":\tNumber of sides = " << numAngles << ",\tlength of the sides = " << side << ";";
}
	// ������������� ��������� ������
void RegPolygons::editShape()
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