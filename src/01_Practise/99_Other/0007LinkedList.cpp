#include <iostream>
using namespace std;

template <typename T>
struct Node{
	T data;
	Node<T>* next;
};

template <class T>
class List{
public:
	List();
	~List();
	void AddItem(T data);
	void DeleteItem(T data);
	void Show();

private:
	Node<T>* start;
};

template <class T>
List<T>::List()
{
	this->start = NULL;
}
template <class T>
List<T>::~List()
{
	while (start)
	{
		Node<T>* next = start->next;
		delete start;
		start = next;
	}
}

template <class T>
void List<T>::AddItem(T data)
{
	//if first item then add it to start
	if (this->start == NULL)
	{
		this->start = new Node<T>;
		this->start->data = data;
		this->start->next = NULL;
	}
	else
	{
		//else traverse till end and add it
		Node<T>* runner = this->start;

		while (runner->next)
		{
			runner = runner->next;
		}

		//runner is now at the end

		Node<T>* current = new Node<T>;
		current->data = data;
		current->next = NULL;
		runner->next = current;
	}

}

template <class T>
void List<T>::Show()
{
	Node<T>* current = this->start;
	while (current)
	{
		cout <<current->data << "\t";
		current = current->next;
	}
}

template <class T>
void List<T>::DeleteItem(T data)
{

}
int main()
{
	List<double> ls;
	ls.AddItem(1.567);
	ls.AddItem(20.2222);
	ls.AddItem(21.012);
	ls.AddItem(22.1234);
	ls.Show();
	return 0;
}
