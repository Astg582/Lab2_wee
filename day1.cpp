#include <iostream>
void swap1(int&, int&);
int sum1 (int* a, int* b);
int sub1(int* a, int* b);
int mul1(int* a, int* b);
int div1(int* a, int* b);

int main(){
	int p = 24;
	int w = 3;
	int res = mul1(&p, &w);	
		
	std::cout << (0 == nullptr) << std::endl;
}

int div1(int* a, int* b){
	if(*b != 0){
		return *a / (*b);
	}
	return -1;
}

int mul1(int* a, int* b){
	return (*a) * (*b);
}

int sub1(int* a, int* b){
	return (*a) - (*b);
}

int sum1 (int* a, int* b){
	return *a + *b;
}

void swap1(int& a, int& b){
	int e = a;
	a = b;
	b = e;
}
