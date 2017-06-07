#pragma once
using namespace std;

const int Detlen=20;
template <class T>
class TStack
{
private:
	T *data;
	int size;
	int top;
	void ChangeSize(int s)
	{
		if (s>size)
		{
			T*tmp=new T[s];
			for (int i=0;i<size;i++)
				tmp[i]=data[i];
			delete[] data;
			data=tmp;
			size=s;
		}
	}

public:
	
	TStack(int s=Detlen)
	{
		data=new T[size=s];
		top=0;
	}

	TStack(const TStack <T>&st)
	{
		data= new T [size=st.size];
		top=st.top;
		for(int i=0;i<top;i++)
			data[i]=st.data[i];
	}

	~TStack()
	{
		delete[]data;
	}

	void Push (T item)
	{
		if (top<size)
			data[top++]=item;
		else
		{
			ChangeSize(size+Detlen);
			data[top++]=item;
		}
	}
	
	T Pop()
	{
		if(top>0)
			return data[--top];
		else
			return (T) 0;
	}
	
	T get() const
	{
		if(top>0)
			return data [top-1];
		else return(T) 0;
	}

		bool IsEmpty()
	{
		if (top <=0) return true;
		else return false;
	}

};

