#ifndef SHAPESDLL_H
#define SHAPESDLL_H

#ifdef SHAPESDLL_EXPORTS
#define SHAPESDLL_API __declspec(dllexport) 
#else
#define SHAPESDLL_API __declspec(dllimport) 
#endif

#include <iostream>
#include <typeinfo>
#include <string>

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
	virtual SHAPESDLL_API void showSets()const;			// ������� ��������� ������ �� �����
	virtual SHAPESDLL_API void editShape();				// ������������� ��������� ������
	class SizeError								// ����� ����������
	{
	public:
		std::string origin;						// ��� ����� �������
		std::string description;				// ��������
		SizeError(std::string or, std::string desc)
			: origin(or ), description(desc)
		{ }
	};
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
	SHAPESDLL_API void showSets()const override;		// ������� ��������� ������ �� �����
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
	SHAPESDLL_API void showSets()const override;		// ������� ��������� ������ �� �����
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
	SHAPESDLL_API void showSets()const override;		// ������� ��������� ������ �� �����
	SHAPESDLL_API void editShape() override;		// ������������� ��������� ������
};
							
static const char* formatS(const char* strs);		// ������� �������������� ������ ������

#endif // !SHAPESDLL_H