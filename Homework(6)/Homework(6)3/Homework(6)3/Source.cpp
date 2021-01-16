#include <iostream>
template <typename T>
class Array 
{

	T* arr;
	int count; 
	int size; 
	int grow;

public:
	Array();
	~Array();
	Array(const Array&);
	int GetSize();
	void SetSize(int, int);
	int GetUpperBound();
	bool IsEmpty();
	void FreeExtra(); 
	void RemoveAll();
	T GetAt(int); 
	void SetAt(int, T); 
	T& operator [] (const int); 
	void Add(T); 
	Array Append(const Array&) const; 
	Array& operator =(const Array&);
	T* GetData();
	void InsertAt(int, T); 
	void RemoveAt(int); 
	void Print();
};

template <typename T>
void Array<T>::SetSize(int size2, int grow2) 
{
	grow = grow2;
	if (size2 > size) 
	{
		if ((size2 - size) % grow) 
		{
			size = size + ((size2 - size) / grow + 1) * grow;
		}
		else 
		{
			size = size2;
		}
	}
	else if (size2 < size) 
	{
		if ((size - size2) % grow)
		{
			size = size - ((size - size2) / grow) * grow;
		}
		else
		{
			size = size2;
		}
	}
	if (arr) 
	{ 
		arr = (T*)realloc(arr, sizeof(T) * size);
	}
}

template<typename T>
int Array<T>::GetUpperBound()
{
	return count - 1; 
}

template<typename T>
bool Array<T>::IsEmpty()
{
	return count == false; 
}

template <typename T>
void Array<T>::FreeExtra() 
{
	size = count;
	arr = (T*)realloc(arr, sizeof(T) * size);
}

template <typename T>
void Array<T>::RemoveAll() 
{
	free(arr); 
	arr = NULL;
	count = size = 0;
}

template <typename T>
void Array<T>::Add(T etem) 
{
	if (!arr) 
	{ 
		arr = (T*)malloc(sizeof(T) * size);
	}
	if (count < size) 
	{
		arr[count++] = etem;
	}
	else 
	{
		SetSize(size + grow, grow);
		arr[count++] = etem;
	}

}

template <typename T>
T& Array<T>::operator [] (const int index)
{
	if (arr && index < count)
	{
		return arr[index];
	}
	else 
	{
		std::cout << "no Elements or no such index" << std::endl;
	}
}

template <typename T>
T Array<T>::GetAt(int index) 
{
	if (index < count) 
	{
		T temp = (*this)[index]; 
		return temp;
	}
	else return 0;
}

template <typename T>
void Array<T>::SetAt(int index, T data) 
{
	if (index < count) 
	{
		(*this)[index] = data;
	}
	else std::cout << "no SetAt, because wrong index" << std::endl;
}

template <typename T>
Array<T> Array<T>::Append(const Array& obj) const 
{
	Array temp = *this;
	temp.SetSize(size + obj.size, grow);
	for (size_t i = 0; i < obj.count; ++i)
	{
		temp.Add(obj.arr[i]);
	}
	return temp;
}

template<typename T>
Array<T>::Array()
{
	count = 0; 
	size = grow = 4;
	arr = NULL; 
}

template<typename T>
Array<T>::~Array()
{
	free(arr); 
}

template <typename T>
Array<T>::Array(const Array& obj) 
{
	*this = obj;
}

template<typename T>
int Array<T>::GetSize()
{
	return size; 
}

template <typename T>
Array<T>& Array<T>::operator = (const Array& obj)
{
	if (this != &obj)
	{
		count = obj.count;
		size = obj.size;
		grow = obj.grow;
		arr = (T*)malloc(sizeof(T) * size); 
		for (int i = 0; i < count; ++i) 
		{
			arr[i] = obj.arr[i];
		}
	}
	else return *this;
}

template<typename T>
T* Array<T>::GetData()
{
	return arr;
}

template <typename T>
void Array<T>::InsertAt(int index, T etem)
{
	SetSize(++size, grow);
	++count;
	for (int i = count - 1; i >= index; --i)
	{
		this->arr[i] = this->arr[i - 1];
	}
	(*this)[index] = etem;
}

template <typename T>
void Array<T>::RemoveAt(int index) 
{
	--count;
	for (int i = index; i < count; ++i)
	{
		this->arr[i] = this->arr[i + 1];
	}
	SetSize(--size, grow);
}

template<typename T>
void Array<T>::Print()
{
	if (count) {
		for (int i = 0; i < count; ++i)
		{
			std::cout << arr[i] << "  ";
		}
	}

	else
	{
		std::cout << "Empty array";
	}
	std::cout << "\nsize = " << size << "  count = " << count << "  grow = " << grow << std::endl << std::endl;
}


void main()
{
	Array <int> A, C;
	for (int i = 0; i < 5; ++i)
	{
		A.Add(1 + i);
	}
	A.Print();

	Array <int> B = A;
	B.Add(2); 
	B.Add(3);
	B.Print();

	C = B.Append(A);
	C.Print();

	C.InsertAt(3, 4);
	C.Print();

	C.RemoveAt(5);
	C.Print();
}
