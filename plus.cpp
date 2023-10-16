#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

template<class T>
class Queue {
private:
	T* data;
	size_t size;
	size_t i_start;
	size_t els;
public:
	Queue(size_t size) {
		data = new T[size];
		this->size = size;
		i_start = 0;
		els = 0;
	}
	void push(T& elem) {
		if (isFull()) {
			throw out_of_range("out of range"); //must change
		}
		data[(i_start + els + 1) % size] = elem;
	}
	T pop() {
		if (isEmpty()) {
			throw out_of_range("out of range"); //must change
		}
		size_t i = i.start;
		i_start = (++i_start) % size;
		els--;
		return data[i];
	}
	bool isFull() {
		return (size == els);
	}
	bool isEmpty() {
		return (els == 0);
	}
	~Queue() {
		delete[]data;
		size = 0;
		i_start = 0;
		els = 0;
	}
};


template<typename T>
class Stack {
	T* data;
	size_t size;
	size_t capacity;
public:
	Stack() {
		data = new T[10];
		capacity = 10;
		size = 0;
	}
	bool isEmpty() {
		return (size == 0);
	}
	T pop() {
		if (isEmpty) {
			throw out_of_range("out of range"); //must change
		}
		return data[--size];
	}
	void push(T& e) {
		if (size == capacity) {
			resize();
		}
		data[size++] = e;
	}
	void resize() {
		T* tmp = new T[size * 2];
		memcpy(tmp, data, size);
		delete[]data;
		data = tmp;
		capacity = size;
	}
	~Stack() {
		delete[]data;
		size = 0;
		capacity = 0;
	}
};

int main() {
	Stack<int> A;
	for (int i = 0; i < 11; i++) {
		A.push(i);
	}
}


