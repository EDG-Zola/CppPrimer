/************************************************************************/
/* 归并排序                                                                     */
/************************************************************************/
#include <iostream>
#include <math.h>
using namespace std;

/************************************************************************/
/* 函数原型声明                                                                     */
/************************************************************************/
void merge(int *A, int p, int q, int r);
void mergeSort(int *A, int p, int r);
int main(){
	system("Color 5E");
	const int arraySize = 8;
	int A[arraySize] = {2, 4, 5, 7, 1, 2, 3, 6};
	mergeSort(A, 0, arraySize - 1);//归并排序
	for (int i=0; i < 8; ++i)
		cout << *(A+i) << " ";
	cout << endl;
	system("pause");
	return 0;
}

void mergeSort(int *A, int p, int r){
	if (p < r){
		int q = (int) (p+r)/2;
		mergeSort(A, p, q);
		mergeSort(A, q+1, r);
		merge(A, p, q, r);
	}
}

void merge(int *A, int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = new int[n1+1];
	int *R = new int[n2+1];
	//let L[1 ... n1+1] and R[1 ... n2+1] be new arrays
	for (int i = 0; i < n1; ++i)
		*(L+i) = A[p + i];
	for (int j = 0; j < n2; ++j)
		*(R+j) = A[q + j +1];
	*(L+n1) = 'q';
	*(R+n2) = 'q';
	int i = 0, j = 0;
	for (int k = p; k <= r; ++k){
		if (*(L+i) <= *(R+j)){
			A[k] = *(L+i);
			i += 1;
		}
		else{
			A[k] = *(R+j);
			j += 1;
		}
	}
	delete [] L;
	delete [] R;
}