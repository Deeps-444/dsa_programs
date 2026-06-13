import java.util.*;
public class QuerySum {

    public static void main(String[] args) {
        int n;
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter a number: ");
        n = scan.nextInt();
        System.out.println("Enter number of queries: ");
        int q = scan.nextInt();

        // first make diffrence array:
        int diff[] = new int[n+1];


        while(q>0){
            int l , r, value;
            System.out.println("l=");
            l = scan.nextInt();
            System.out.println("r =");
            r = scan.nextInt();

            System.out.println("Value = ");
            value = scan.nextInt();

            diff[l] += value;
            diff[r] -= value;
        }
        scan.close();
        return;

    }
}
