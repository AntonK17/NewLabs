#include <string> 
#include <conio.h>
#include <iostream>
#include "Stacksimple.h" 
#include "Operations.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string inf;

	cout << "Введите выражение в формате 'выражение='"<<endl;
	cin >> inf;
	Ar u(inf);
	string post = u.ToPost();
	cout <<inf<< u.Answer()<<endl;
	cout << "Постфиксная запись: " <<post << endl;

	_getch();
	return 0;
}
