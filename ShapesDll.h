#ifndef SHAPESDLL_H
#define SHAPESDLL_H

#ifdef SHAPESDLL_EXPORTS
#define SHAPESDLL_API __declspec(dllexport) 
#else
#define SHAPESDLL_API __declspec(dllimport) 
#endif

#include <iostream>
#include <typeinfo>

	// Базовый класс для хранения геометрических фигур
class Shape
{
protected:
	// здесь могут содержаться поля с даннми общими для объектов всех порождённых классов:
	// координаты объекта, его цвет, метод заполнения и др.
public:
	SHAPESDLL_API Shape() = default;
	virtual SHAPESDLL_API ~Shape() = 0;
	virtual SHAPESDLL_API double getArea() = 0;	// посчитать и вернуть площадь фигуры
	virtual SHAPESDLL_API void display();		// вывести параметры фигуры на экран
	virtual SHAPESDLL_API void editShape();		// редактировать параметры фигуры
};

	// Класс для хранения треугольников
class Triangle : public Shape
{
protected:
	float sideAB;
	float sideAC;
	float anglBAC;
public:
	SHAPESDLL_API Triangle(float lengthAB, float lengthAC, float aBAC);
	SHAPESDLL_API ~Triangle() = default;
	SHAPESDLL_API double getArea() override;	// посчитать и вернуть площадь фигуры
	SHAPESDLL_API void display() override;		// вывести параметры фигуры на экран
	SHAPESDLL_API void editShape() override;	// редактировать параметры фигуры
};

	// Класс для хранения прямоугольников
class Rectangle : public Shape
{
protected:
	float sideA;
	float sideB;
public:
	SHAPESDLL_API Rectangle(float lengthA, float lengthB);
	SHAPESDLL_API ~Rectangle() = default;
	SHAPESDLL_API double getArea() override;	// посчитать и вернуть площадь фигуры
	SHAPESDLL_API void display() override;		// вывести параметры фигуры на экран
	SHAPESDLL_API void editShape() override;	// редактировать параметры фигуры
};

	// класс для хранения правильных многоугольников
class RegularPolygons : public Shape
{
protected:
	int numAngles;
	float side;
public:
	SHAPESDLL_API RegularPolygons(int nAngles, float lSide);
	SHAPESDLL_API ~RegularPolygons() = default;
	SHAPESDLL_API double getArea() override;	// посчитать и вернуть площадь фигуры
	SHAPESDLL_API void display() override;		// вывести параметры фигуры на экран
	SHAPESDLL_API void editShape() override;	// редактировать параметры фигуры
};
							
static const char* formatS(const char* strs);	// функция форматирования строки вывода

#endif // !SHAPESDLL_H