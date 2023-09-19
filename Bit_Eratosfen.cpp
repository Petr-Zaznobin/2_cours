#include <iostream>
using namespace std;

class C {
	int N;
	unsigned char* arr;
public:
	C(int _N) {
        N = _N;
		arr = new unsigned char[N];
        for (int i = 0; i < N; i++){
            arr[i] = 0;
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
		arr[ind] &= ~1 << (n % (8 * sizeof(unsigned char)));
	}

    int get(int ind, int n){
        return((arr[ind] & (1<<(n%(8*sizeof(unsigned char))))));
    }

	unsigned char operator [] (int ind) const {
		if (arr[ind] & (1 << (ind % (8 * sizeof(unsigned char))))) return 1;
		else return 0;
	}

	~C() {
        N = 0;
		delete[]arr;
	}
};




int main()
{
	int N = 20;
    int num = N*8;
	C arr(N);
    
    for (int i = 2; i<num; i++){
        int ind = arr.check_ind(i);
        if (arr.get(ind, i) == 0){
            for (int j = i*i; j<num; j+=i){
                ind = arr.check_ind(j);
                arr.num_to_1(ind, j);
            }
            cout << i << "\n";
        }
    }


}


