#include<stdio.h>
//quick sort

void swap(int* a, int*b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
// function
int partition(int  arr[], int l, int r)
{
	int x, i , j;
	x = arr[r];//pivot
	i = l-i;
	for(j=0;j<r; j++){
		if(arr[j]<x){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[r]);
	return i+1;
}
void QuickSort(int arr[], int l, int r)
{
	int p;
	if(l<r){
		p = partition(arr, l, r);
		QuickSort(arr, l, p-1);
		QuickSort(arr, p+1, r);
	}
}


int main()
{
	int arr[10], i , j, n; 
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter the elements of array: ");
	for(i = 0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	//sorting
	QuickSort(arr, 0, n);
	printf("\nthe sorted array is: \t");
	for(i = 0; i<n; i++){
		printf("%d\t", arr[i]);
	}
}
