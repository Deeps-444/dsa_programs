//binary search using iterative method
#include<stdio.h>
int main()
{
	int arr[10], i, n, low, high, mid, target, result=0;
	printf("Enter the length of the array: ");//input
	scanf("%d", &n);
	printf("enter a sorted array: ");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	printf("Enter the target value: ");
	scanf("%d", &target);
	//apply binary search
	low = 0;  //initializing
	high = n-1;
	for(i=0; low<=high; i++)
	{
		mid = (low + high)/2; //mid value
	    printf("pass%d mid value: %d\n", i+1, mid);
		if(arr[mid] == target){
			result =1;
			printf("The target is found at %d position: ", mid+1); break;
		}
		else if(arr[mid] < target){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	if(result ==0){
		printf("the target key is not present in this array.");
	}
	return 0;
}
