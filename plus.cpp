#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

template <typename T>
class nvector {
	T* data;
	size_t size;
	size_t capacity;
public:
	nvector(size_t size = 10) {
		this->size = 0;
		capacity = size;
		data = new T[size]();
	}
	void push_back(T a) {
		if (capacity == size) {
			resize(size * 2);
		}
		data[size++] = a;
	}
	void resize(size_t size) {
		if (size < capacity) {
			cout << "bad idea"; //здесь нужно исключение
		}
		T* tmp = new T[size];
		memcpy(tmp, data, this -> size*sizeof(T));
		delete[] data;
		capacity = size;
	}
	T& operator[] (size_t index) {
		return data[index];
	}
	const T& operator[] (size_t index) const {
		return data[index];
	}


	~nvector(){
		delete[] data;
		size = 0;
		capacity = 0;
	}
};


int main(){

	size_t s = 1024;
	
	//nvector<nvector<int>> V1(s);
	//nvector<nvector<int>> V2(s);
	//nvector<nvector<int>> C(s);
	nvector<int> In(s);
	
	for (int i = 0; i < s; i++) {
		In.push_back(1 + rand() % 4000);
	}

	//for (int i = 0; i < s; s++) {
	//	V1.push_back(In);
	//	V2.push_back(In);
	//}


	system_clock::time_point start = system_clock::now();
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			for (int k = 0; k < s; k++) {
				//C[i][j] = V1[i][k] * V2[k][j];
			}
		}
	}
	system_clock::time_point end = system_clock::now();	
	duration<double> sec = end - start;
	cout << sec.count() << " сек." << endl;

}

