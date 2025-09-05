//selection sort 
#include<stdio.h>

//declaration of swap function
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//declaring selection sort
void SelectionSort(int arr[], int n)
{
	int i, j, k, min;
	for(i=0; i<n; i++){
		min = i;
		printf("Pass%d: ", i+1);
		for(j=i+1; j<n; j++){
			if(arr[min]>arr[j]){
				min =j;
			}
		}
		swap(&arr[min], &arr[i]);
		for(k=0; k<n; k++){
			printf("%d\t", arr[k]);}
		printf("\n");
	}
}

//driving code
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
	// sorting the array
	SelectionSort(arr, n);
	printf("We will use Selection sort here.\n");
	printf("\nThe sorted array is: ");
	for(i=0; i<n; i++){
			printf("%d\t", arr[i]);
		}
	return 0;
}


