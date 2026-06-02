package binarySearch;

public class MinMax {
    public static boolean f(int mid, int n , int[] arr){
        for(int i=0; i< n-1; i++){
            int difference = arr[i+1] - arr[i];
        }
        
    }
    
     public static void findShifting(int[] nums){
        //bianry search

        // find th f(mid)

        //send step
        int n = nums.length;
        int low =0;
        int high = n-1;
        int ans = 0;
        while(low<high){
            int mid = low + (high-low)/2;
            /*
            for a given array tell yes or no */

            if(f(mid, nums[0], nums)){
                low = mid + 1;
                ans = mid;
            }else{
                high = mid -1;

            }
        }
    }

    public static void main(String[] args) {
        return;
    }
}
