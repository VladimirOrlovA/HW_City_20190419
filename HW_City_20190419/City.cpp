#include "City.h"

City::City(): population(1806833), cityFoundationYear(1854)
{
	{
		this->name = new char[strlen("Almaty") + 1];
		strcpy_s(this->name, strlen("Almaty") + 1, "Almaty");
	}
}

City::City(const char * name, int population, int cityFoundationYear)
	:population(population), 
	cityFoundationYear(cityFoundationYear)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

// Конструктор копирования
City::City(const City & obj)
{
	cout << "Copy\n";
	this->name = new char[strlen(obj.name) + 1];
	
	this->cityFoundationYear = obj.cityFoundationYear;
	this->population = obj.population;
	strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
}

// Конструктор копирования R-value
City::City(City&&obj)
{
	cout << "move";
	swap(this->name, obj.name);
	swap(this->cityFoundationYear, obj.cityFoundationYear);
	swap(this->population, obj.population);
}

// Перегрузка оператора присваивания =
City & City::operator=(City&&obj)
{
	swap(this->name, obj.name);
	swap(this->cityFoundationYear, obj.cityFoundationYear);
	swap(this->population, obj.population);
	return *this;
}

// Перегрузка оператора присваивания =
City & City::operator=(const City & obj)
{
	if (this == &obj)
		return *this;
	if (strlen(this->name) != strlen(obj.name))
	{
		delete[]this->name;
		this->name = new char[strlen(obj.name) + 1];
	}
	this->cityFoundationYear = obj.cityFoundationYear;
	this->population = obj.population;
	strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
}

// Деструктор
City::~City()
{
	delete[]name;
}

void City::setCityName()
{
	char cityName[30];
	cout << "Enter City name -> ";
	cin >> cityName;
	delete[] this->name;
	this->name = new char[strlen(cityName) + 1];
	strcpy_s(this->name, strlen(cityName) + 1, cityName);
}

void City::setPopulation()
{
	cout << "\n Enter city population -> ";
	cin >> this->population;
}

void City::setCityFoundationYear()
{
	cout << "\n Enter the year of the city foundation -> ";
	cin >> this->cityFoundationYear;
}

char City::getName() const
{
	return *this->name;
}

int City::getPopulation() const
{
	return this->population;
}

int City::getCityFoundationYear() const
{
	return this->cityFoundationYear;
}

ostream & operator<<(ostream & os, const City & obj)
{
	if (obj.name == nullptr)
	{
		cout << "Object is empty \n";
		return os;
	}
	os << "City name: \t" << obj.name << endl;
	os << "Foundation: \t" << obj.cityFoundationYear << endl;
	os << "Population: \t" << obj.population << endl;
	return os;
}

istream & operator>>(istream & is, City & obj)
{
	cout << "\nEnter City name: ";
	char s[30];
	cin >> s;
	obj.name = new char[strlen(s) + 1];
	strcpy_s(obj.name, strlen(s) + 1, s);
	return is;
}
