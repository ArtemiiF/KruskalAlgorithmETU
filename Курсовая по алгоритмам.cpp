// Курсовая по алгоритмам.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <conio.h>

using namespace std;

//Список
template<typename T>
class List
{
public:
	List()
	{
		size = 0;
		head = nullptr;
	}
	~List()
	{
		Clear();
	}

	int GetSize() { return size; }

	void Clear()
	{
		while (size != 0)
		{
			Node<T>* temp = head;
			head = head->pNext;
			//delete temp;
			size--;
		}
	}

	int IndexOfFirstElemenWThisValue(T data)
	{
		Node<T>* current = this->head;
		int counter = 0;

		while ((counter < size - 1) && (current->data != data))
		{
			counter++;
			current = current->pNext;
		}

		if ((current->data) == data)
		{
			return counter;
		}
		else
		{
			//cout << "Такого элемента нет ";
			return -1;
		}
	}

	void DeleteLastElement()
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < size - 2; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;
		size--;
	}

	void DeleteElement(int index)
	{
		int count = 0;
		if (head == nullptr)
		{
			cout << "Error!!!\n";
		}
		else
		{
			if (index == 0)
			{
				Node<T>* current = this->head;
				Node<T>* toDelete = this->head;
				current = current->pNext;
				head = current;
				delete toDelete;
				size--;
			}
			else if (index == (size - 1))
			{
				DeleteLastElement();
			}
			else
			{
				Node<T>* current = this->head;
				while (count < index)
				{
					current = current->pNext;
					count++;
				}

				Node<T>* toDelete = current->pNext;
				current->pNext = toDelete->pNext;;
				delete toDelete;
				size--;
			}
		}
	}

	T GetData(int index)
	{

		int counter = 0;

		Node<T>* current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pNext;
			counter++;
		}

	}

	T& operator[](const int index)
	{

		int counter = 0;

		Node<T>* current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pNext;
			counter++;
		}

	}

	void Add(T data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
		}
		else
		{
			Node<T>* current = this->head;
			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node<T>(data);
		}
		size++;
	}

private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;


		Node(T data = T(), Node<T>* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node<T>* head;
	int size;
};

//Список с двумя значениями в узле
template<typename T>
class DoubleList
{
public:
	DoubleList()
	{
		size = 0;
		head = nullptr;
	}
	~DoubleList()
	{
		Clear();
	}

	int GetSize() { return size; }

	void Clear()
	{
		while (size != 0)
		{
			Node<T>* temp = head;
			head = head->pNext;
			//delete temp;
			size--;
		}
	}

	int IndexOfFirstElemenWThisValue(T data)
	{
		Node<T>* current = this->head;
		int counter = 0;

		while ((counter < size - 1) && (current->data != data))
		{
			counter++;
			current = current->pNext;
		}

		if ((current->data) == data)
		{
			return counter;
		}
		else
		{
			cout << "Такого элемента нет ";
			return -1;
		}
	}

	void DeleteLastElement()
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < size - 2; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;
		size--;
	}

	T GetFirst(int index)
	{
		int counter = 0;

		Node<T>* current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data1;
			}
			current = current->pNext;
			counter++;
		}

	}

	T GetSecond(int index)
	{
		int counter = 0;

		Node<T>* current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data2;
			}
			current = current->pNext;
			counter++;
		}

	}

	void Swap(int first, int second)
	{
		int counter = 0;

		Node<T>* firstNode = this->head;
		Node<T>* secNode = this->head;

		while (counter != first)
		{
			firstNode = firstNode->pNext;
			counter++;
		}

		counter = 0;
		while (counter != second)
		{
			secNode = secNode->pNext;
			counter++;
		}

		T tdata1 = firstNode->data1;
		T tdata2 = firstNode->data2;

		firstNode->data1 = secNode->data1;
		firstNode->data2 = secNode->data2;
		secNode->data1 = tdata1;
		secNode->data2 = tdata2;
	}

	void Add(T data1, T data2)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data1, data2);
		}
		else
		{
			Node<T>* current = this->head;
			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node<T>(data1, data2);
		}
		size++;
	}

	void SetFirstValue(int index, T value)
	{
		int counter = 0;

		Node<T>* current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			{
				current->data1 = value;
			}
			current = current->pNext;
			counter++;
		}
	}

	void SetSecValue(int index, T value)
	{
		int counter = 0;

		Node<T>* current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			{
				current->data2 = value;
			}
			current = current->pNext;
			counter++;
		}
	}

private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data1;
		T data2;

		Node(T data1 = T(), T data2 = T(), Node<T>* pNext = nullptr)
		{
			this->data1 = data1;
			this->data2 = data2;
			this->pNext = pNext;
		}
	};

	Node<T>* head;
	int size;
};

