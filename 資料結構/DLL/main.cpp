#include<iostream>
using namespace std;
template<typename T>
class Node2{
	private:
		T e;
		Node2 *next,*pre;
	public:
		Node2()
		{
			e = T();
			next = pre= NULL;
		}
		Node2(const T data);
		T getData();
		void setData(const T data);
		Node2 *getNext();
		Node2 *getPre();
		void setNext(Node2* p);
		void setPre(Node2* p);
};

template<typename T>
Node2<T>::Node2(const T data)
{
	e = data;
}
template<typename T>
T Node2<T>::getData()
{
	return e;
}
template<typename T>
void Node2<T>::setData(const T data)
{
	e = data;
	return ;
}
template<typename T>
Node2<T>* Node2<T>::getNext()
{
	return next ;
}
template<typename T>
Node2<T>* Node2<T>::getPre()
{
	return pre ;
}
template<typename T>
void Node2<T>::setNext(Node2* p)
{
	next = p;
	return ;
}
template<typename T>
void Node2<T>::setPre(Node2* p)
{
	pre = p;
	return ;
}
template<typename T>
class DLL{
	private:
		Node2<T> *first, *last;
		int sz;
	public:
		DLL()
		{
			first = last ;
			sz = 0;
		}
		T top();
		void push_back(const T data);
		void pop_back();
		void push_front(const T data);
		void pop_front();
		int size()
		{
			return sz;
		}
		void show();
};
template<typename T>
T DLL<T>::top()
{
	return last->getData();
}
template<typename T>
void DLL<T>::push_front(const T data)
{
	Node2<T>* tmp = new Node2<T>(data);
	if(sz == 0)
	{
		first = last = tmp;
		sz = 1;
		return ;
	}
	tmp->setPre(NULL);
	tmp->setNext(first);
	first->setPre(tmp);
	first = tmp ;
	++sz;
}
template<typename T>
void DLL<T>::pop_front()
{
	if(sz == 0)
	{
		return ;
	}
	if(sz == 1)
	{
		delete last;
		first = last = NULL ;
		sz = 0;
		return ;
	}
	Node2<T>* newFirst;
	newFirst = first->getNext();
	delete first ;
	first = newFirst ;
	first->setPre(NULL);
	sz--;
}
template<typename T>
void DLL<T>::push_back(const T data)
{
	Node2<T>* tmp = new Node2<T>(data);
	if(sz == 0)
	{
		first = last = tmp;
		sz=1;

		return ;
	}
	tmp->setPre(last);
	tmp->setNext(NULL);
	last->setNext(tmp);
	last = tmp ;
	++sz;
}
template<typename T>
void DLL<T>::pop_back()
{
	if(sz == 0)
	{
		return ;
	}
	if(sz == 1)
	{
		delete last ;
		first = last = NULL;
		sz=0;
		return ;
	}
	last = last->getPre();
	last->setNext(NULL);
	--sz;
}
template<typename T>
void DLL<T>::show()
{
	cout<<"(first, last, sz)=("<<first<<", "
								<<last<<", "<<sz<<")"<<endl;
	cout<<"{";

	if(sz != 0)
	{
		for(Node2<T>*p=first; p!=last->getNext(); p=p->getNext())
		{
			cout<<p->getData();
			if(p != last)
			{
				cout<<",";
			}
		}
	}
	cout<<"}"<<endl;
}
int main()
{
	DLL <string>s1;
	s1.push_back("3");
    s1.push_front("AA");
    s1.push_back("10");
    s1.push_front("BB");
    s1.show();
    s1.pop_front();
    s1.show();
    s1.pop_back();
    s1.show();
	return 0;
}


