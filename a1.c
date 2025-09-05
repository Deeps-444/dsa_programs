//program for linear search with optimization
#include<stdio.h>

int main(){
	int n, arr[10], i, target, result;
	
	//taking input of max length of array
	printf("Enter desired length of the array: ");
	scanf("%d", &n);
	// array input
	printf("enter the sorted array: ");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	} 
	//target input
	printf("enter the target value: ");
	scanf("%d", &target);
	
	//linear search
	for(i=0; i<n; i++){
		if(target<arr[i]) //optimization of program
		{
			break;
		}
		else{
			if(target == arr[i]){
				printf("target value is found at %d position.", i+1);
				result =1; //break; => removing break to check repetition of target value
			}
		}
	}
	if(result == 0){
		printf("target value is not present in this array.");
	}
	return 0;
}
