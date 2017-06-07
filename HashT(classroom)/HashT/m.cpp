#include "Hastable.h"
#include <conio.h>
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	const int n=53;
	Node<int, int> a;
	a.SetKey(1);
	a.SetVal(1);
	cout<<a.GetData()<<", ключ: "<<a.GetKey()<<endl;

	Table<int,int> t(n,5);
		for (int i=0;i<n;i++)
			{
				int r=rand()%17;
				t.Add (r,i);
				cout<<"("<<i<<", "<<r<<"); ";
			}
		cout<<endl<<"Вывод с использованием [] Формат: (KEY, DATA)"<<endl;
		for (int i=0;i<10;i++)
		{
			int r=rand()%17;
			cout<<"Поиск по ключу ["<<r<<"]"<<endl;
			cout<<"("<<t[r].GetData()<<", "<<t[r].GetKey()<<"); "<<endl;
		
		}

	_getch();
	return 0;
}