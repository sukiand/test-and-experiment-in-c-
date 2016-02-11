#include <stdio.h>
void main(){
	/*int x = 10;
	x =x- x--;
	printf("%d", x);*/

	/*int x = 1, y = 1, z = 1;
	int t = x | y && z;
	printf("%d", z);*/

	//int x, y;
	//for (x = 1, y = 1; y <= 50; ++y){
	//	if (x = 10) break;
	//	if (x % 2 == 1){
	//		x = 5;
	//		continue;
	//	}
	//	x -= 3;
	//}
	//printf("%d\n", ++y);

	/*int a = 1, b = 10;
	do 
	{
		b -= a;
	} while (b--<0);
	printf("%d\n", b);*/

	//int j;
	//for (j = 10; j > 3; j--){
	//	if (j % 3) j--;
	//	--j; --j;
	//	printf("%d\n", j);
	//}

	//int arr[] = { 6, 7, 8, 9, 10 };
	//int *ptr;
	//ptr = arr;
	//*(ptr + 2) += 2;
	//printf("%d,%d\n", *ptr, *(ptr + 2));

	int i, k, a[10], p[3];
	k = 5;
	for (i = 0; i < 10; i++){ a[i] = i; }
	for (i = 0; i < 3; i++){ p[i] = a[i*i]; }
	for (i = 0; i < 3; i++){ k = p[i] * 2; }
	printf("%d\n", k);
	getchar();
}