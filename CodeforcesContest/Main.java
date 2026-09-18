import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {

        Scanner scan = new Scanner(System.in);

        int t = scan.nextInt();

        for(int i = 0; i < t; i++){

            int n = scan.nextInt();

            int[] a = new int[n];

            for(int j = 0; j < n; j++){
                a[j] = scan.nextInt();
            }

            
            int ones = 0;
            for(int j = 0; j < n; j++){
                if(a[j] == 1){
                    ones++;
                }
            }

            if (ones > ((n-1)/2)){
                System.out.println("Bessie");
            }else{
                System.out.println("Elsie");
            }
        }

        scan.close();
    }
}