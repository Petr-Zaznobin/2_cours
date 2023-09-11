#include <iostream>
using namespace std;

class C {
	int N;
	unsigned char arr[];
public:
	C(int _N) {
		unsigned char* arr = new unsigned char[N];
		N = _N;
	}

	template <typename T>
	int check_ind(T t) {
		int ind = n / (8 * sizeof(unsigned char));
		return ind;
	}

	template <typename T>
	void num_to_1(int ind, T t) {
		arr[ind] |= 1 << (n % (8 * sizeof(unsigned char)));
	}

	template <typename T>
	void num_to_0(int ind, T t) {
		arr[ind] |= 1 << (n % (8 * sizeof(unsigned char)));
	}

	template <typename T>
	void get(int ind, T t) {
		arr[ind] & (1 << (n % (8 * sizeof(unsigned char))));
	}

	unsigned char operator [] (int ind) const {
		if (arr[ind] & (1 << (ind % (8 * sizeof(unsigned char))))) return 1;
		else return 0;
	}

	~C() {
		delete[]arr;
	}
};




int main()
{
	int N = 1600;
	C r(1600);
	for (int i = 0; i < N; i++) {
		r.arr
	}
	arr.get()
	delete[] arr; 
}

