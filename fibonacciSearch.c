//fibonacci search 
#include<stdio.h>

//function to find minimum of two numbers
int min(int a, int b)
{return (a<=b)?a:b;}

//fibonacci search function
int fiboSearch(int arr[], int n, int target)
{
	int fm, fm1, fm2, offset, i;
	//initializing 
	fm2 = 0;
	fm1 = 1;
	fm = fm2 + fm1;
	
	//loop1: to know the equal or near fibo number to n
	while(fm<n){
		fm2 = fm1;
		fm1 = fm;
		fm = fm2 +  fm1;
	}
	offset = -1;
	//loop2: for searching
	while(fm>1){
		i = min(offset+fm2, n-1);
		
		if(arr[i]<target){
			fm = fm1;
			fm1 = fm2;
			fm2 = fm - fm1;
			offset = i;
		}
		else if(arr[i]>target){
			fm = fm2;
			fm1 = fm1 - fm2;
			fm2 = fm - fm1;
		}
		else{
			return i+1;
		}
	}
	//last element
	if(fm1 && arr[offset+1]==target){
		return offset + 1;
	}
	return -1;
}
//driving code
int main()
{
	int arr[10], i, n, target, result;
	//input
	printf("Enter the size of your array: ");
	scanf("%d", &n);
	printf("Enter the array: ");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	printf("Enter the target value: ");
	scanf("%d", &target);
	result = fiboSearch(arr, n, target);
	
	if(result>1){
		printf("The target: %d is present at %d position.", target, result);
	}
	else{
		printf("Target value not found :(");
	}
	return 0;
}

