#include<iostream>

using namespace std;
class stack
{
	public:
		stack():head(NULL){}
		~stack();
		void push(void* v);
		void* pop();
		bool isEmpty();
	protected:
		class Element
		{
			public:
	      Element(Element *n,void* v):value(v),next(n){}
		
				void* getvalue() const {return value;}
				Element* getnext()const {return next;}
			private:
				void *value;
				Element *next;
		};

	 Element *head;
};

bool stack::isEmpty()
{
	if(NULL == head)
		return true;
	return false;
}

void stack::push(void *v)
{
	Element *el = new Element(head,v);
	head = el;
}

void *stack::pop()
{
	if(NULL == head)
		cout << "stack is empty\n"<<endl;

	Element * popEl = head;
	void *data = popEl->getvalue();
	head = popEl->getnext();
	delete popEl;

	return data;
}

stack::~stack()
{
	while(head)
	{
		Element *todel = head;
		head = head->getnext();
		delete todel;
	}
}	

int main()
{
	stack *stackds = new stack();

	stackds->push(static_cast<void*>(new int(5) ));
	stackds->push(static_cast<void*>(new int(4) ));
	stackds->push(static_cast<void*>(new int(3) ));
	stackds->push(static_cast<void*>(new int(2) ));
	stackds->push(static_cast<void*>(new int(1) ));
	stackds->push(static_cast<void*>(new int(0) ));

	while(not stackds->isEmpty())
	{
	  void *data = stackds->pop();
		cout <<"data:" << *(static_cast<int*>(data)) << endl;
	}
	return 0;
}
