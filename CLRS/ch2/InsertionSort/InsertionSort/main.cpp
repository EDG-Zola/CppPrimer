#include<iostream>
int *insertionSort(int *A, int length); 
int main()
{
	int A[6]={5, 2, 4, 6, 1, 3};
	int *B = insertionSort(A,sizeof(A)/sizeof(int));
	for (int i = 0; i<6; i++){
		std::cout << *(B+i) << std::endl;
	}
	system("pause");
	return 0;
}

int *insertionSort(int *A, int length){
	/*
	*插入排序算法:时间复杂度为O(n**2)
	*功能：从小到大排序
	*输入参数：
	*输出参数：
	*注意：下标的引用
	*/
	int key = 0, i=0;
	for(int j = 1; j < length; j++){
		key = *(A+j);
		i = j - 1;
		while ((i >= 0 ) && (*(A+i) > key)){
			*(A+i+1) = *(A+i);
			i--;
		}
		*(A+i+1) = key;
	}
	return A;
} 