#include<stdio.h>
//swap(������������ֵ)
void swap(int *a,int *b){
	int temp;
    temp=*a;
	*a=*b;
    *b=temp;
}
//show(��������)
void show(int *arr,int len){
	 for(int i=0;i<len;i++)
	  printf("%d",arr[i]);
}
//bubblesort(ð���㷨)
void bubblesort(int *arr,int len){
	for(int i=0;i<len-1;i++)
		for(int j=i+1;j<len-1;j++)
			if(*(arr+i)>*(arr+j))
				swap(&arr[i],&arr[j]);
}
//������
int main(){
	int arr[] = {2,5,3,6,8};
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("δ����ǰ������Ϊ:");
  	show(arr,len);
    bubblesort(arr,len);
	printf("\n����������Ϊ:");
	show(arr,len);
	return 0;
}