//binary search
//using recursion
#include<stdio.h>

//binary search function
int BinarySearch(int arr[], int t, int l, int h, int i)
{
	int  mid;
	if(l <= h)
	{
		mid = (l + h)/2;
		printf("pass %d mid value = %d\t", i+1, mid);
		if(arr[mid] == t){
			return mid; 
		}
		else if(arr[mid] > t){
			return BinarySearch( arr, t, l, mid-1, i+1);
		}
		else{
			return BinarySearch(arr, t, mid+1, h, i+1);
		}
	}
	return -1;
}

int main()
{
	int arr[10], n, i, target, low, high, result;
	//input
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("enter a sorted array: ");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	printf("Enter the target value: ");
	scanf("%d", &target);
	
	low = 0;
	high = n-1;
	
	result = BinarySearch(arr, target, low, high, 0);
	if (result != -1){
		printf("\n Target value is found at %d position.", result+1);
	}
	else{
		printf("\nTarget value is not found");
	}
	return 0;
}
