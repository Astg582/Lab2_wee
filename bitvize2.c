#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 


bool if_dec(char*);  //if in char* decimal number true else false
bool if_hex(char*);  //if in char* hexadecimal number true else false
bool if_bin(char*);  //if in char* binary number true else false
int bin_dec(char*);  // binar number in char* --> int number in int
int dec_dec(char*);  // decimal number in char* --> int number in int
int hex_dec(const char*); // hexadecimal number in char* --> int number in int


int calculator(int, int); // bitvize calculator
void determinant(int);  //license plate number system

int main(){
	int dec = 0;
	
	printf("Enter '2' -> binary, '10' -> decimal or '16' -> hexadecimal\n");
	do{	
		scanf("%d", &dec);

		if(dec != 10 && dec != 2 && dec != 16)
		{
		printf("Invalid number system. Please tray again\n");
		printf("\t'2' or '10' or '16'\n");
		}
	}while(dec != 10 && dec != 2 && dec != 16);
	
	determinant(dec);
	return 0;
}	


int calculator(int a, int b){
	
	int cal = 0;
	int count = 0;
	

	printf("1. AND, \n2. OR \n3. XOR \n4. NOR \n5. Left Shift \n6. Right shift \n7. Replay \n8. Exit\n");	
	do{
		scanf("%d", &cal);

		++count;
		if(count >= 15){
			printf("Wrong value write limit exceeded\n");
			exit(0); 
		}
		if(cal < 1 || cal > 8){
			printf("Invalid number system. Please tray again\n");
		} 
	}while(cal < 1 || cal > 8);
	
	switch (cal){
		case 1:
		return a & b;
		case 2:
		return a | b;
		case 3:	
		return a ^ b;
		case 4:
		return ~(a | b);
		case 5:
		return a << b;
		case 6:
		return a >> b;
		case 7:
		printf("\tTray again\n");
		return main();
                case 8:
		printf( "\tGood bye\n");
		exit(0);
	}

	return 0;
}


void determinant(int dec){
	switch(dec){
		case 10:
		char num1[8];
		char num2[8];
		do{
		printf("enter  1 numbers in your chosen numeric system\n");
		scanf("%s", num1);
		}while(!(if_dec(num1)));
		do{
		printf("enter  1 numbers in your chosen numeric system\n");
		scanf("%s", num2);
		}while(!(if_dec(num2)));
		
		printf("The result  : %d\n", calculator(dec_dec(num1), dec_dec(num2)));

			break;
		case 2:
			char bnum1[16];
			char bnum2[16];

			do{
			printf("enter  1 numbers in binary numeric system\n");
			scanf("%s", bnum1);
			}while(!(if_bin(bnum1)));
			do{
			printf("enter  1 numbers in binary numeric system\n");
			scanf("%s", bnum2);
			}while(!(if_bin(bnum2)));
			
			int a = calculator(bin_dec(bnum1), bin_dec(bnum2));

			int binary[32];
			int i = 0;
			while(a > 0){
				binary[i] = a % 2;
				a /= 2;
				++i;
			}
			
			for(int j = i - 1; j >= 0; --j){
				printf("%d", binary[j]);
			}
			break;
		case 16:
			char hex1[8];
			char hex2[8];
				do{
				printf("enter  1 numbers in hexadecimal numeric system\n");
				scanf("%s", hex1);
				}while(!(if_hex(hex1)));
				do{
				printf("enter  1 numbers in hexadecimal numeric system\n");
				scanf("%s", hex2);
				}while(!(if_hex(hex2)));
			printf("Hexadecimal: %X\n", calculator(hex_dec(hex1), hex_dec(hex2)));		
	}
}



int hex_dec(const char* hex){
	int decimal = 0;
	sscanf(hex, "%x",&decimal);
	return decimal;
}



int dec_dec(char* dec1){
	int a = 0;
	if(*dec1 == '0' && (*(dec1 + 1) == 'd' || *(dec1 + 1) == 'D')){
		dec1 += 2;
	}	

	int j = 0;
	while(*dec1 != '\0'){
	a *= 10;
	a += (int) *dec1 - 48;
	dec1 += 1;
	}
	return a;
}


int bin_dec(char* bin1){
	int a = 0;
	if(*bin1 == '0' && (*(bin1 + 1) == 'b' || *(bin1 + 1) == 'B')){
		bin1 += 2;
	}
	int i = 1;
	int j = 0;
	while(bin1[j] != '\0'){
		++j;
	}
	while(*bin1 != '\0'){ 
			a += (int)(*bin1 - '0') * (1 << (j - i));
			bin1 += 1;
			++i;
	}
	return a;
}


bool if_bin(char* bin){
	if(*bin == '0' && (*(bin + 1) == 'b' || *(bin + 1) == 'B')){
		bin += 2;
	}	
	while(*bin != '\0'){
                       if(*bin < '0' || *bin > '1'){
                                       return 0;
		       }
                       bin += 1;
	}
	return 1;
}


bool if_hex(char* hex1){
	if(*hex1 == '0' && (*(hex1 + 1) == 'x' ||  *(hex1 + 1) == 'X')){
		hex1 += 2;
	}

	while(*hex1 != '\0'){
		if((*hex1 < '0') || (*hex1 > '9')){
			if(*hex1 < 'A' || *hex1 > 'F'){
				return 0;
			}
	         }
	         hex1 += 1;
	}
	return 1;
}



bool if_dec(char* a){
	if((*a == '0') && (*(a + 1) != 'd' ||  *(a + 1) != 'D')){
		a += 2;
	}
	while(*a != '\0'){
 		if(*a < '0' || *a  > '9'){
			return 0;
		} 
		a += 1;
	}
	return 1;
}

