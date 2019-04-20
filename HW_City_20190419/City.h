#pragma once
#include <iostream>

using namespace std;

class City
{
	char*name;
	int population;
	int cityFoundationYear;

public:
	// ����������� �� ���������
	City();
	// ����������� � �����������
	City(const char*name, int population, int cityFoundationYear);
	
	// ����������� �����������
	City(const City&obj);
	
	// ����������� ����������� R-value
	City(City&&obj);

	// ��������� ��������� ������������ =
	City& operator=(City&&obj);
	City& operator=(const City&obj);

	// ����������
	~City();

	// �������
	void setCityName();
	void setPopulation();
	void setCityFoundationYear();

	// �������
	char getName() const;
	int getPopulation() const;
	int getCityFoundationYear() const;

	// ���������� ������������� �������
	friend ostream& operator<<(ostream &os, const City &obj);
	friend istream& operator>>(istream &is, City &c);
};

// ���������� ���������� ������� �������� ��� ��������
ostream& operator<<(ostream &os, const City &obj);
istream& operator>>(istream &is, City &obj);
