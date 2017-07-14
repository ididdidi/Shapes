#include "ShapesDll.h"
	// ������ ��������� ������� Shape
Shape::~Shape() 
{ }
	// ������� ��������� ������ �� �����
void Shape::showSets()const
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
	// ��������� � ������� ������� ������
double Triangle::getArea()const
{
	return (sideAB*sideAC*sin(anglBAC*3.14159265/180))/2;
}
	// ������� ��������� ������ �� �����
void Triangle::showSets()const
{
	Shape::showSets();
	std::cout << ":\tSide AB = " << sideAB << ",\tSide AC = " << sideAC 
		<< ",\tAngl BAC = " << anglBAC << ";";
}
	// ������������� ��������� ������
void Triangle::editShape()
{
	Shape::editShape(); // �������������� ����� �������� ������
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

	// ������ ������� Rectangle
Rectangle::Rectangle(float lengthA, float lengthB)
{ 
	if (lengthA<0 || lengthB<0)
		throw SizeError("Initialization error", "Side must be greater than zero!");
	else {
		sideA = lengthA;
		sideB = lengthB;
	}
}
	// ��������� � ������� ������� ������
double Rectangle::getArea()const
{
	return sideA * sideB;
}
	// ������� ��������� ������ �� �����
void Rectangle::showSets()const
{
	Shape::showSets();
	std::cout << ":\tWidth = " << sideA << ",\tHeight = " << sideB << ";";
}
	// ������������� ��������� ������
void Rectangle::editShape()
{
	Shape::editShape(); // �������������� ����� �������� ������
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

	// ������ ������� RegularPolygons
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
	// ��������� � ������� ������� ������
double RegPolygons::getArea()const
{
	return  (numAngles * side*side) / (4 * tan(3.14159265 / numAngles));
}
	// ������� ��������� ������ �� �����
void RegPolygons::showSets()const
{
	Shape::showSets();
	std::cout << ":\tNumber of sides = " << numAngles << ",\tlength of the sides = " << side << ";";
}
	// ������������� ��������� ������
void RegPolygons::editShape()
{
	Shape::editShape(); // �������������� ����� �������� ������
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

	// ������� �������������� ������ ������
const char* formatS(const char* strs)
{
	return strs + 6;		// ������� ��������� �� ����� �������� ������
}