//Класс ребра
class Edge
{
public:
	Edge(int weight, char vertex1, char vertex2)
	{
		this->weight = weight;

		//Вершины вносятся в алфавитном порядке
		if (vertex1 - vertex2 < 0)
		{
			this->vertex1 = vertex1;
			this->vertex2 = vertex2;
		}
		else
		{
			this->vertex1 = vertex2;
			this->vertex2 = vertex1;
		}

	}

	Edge()
	{
		this->weight = -1;
		this->vertex1 = '?';
		this->vertex2 = '?';
	}

	int GetWeight()
	{
		return weight;
	}

	void SetWeight(int weight)
	{
		this->weight = weight;
	}

	char GetFirstVertex()
	{
		return vertex1;
	}

	void SetFirstVertex(char vertex)
	{
		this->vertex1 = vertex;
	}

	char GetSecVertex()
	{
		return vertex2;
	}

	void SetSecVertex(char vertex)
	{
		this->vertex2 = vertex;
	}


private:
	int weight;
	char vertex1;
	char vertex2;
};

//Список смежности
class AdjList
{
public:
	AdjList()
	{
		size = 0;
		head = nullptr;
	}
	~AdjList()
	{
		Clear();
	}


	void Clear()
	{
		while (size != 0)
		{
			Node* temp = head;
			head = head->pNext;
			delete temp;
			size--;
		}
	}

	int GetSize() { return size; }

	void Add(char vertex, Edge edge)
	{
		Node* temp = this->head;
		int count = 0;
		bool flagRepeat = false;		//Повторные ли вершины

		//Пробегает по всем узлам проверяя есть ли вершина в графе
		while (count != size && !flagRepeat)
		{
			if (vertex != temp->vertex)
			{
				count++;
				temp = temp->pNext;
			}
			else
			{
				flagRepeat = true;
			}
		}


		if (!flagRepeat)
		{
			if (head == nullptr)
			{
				head = new Node(vertex, edge);
			}
			else
			{
				Node* current = this->head;
				while (current->pNext != nullptr)
				{
					current = current->pNext;
				}
				current->pNext = new Node(vertex, edge);
			}
			size++;
		}
		else
		{
			Node* current = this->head;
			while (current->vertex != vertex)
			{
				current = current->pNext;
			}

			current->edgeList.Add(edge);
		}

	}

	char GetVertex(int index)
	{
		int counter = 0;

		Node* current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->vertex;
			}
			current = current->pNext;
			counter++;
		}
	}

	List<Edge> GetEdge(int index)
	{
		int counter = 0;

		Node* current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->edgeList;
			}
			current = current->pNext;
			counter++;
		}
	}

private:
	class Node
	{
	public:
		Node* pNext;
		char vertex;
		List<Edge> edgeList;

		Node(char vertex, Edge edge, Node* pNext = nullptr)
		{
			this->vertex = vertex;
			edgeList.Add(edge);
			this->pNext = pNext;
		}
	};

	Node* head;
	int size;
};

template<typename T>
bool IsFlag(DoubleList<T> list, T data)
{
	for (int i = 0; i < list.GetSize(); i++)
	{
		if (list.GetFirst(i) == data)
		{
			return true;
		}
	}
	return false;
}


template<typename T>
void InsertionSort(DoubleList<T>* list)
{
	for (int i = 1; i < list->GetSize(); i++)
	{
		int current = (char)list->GetSecond(i)[0] - '0';
		string strcurr = list->GetFirst(i);
		int j = i - 1;
		while ((j >= 0) && (current <= (char)(list->GetSecond(j)[0] - '0')))
		{
			list->Swap(j, j + 1);
			--j;
		}
	}
}


string StringInput()
{
	string n;
	char c;
	int count = 0;
	do
	{
		c = _getch();


		if ((c >= 0) && (c <= 255) && (c != 8))
		{
			cout << c;
			n = n + c;
			count++;
		}
		else if (c == 8 && count > 0)
		{
			cout << "\b \b";

			n.erase(count - 1, 1);
			count--;
		}

	} while (c != 13);

	return n;
}



