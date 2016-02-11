#include <stdio.h>
#include <malloc.h>
#include <string.h>

using namespace std;

void test(char here[100]){
	printf("%d\n",(int)sizeof(here));
	printf("%s\n", here);
} 

int main(int argc, char ** argv){
	char a[] = "hello";
	char b[20] = "hello";
	printf("int: %d\n", (int) sizeof(int));
	printf("short: %d\n", (int) sizeof(short));
	printf("long: %d\n", (int) sizeof(long));
	printf("long int: %d\n", (int) sizeof(long int));
	printf("long long int: %d\n", (int) sizeof(long long int));
	printf("float: %d\n", (int) sizeof(float));
	printf("unsigned int: %d\n", (int) sizeof(unsigned int));
	//printf("short: %d\n", (int) sizeof(uint32_t));
	printf("int*: %d\n", (int) sizeof(int *));
	printf("char: %d\n", (int) sizeof(char));
	printf("char*: %d\n", (int) sizeof(char *));
	printf("sizeof(a) %d\n", (int)sizeof(a));
	printf("sizeof(b) %d\n", (int)sizeof(b));
	printf("strlen(a) %d\n", strlen(a));
	printf("sizeof(*a) %d\n", (int)sizeof(*a));
	test(a);
	test(b);
	getchar();
	return 1;
}