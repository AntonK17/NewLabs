#include <string>
#include "Hastable.h"
#include <conio.h>
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	const int n=53;
	Node<string, int> a;
	a.SetKey("ura");
	a.SetVal(1);
	cout<<a.GetData()<<", ключ: "<<a.GetKey()<<endl;

	Table<string,int> t(n,5);

				t.Add ("Anatoliy",12);
				cout<<"("<<"12"<<", "<<"Anatoliy"<<"); ";

				t.Add ("Sergey",11);
				cout<<"("<<"11"<<", "<<"Sergey"<<"); ";

		cout<<endl<<"Вывод с использованием [] Формат: (DATA, KEY)"<<endl;

			
			cout<<"Поиск по ключу ["<<"Sergey"<<"]"<<endl;
			cout<<"("<<t["Sergey"].GetData()<<", "<<t["Sergey"].GetKey()<<"); "<<endl;

	_getch();
	return 0;
}