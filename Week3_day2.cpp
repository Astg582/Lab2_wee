#include <iostream>
size_t strlen(const char* str){
	int l = 0;
	while(str[l] != '\0'){
		++l;
	}
	return l;
}

const char* strcmp(const char* str1, const char* str2){

		int s1 = 0;
		int s2 = 0;
		for(int i = 0; str1[i] != '\0'; ++i){
			if(str1[i] > str2[i]){
				++s1;
			}else{
				++s2;
			}
		}
		if(s1 == 0 && s2 == 0){
			return nullptr;
		}else if(s1 > s2){
			return str1;
		}
	return str2;
}

int main(){
char str1[10];
char str2[10];
std::cin >> str2;
std::cin >> str1 ;
std::cout << strcmp(str1, str2) << std::endl;

}
