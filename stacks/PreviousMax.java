package stacks;
import java.util.*;



public class PreviousMax {

    public static int[] previousGreater(int[] arr){
        int n = arr.length;
        Stack<int[]> stack = new Stack<>();
        int[] ans = new int[n];
        for(int i=0; i<n; i++){
            if (stack.empty()){
                int[] element = new int[2];
                ans[
            }
        }


    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = scan.nextInt();
        }

        scan.close();
        return;
    }

}
