#include <string>
#ifndef _HT_H_
#define _HT_H_
using namespace std;

#include "Node.h"

template <class KEY, class DATA>
class Table
{
protected:
	int size;
	int count;
	int p; 
	Node<KEY,DATA>* mas; 
	unsigned int Hash(KEY K);

public:
Table(int size_ = 1,int p_ =5); 
Table(Table& ht);
~Table();
Node<KEY,DATA>& operator[](KEY k_);
Table& operator=(Table& ht);
void Add(KEY k_ ,DATA val_);
void Del(KEY k_);
};

template <class KEY, class DATA>
Table<KEY, DATA>::Table(int size_, int p_)
{
	size = size_;
	count = 0;
	p = p_;
	mas = new Node<KEY,DATA>[size];
}

template <class KEY, class DATA>
Table<KEY, DATA>::Table(Table& ht)
{
	size=ht.size;
	count=ht.count;
	p=ht.p;
	mas=new Node<KEY,DATA>[ht.size];
	for(int i=0; i<ht.size;++i)
		mas[i]=ht.mas[i];

}

template <class KEY, class DATA>
Table<KEY, DATA>::~Table()
{
	delete[] mas;
	size=0;
	count=0;
}

template <class KEY, class DATA>
unsigned int Table<KEY, DATA>:: Hash(KEY K)
{
	unsigned int hash = 2139062143;
	char *str=new char[K.length()];
	for(; *str; str++)
		hash = (37 * hash + *str)%17;

	return hash;

}

template <class KEY, class DATA>
Node<KEY, DATA>& Table<KEY, DATA>::operator[](KEY k_)
{
	unsigned int index=Hash(k_);
	unsigned int HashIndex=index;
	do
	{
		
	if(mas[index].GetKey()==k_)
		return mas[index];
	else
		index=index+p;
	}
	while(index!=HashIndex && index<size);
	cout<<"no matches"<<endl;
}

template <class KEY, class DATA>

void Table<KEY, DATA>::Add(KEY k_ , DATA val_ )
{


	unsigned int index=Hash(k_);
	unsigned int HashIndex=index;
	do
	{
		
	if(mas[index].isused==false)
		{
		mas[index].SetKey(k_);
		mas[index].SetVal(val_);
		mas[index].isused = true;
		return;

		}
	else
		index=index+p;
	}
	while(index!=HashIndex && index<size);


}

#endif