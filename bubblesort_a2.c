//bubble sort
#include<stdio.h>
//declaration of swap function
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//bubble sort function 
void BubbleSort(int arr[], int n)
{
	int i, j,k, swapped;

	for(i=0; i<n-1; i++){
		swapped = 0; // for optimization of bubble sort;
		for(j=0; j<n-1-i; j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
				swapped = 1;
			}
		}
		if(swapped == 0){
			break;}
		printf("Pass %d : ", i+1);
		for(k=0; k<n; k++){
			printf("%d\t", arr[k]);}
		printf("\n");
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
	// sorting the array
	BubbleSort(arr, n);
	printf("\nwe will use Bubble sort here.\n");
	printf("\nThe sorted array is: ");
	for(i=0; i<n; i++){
			printf("%d\t", arr[i]);
		}
	return 0;
}
