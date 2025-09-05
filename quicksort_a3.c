//quick sort 
#include<stdio.h>

// defining swap function
void swap(int* a, int*b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
//defining function to select pivot element
int partition(int arr[], int l, int r)
{
	int x, j, i; 
	x = arr[r];//pivot
	i = l-1;
	for(j=0; j<r; j++){
		if(arr[j]<=x){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[r]);
	return i+1;
}

// defining function to sort
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
	int arr[10],n, i;
	//input
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter an array: ");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	//sorting
	QuickSort(arr, 0, n-1);
	printf("The sorted array by using Quick Sort Algorithm:\n");
	for(i=0; i<n; i++){
		printf("\t%d", arr[i]);
	}
	return 0;
}
