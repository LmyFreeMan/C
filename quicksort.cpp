	#include<stdio.h>
//交换两个数 
void swap(int *a,int *b)
{
    int tmp = *a;
    *a= *b;
    *b = tmp;
}
//show(遍历数组)
void show(int *arr,int len){
	 for(int i=0;i<len;i++)
	  printf("%d",arr[i]);
}
void quicksort(int array[],int left,int right){
	//基准值
	int pivot=left;
	//起始值
	left++;
	//结束程序
	if(left>right)
		return;
		//值小于基准值 
	while(left<right){
		while(array[left]<array[pivot]&&left<right)
			left++;
		//如果值大于基准值 
		while(array[right]>array[pivot]&&left<right)
			right--;
		//两个数交换
		swap(&array[left],&array[right]);
		//改变基准值
    }
	swap(&array[right],&array[pivot]);
	//递归执行
	quicksort(array,0,left-1);
    quicksort(array,left+1,right);
}
int main()
{
    int array[5]={5,4,9,5,8};
	//5,4,2,3,8
	//5,4,9,5,8
	quicksort(array,0,4); 
    return 0;
}
