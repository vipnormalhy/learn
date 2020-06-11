#include <iostream>

template <typename T>
class Compare {
public:
	typedef unsigned long size_t;
	Compare(T value1, T value2);
	int compare();
private:
	T v1;
	T v2;
};

template <typename T>
Compare<T>::Compare(T value1, T value2) {
	v1 = value1;
	v2 = value2;
}

template <typename T>
inline int Compare<T>::compare() {
	if (v1 < v2)
	{
		return -1;
	}
	else if (v1 == v2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main() {
	Compare<int> b(4,5);

	std::cout << b.compare() << std::endl;
	
	return 0;
}
