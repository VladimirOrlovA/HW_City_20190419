#include"City.h"

void main()
{
	City a; //  ("Almaty", 1, 1);

	cout << a;
	cin >> a;
	cout << a;

	a.setCityName();
	cout << a << endl;

	cout << a.getName() << endl; /// ??????????????

	system("pause");
}