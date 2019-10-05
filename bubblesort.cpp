#include<stdio.h>
//swap(交换两个数的值)
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
//show(遍历数组)
void show(int *arr,int len){
    for(int i=0;i<len;i++)
      printf("%d",arr[i]);
}
//bubblesort(冒泡算法)
void bubblesort(int *arr,int len){
     for(int i=0;i<len-1;i++)
			for(int j=i+1;j<len-1;j++)
		  	if(*(arr+i)>*(arr+j))
	     	 swap(&arr[i],&arr[j]);
}
//主函数
int main(){
			int arr[] = {2,5,3,6,8};
			int len = sizeof(arr)/sizeof(arr[0]);
			printf("未排序前的数组为:");
			show(arr,len);
			bubblesort(arr,len);
			printf("\n排序后的数组为:");
			show(arr,len);
			return 0;
}
