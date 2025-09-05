//Merge Sort 
#include<stdio.h>

//function to merge the sub-arrays
void Merge(int arr[], int l, int m, int r)
{
	int i, j, k, n1, n2, t, n;
	n = r-l;
	n1 = m+1-l; //size of left subarray
	n2 = r-m;//size of right sub-array
	int L[n1], R[n2]; // left and right subarrays
	
	for(i=0; i<n1; i++){
		L[i] = arr[l+i];
	}
	for(j=0; j<n2; j++){
		R[j] = arr[m+1+j];
	}
	i=0;
	j=0;
	k = l;
	//sorting and merging
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k] = R[j];
		j++;
		k++;
	}
	for(t=0; t<n; t++){
		printf("%d\t", arr[t]);
	}
	printf("\n");
}

void MergeSort(int arr[], int l, int r)
{
	int m, i;
	if(l<r){
		m = (l+r)/2;
		MergeSort(arr, l, m);
		MergeSort(arr, m+1, r);
		Merge(arr, l, m , r);
	}
}

int main()
{
	int arr[10], i, n;
	//input
	printf("Enter size of array: ");
	scanf("%d", &n);
	printf("Enter array : ");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	MergeSort(arr, 0, n-1);
	printf("\nThe sorted array using Merge sort is: ");
	for(i=0; i<n; i++){
		printf("%d\t", arr[i]);
	}
}
