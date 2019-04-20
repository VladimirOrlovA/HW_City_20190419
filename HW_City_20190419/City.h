#pragma once
#include <iostream>

using namespace std;

class City
{
	char*name;
	int population;
	int cityFoundationYear;

public:
	// Конструктор по умолчанию
	City();
	// Конструктор с параметрами
	City(const char*name, int population, int cityFoundationYear);
	
	// Конструктор копирования
	City(const City&obj);
	
	// Конструктор копирования R-value
	City(City&&obj);

	// перегузка оператора присваивания =
	City& operator=(City&&obj);
	City& operator=(const City&obj);

	// Деструктор
	~City();

	// сеттеры
	void setCityName();
	void setPopulation();
	void setCityFoundationYear();

	// геттеры
	char getName() const;
	int getPopulation() const;
	int getCityFoundationYear() const;

	// объявление дружественных функции
	friend ostream& operator<<(ostream &os, const City &obj);
	friend istream& operator>>(istream &is, City &c);
};

// объявление глобальных функций операций над строками
ostream& operator<<(ostream &os, const City &obj);
istream& operator>>(istream &is, City &obj);
