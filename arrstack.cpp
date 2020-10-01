#include <iostream>
#include <cstring>
using namespace std;
class StackEmpty:public exception
{
    public:
    	char* what()const throw()
    	{
    		return"stack is empty";
		}
};
class StackFull:public exception
{
    public:
    	char* what()const throw()
    	{
    		return"stack is  full";
		}
};
template <typename E>
class arrstack
{
	enum{def_cap=100};

	 public:
	 	arrstack(int c);
	 	int size()const;
	 	bool empty()const;
	 	E& top()const throw(StackEmpty);
	 	void push(const E& e)throw(StackFull);
	 	void pop()throw(StackEmpty);
	 	void display();
	 private:
	    E* s;
		int capacity;
		int index;	
};

template <typename E> arrstack<E>::arrstack(int c)
{
	s=new E[c];
	capacity=c;
	index=-1;
}
template <typename E> bool arrstack<E>::empty()const
{
	return index<0;
}
template <typename E> int arrstack<E>::size()const
{
	return (index+1);
}
template <typename E> E& arrstack<E>::top()const throw(StackEmpty)
{
	if(empty())
	  throw StackEmpty();
	return s[index];  
}
template <typename E> void arrstack<E>::push(const E& e)throw(StackFull)
{
	if(size()==capacity)
	  throw StackFull();

	  s[++index]=e;  
}
template <typename E> void arrstack<E>::pop()throw(StackEmpty)
{
	if(size()==-1)
	  throw StackEmpty();
	--index;  
}
template <typename E> void arrstack<E>::display()
{
	int i;
	for(i=0;i<size();i++)
	  cout<<s[i];
}
int main()
{
	arrstack <int> a(10);
	
	a.display();
	cout<<endl;
	cout<<"top element  "<<a.top()<<endl;
	a.display();
	cout<<endl;
	a.pop();
	cout<<"AFTER POP"<<endl;
	a.display();
}
