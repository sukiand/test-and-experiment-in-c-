#include <stdio.h>

void sort1(int *a, int *b){
	int * temp;
	temp = a;
	a = b;
	b = temp;
}

//void sort2(int *a, int *b){
//	int *temp;
//	*a = *b;
//	*b = *temp;
//}

void sort3(int a, int b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void sort4(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void sort5(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(int argc, char ** argv){
	int a = 1, b = 2;
	int *p1, *p2;
	p1 = &a;
	p2 = &b;
	printf("initial\ta:%d,b:%d\n", a, b);
	
	sort1(&a, &b);
	printf("sort1\ta:%d,b:%d\n", a, b);
	sort1(p1,p2);
	printf("sort1\ta:%d,b:%d\n", *p1, *p2);

	a = 1;
	b = 2;
	sort3(a, b);
	printf("sort3\ta:%d,b:%d\n", a, b);

	a = 1;
	b = 2;
	sort4(a, b);
	printf("sort3\ta:%d,b:%d\n", a, b);

	a = 1;
	b = 2;
	sort5(&a, &b);
	printf("sort5\ta:%d,b:%d", a, b);

	getchar();
	return 1;
}