int main()
{
	setlocale(LC_ALL, "ru");

	AdjList alist;
	string str;

	cout << "Введите количество троек:";
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cout << "Введите тройки(A B 3):";

		str = StringInput();
		cout << endl;
		char v1, v2;
		int w = 0;

		remove(str.begin(), str.end(), ' ');

		int size = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '\r' && size == 0)
			{
				size = i;
			}
		}

		v1 = str[0];
		v2 = str[1];

		for (int i = 2; i < size; i++)
		{
			w = w * 10 + str[i] - '0';
		}


		if (!((v1 >= 'A' && v1 <= 'Z') && (v2 >= 'A' && v2 <= 'Z')) && (w >= 0 && w <= 1023))
		{
			cout << "\nОшибка! Ввод должен быть буква-буква-число\n";
			num++;
		}
		else
		{
			alist.Add(v1, Edge(w, v1, v2));
			alist.Add(v2, Edge(w, v1, v2));

		}

	}


	//Тестовый
	/*cout << "Ввели:\n";
	alist.Add('A', Edge(3, 'A', 'B'));
	alist.Add('B', Edge(3, 'A', 'B'));
	alist.Add('C', Edge(5, 'A', 'C'));
	alist.Add('A', Edge(5, 'A', 'C'));
	alist.Add('B', Edge(1, 'B', 'C'));
	alist.Add('C', Edge(1, 'B', 'C'));

	alist.Add('Z', Edge(3, 'Z', 'B'));
	alist.Add('B', Edge(3, 'Z', 'B'));
	alist.Add('F', Edge(5, 'F', 'E'));
	alist.Add('E', Edge(5, 'E', 'F'));
	alist.Add('E', Edge(1, 'E', 'A'));
	alist.Add('A', Edge(1, 'E', 'A'));*/

	DoubleList<string> minList;
	//Обход 
	for (int i = 0; i < alist.GetSize(); i++)
	{
		//Ребра i вершины
		List<Edge> tempList = alist.GetEdge(i);
		for (int j = 0; j < tempList.GetSize(); j++)
		{
			char v1 = tempList[j].GetFirstVertex();
			char v2 = tempList[j].GetSecVertex();
			char w = tempList[j].GetWeight() + '0';

			string tstr = "";
			tstr = tstr + v1 + v2;
			string tstr2 = "";
			tstr2 = tstr2 + w;

			if (!IsFlag(minList, tstr))
			{
				minList.Add(tstr, tstr2);
			}
		}
		cout << endl;
	}

	//Сортировка вставками
	InsertionSort(&minList);
	//СНМ
	List<List<char>> SNMList;

	//Заполняем
	for (int i = 0; i < alist.GetSize(); i++)
	{
		List<char> list;
		char ch = alist.GetVertex(i);
		list.Add(ch);
		SNMList.Add(list);
	}

	bool minGraphFlag = false;
	int i = 0;

	while (!minGraphFlag)
	{
		int j = 0;

		char minEdgeV1;
		char minEdgeV2;

		minEdgeV1 = minList.GetFirst(i)[0];
		minEdgeV2 = minList.GetFirst(i)[1];

		int x1 = 0;
		int	x2 = 0;

		//В какой сд находится вершина 1
		for (int i = 0; j < SNMList.GetSize(); j++)
		{
			List<char> tempList;
			tempList = SNMList.GetData(j);

			if (tempList.IndexOfFirstElemenWThisValue(minEdgeV1) != -1)
			{
				x1 = j;
			}
		}

		//В какой сд находится вершина 2
		for (int k = 0; k < SNMList.GetSize(); k++)
		{
			List<char> tempList;
			tempList = SNMList.GetData(k);

			if (tempList.IndexOfFirstElemenWThisValue(minEdgeV2) != -1)
			{
				x2 = k;
			}
		}

		string tempStr1 = "";
		string tempStr2 = "";

		for (int z = 0; z < SNMList.GetData(x1).GetSize(); z++)
		{
			tempStr1 = tempStr1 + SNMList.GetData(x1).GetData(z);
		}

		for (int z = 0; z < SNMList.GetData(x2).GetSize(); z++)
		{
			tempStr2 = tempStr2 + SNMList.GetData(x2).GetData(z);
		}

		List<char> tempList;

		for (int z = 0; z < SNMList.GetData(x1).GetSize(); z++)
		{
			tempList.Add(tempStr1[z]);
		}

		for (int z = 0; z < SNMList.GetData(x2).GetSize(); z++)
		{
			tempList.Add(tempStr2[z]);
		}

		SNMList.DeleteElement(x1);

		if (x1 < x2)
		{
			x2--;
		}

		SNMList.DeleteElement(x2);

		SNMList.Add(tempList);


		i++;

		if (SNMList.GetSize() == 1)
		{
			minGraphFlag = true;
		}
	}

	int sum = 0;
	for (int j = 0; j < i; j++)
	{
		cout << minList.GetFirst(j)[0] << " " << minList.GetFirst(j)[1] << endl;
		sum += minList.GetSecond(j)[0] - '0';
	}
	cout << "Сумма:" << sum;

	cout << endl;
	system("pause");
	return 0;
}