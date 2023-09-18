#include <iostream>
using namespace std;

class C {
	int N;
	unsigned char arr[];
public:
	C(int _N) {
        N = _N;
		unsigned char* arr = new unsigned char[N];
	}

    void get_arr(){
        for (int i = 0; i< N; i++){
            cout << arr[i];
        }
    }



	int check_ind(int n) {
		int ind = n / (8 * sizeof(unsigned char));
		return ind;
	}


	void num_to_1(int ind, int n) {
		arr[ind] |= 1 << (n % (8 * sizeof(unsigned char)));
	}

	void num_to_0(int ind, int n) {
		arr[ind] |= ~1 << (n % (8 * sizeof(unsigned char)));
	}

    void get_sq(int ind, int n){
        cout << (arr[ind] & (1<<(n%(8*sizeof (unsigned char)))));
    }

	unsigned char operator [] (int ind) const {
		if (arr[ind] & (1 << (ind % (8 * sizeof(unsigned char))))) return 1;
		else return 0;
	}

	~C() {
        N = 0;
		delete [] &arr;
	}
};




int main()
{
	int N = 120;
	C arr(N);
    for (int i = 0; i< N;i++){
        int ind = arr.check_ind(i);
        arr.num_to_1(ind, i);
    }

    for (int i = 2; i<N;i++){
        int ind = arr.check_ind(i);
        for (int j = i*i; j < N; j+=i){
            arr.num_to_0(ind, j);
        }
    }

    for (int i = 0;i<N;i++){
        int ind = arr.check_ind(i);
        cout << i << ". ";
        arr.get_sq(ind, i);
        cout << "\n";
    }
}


