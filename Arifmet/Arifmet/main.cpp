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

	cout << "������� ��������� � ������� '���������='"<<endl;
	cin >> inf;
	string post = ToPost(inf);
	cout <<inf<< Answer(post)<<endl;
	cout << "����������� ������: " <<post << endl;

	_getch();
	return 0;
}
