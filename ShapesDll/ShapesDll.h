#ifndef SHAPESDLL_H
#define SHAPESDLL_H

#ifdef SHAPESDLL_EXPORTS
#define SHAPESDLL_API __declspec(dllexport) 
#else
#define SHAPESDLL_API __declspec(dllimport) 
#endif

#include <iostream>
#include <typeinfo>

	// ������� ����� ��� �������� �������������� �����
class Shape
{
protected:
	// ����� ����� ����������� ���� � ������ ������ ��� �������� ���� ���������� �������:
	// ���������� �������, ��� ����, ����� ���������� � ��.
public:
	SHAPESDLL_API Shape() = default;
	virtual SHAPESDLL_API ~Shape() = 0;
	virtual SHAPESDLL_API double getArea()const = 0;	// ��������� � ������� ������� ������
	virtual SHAPESDLL_API void display()const;			// ������� ��������� ������ �� �����
	virtual SHAPESDLL_API void editShape();				// ������������� ��������� ������
};

	// ����� ��� �������� �������������
class Triangle : public Shape
{
protected:
	float sideAB;
	float sideAC;
	float anglBAC;
public:
	SHAPESDLL_API Triangle(float lengthAB, float lengthAC, float aBAC);
	SHAPESDLL_API ~Triangle() = default;
	SHAPESDLL_API double getArea()const override;	// ��������� � ������� ������� ������
	SHAPESDLL_API void display()const override;		// ������� ��������� ������ �� �����
	SHAPESDLL_API void editShape() override;		// ������������� ��������� ������
};

	// ����� ��� �������� ���������������
class Rectangle : public Shape
{
protected:
	float sideA;
	float sideB;
public:
	SHAPESDLL_API Rectangle(float lengthA, float lengthB);
	SHAPESDLL_API ~Rectangle() = default;
	SHAPESDLL_API double getArea()const override;	// ��������� � ������� ������� ������
	SHAPESDLL_API void display()const override;		// ������� ��������� ������ �� �����
	SHAPESDLL_API void editShape() override;		// ������������� ��������� ������
};

	// ����� ��� �������� ���������� ���������������
class RegPolygons : public Shape
{
protected:
	int numAngles;
	float side;
public:
	SHAPESDLL_API RegPolygons(int nAngles, float lSide);
	SHAPESDLL_API ~RegPolygons() = default;
	SHAPESDLL_API double getArea()const override;	// ��������� � ������� ������� ������
	SHAPESDLL_API void display()const override;		// ������� ��������� ������ �� �����
	SHAPESDLL_API void editShape() override;		// ������������� ��������� ������
};
							
static const char* formatS(const char* strs);		// ������� �������������� ������ ������

#endif // !SHAPESDLL_H