//insertion sort 
#include<stdio.h>

//declaration of swap function
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//declaring insertion Sort function
void InsertionSort(int arr[], int n)
{
	int i,j, k;
	for(i =0; i<n; i++){
		j=i;
		printf("Pass%d: ", i+1);
		while(j<=i && j>0){
			if(arr[j]<arr[j-1]){
				swap(&arr[j], &arr[j-1]);
			}
			j--;
		}
		for(k=0; k<n; k++){
			printf("%d\t", arr[k]);}
			printf("\n");
	}
}

//driving function
int main()
{
	int arr[10], n, i;
	//input
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter an array: ");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	//sorting
	InsertionSort(arr, n);
	//result
	printf("we will use insertion sort here.\n");
	printf("The sorted array is: ");
	for(i=0; i<n; i++){
			printf("%d\t", arr[i]);
		}
	return 0;
}
