#include "Hastable.h"
#include <conio.h>
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	const int n=100;
	Node<int, int> a;
	a.SetKey(1);
	a.SetVal(1);
	cout<<a.GetData()<<", ключ: "<<a.GetKey()<<endl;
	char r='a';
	int random;

	Table<char,int> t(n,5);
		for (int i=0;i<n;i++)
			{
				random=rand()%5;
				r=r+random;
				t.Add (r,i);
				cout<<"("<<i<<", "<<r<<"); ";
			}
		cout<<endl<<"Вывод с использованием [] Формат: (DATA, KEY)"<<endl;
 r='a';
		for (int i=0;i<20;i++)
		{
			r ++;
			cout<<"Поиск по ключу ["<<r<<"]"<<endl;
			cout<<"("<<t[r].GetData()<<", "<<t[r].GetKey()<<"); "<<endl;
		
		}

	_getch();
	return 0;
}