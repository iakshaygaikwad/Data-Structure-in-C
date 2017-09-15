#include<stdio.h>

int main()
{
int arr[] = {1,2,3,4,5},i=0;
int *ptr=&arr[0];
while(i < sizeof(arr)/sizeof(arr[0]))
{
	printf("%d\n", *ptr);
	ptr++;
	i++;
}
return 0;
}
