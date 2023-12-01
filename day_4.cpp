#include <iostream>
#include <map>
#include <functional>

//day 2
int str_len(const char*); 
char* str_chr(const char*, const char*);
char* str_cat(char*, const char*);

//day 3
void to_upper(char* str);

//day 4
void foo(int, char, char, short);
void stugich(bool(*ptr)(int), int*, int);
bool parz(int); 
int sume(int, int);
int subt1(int, int);
int divi(int, int);
int mull(int, int); 
typedef int (*BF)(int, int);

//split 
char **split(char* s1, char delim); 


int main(){
	char str[30];
	char ch;
	std::cin >> str;
	std::cout << str << std::endl;
	std::cin >> ch;
	char** str1 = split(str, ch);


return 0;
}
/*
int main(){
	int s = 100;
	int a[100];
	for(int i = 0; i < s; ++i){
		a[i] = i; 
	}

	std::map < char, BF> mp;
	mp['+'] = sume;
	mp['-'] = subt1;
	mp['/'] = divi;
	mp['*'] = mull;
	int w = 0;
	int q = 0;
	char op = '+';
	std::cout << "entr 1 number" << std::endl;
	std::cin >> w;
	std::cout << "operation '+', '-', '/' or '*' " << std::endl;
	std :: cin >> op; 
	std::cout << " enter 2 number " << std::endl; 
	std::cin >> q;
	std::cout <<mp[op](w, q) << std::endl;
//	std::cout << parz(13) << std::endl;
//	stugich(parz, a, s);
}

*/

void to_upper(char* str){
	for(int i = 0; str[i] != '\0'; ++i){
		str[i] -=((bool)(str[i] & 32))* 32;
	}
}
/*
int main(){
	char str[30];
	std::cin>> str;
	to_upper(str);
	std::cout << str;
}
*/
char **split(char* s1, char delim){
	int d = 0;
	for(int i = 0; s1[i] != '\0'){
		if(s1[i] == delim){
			++d;
		}
	}
 
	char** arr = new char*[d];
	int e = 0;
	for(int j = 0; j < d; ++i){
		while(s1[e] !=  delim){
			++e;
		}
		arr[j] = new char[e + 1];
		e = 0; 
	}
	int full = 0;
	for(int e = 0; e < d; ++e){
		while(s1[full] != '\0'){
			for(int bar = full; s1[bar] != delim){
				for( int j = 0; s1[i] != delim; ++j)
			   	arr[e][j] = s1[bar];	
				++bar;
				}
				arr[e][j] = '\0';

				full += bar + 1;
			}
		}
	}

	return arr;
}



int divi(int a, int b){
	if(b == 0){
		return -1;
	}
	return a / b;
}
int mull(int a, int b){ return a * b; }
int subt1(int a, int b){ return a - b; }
int sume(int a, int b){ return a + b; }

// function pointer
void stugich(bool(*ptr)(int), int* a, int s){
	for(int i = 0; i < s; ++i){
		if(ptr(a[i])){
			std::cout << a[i] << std::endl;
		}
	}
}

bool parz(int a){
	if (a <  2){
		return 0;
	}else if( a == 3){
		return 1;
	}

	for(int i = 2; i < a / 2; ++i){
		if(!(a % i)){
			return 0;
		}
	}	
	return 1;
}

//int <-- char, char, short
void foo(int target, char c1, char c2, short sh){
	char* c = (char*) &target;
	short* s = (short*) c;
	*c = c1;
	*(c + 1) = c2;
	*(++s) = sh;
	std::cout << (void*)c << ' ' << (void*)(c + 1) << ' ' << (void*)s << std::endl; 
}

//str car arr1 <-- arr2
char*str_cat(char* str1, const char* str2){
	int i = str_len(str1);
	for(int j = 0; str2[j] != '\0'; ++j, ++i){
			if(str1 == '\0'){
					str1[i] = ' ';
			}
			str1[i] = str2[j];
	}
	str1[i] = '\0';
	return (char*) str1;
}

//str ch searc in char arr 1 char
char* str_chr(const char* str1, const char* str2){
	for(int i = 0;  str1[i] != '\0'; ++i){
		if(str1[i] == *str2){
			return (char*) str1 + i;
		}
	}
	return (char*) str1 + str_len(str1);
}

//str len 
int str_len(const char* ch){
	int l = 0;
	while(ch[l] != '\0'){
		++l;
	}
	return l; 
}
