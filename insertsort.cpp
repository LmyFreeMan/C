#include<stdio.h>
//swap(������������ֵ)
void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
//show(��������)
void show(int *arr, int len) {
	for (int i = 0; i<len; i++)
		printf("%d\t", arr[i]);
}
//insertsort()
//21,25,49,25,16
void insertsort(int *arr, int len) {
	for (int i = 1; i<len; i++) {
		int j = i;
		while (j>0 && arr[j]<arr[j - 1]) {
			swap(&arr[j], &arr[j-1]);
			j--;
		}
	}
}
void main() {
	int arr[] = {2,5,3,6,8};
	insertsort(arr, 5);
	show(arr, 5);
	while (true)
	{
		getchar();
	}
}