#include<stdio.h>

void Swap(int*,int*);
int main()
{
	int num1=10, num2=20;
	int *ptr1,*ptr2;
	ptr1  = &num1;
	ptr2 = &num2;
	printf("Before Swap: \nNumber 1 = %d,\tNumber 2 = %d\n", *ptr1, *ptr2);
	Swap(&ptr1, &ptr2);
	printf("After Swap: \nNumber 1 = %d,\tNumber 2 = %d\n", *ptr1, *ptr2);
	return 0;
}
void Swap(int *ptrx1, int *ptrx2)
{
	*ptrx1 = *ptrx1+*ptrx2;
	*ptrx2 = *ptrx1-*ptrx2;
	*ptrx1 = *ptrx1-*ptrx2;
}
