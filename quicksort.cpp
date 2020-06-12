	#include<stdio.h>
//���������� 
void swap(int *a,int *b)
{
    int tmp = *a;
    *a= *b;
    *b = tmp;
}
//show(��������)
void show(int *arr,int len){
	 for(int i=0;i<len;i++)
	  printf("%d",arr[i]);
}
void quicksort(int array[],int left,int right){
	//��׼ֵ
	int pivot=left;
	//��ʼֵ
	left++;
	//��������
	if(left>right)
		return;
		//ֵС�ڻ�׼ֵ 
	while(left<right){
		while(array[left]<array[pivot]&&left<right)
			left++;
		//���ֵ���ڻ�׼ֵ 
		while(array[right]>array[pivot]&&left<right)
			right--;
		//����������
		swap(&array[left],&array[right]);
		//�ı��׼ֵ
    }
	swap(&array[right],&array[pivot]);
	//�ݹ�ִ��
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
