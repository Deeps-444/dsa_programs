package java_dsa;

public class Rec_02 {
    public static void rec(int n, int sum){
        //base case
        if(n<0){
            return;
        }
        // recursion
        // int sum =0;
        // sum += n;
        System.out.println("n=" + n + " Sum =" + sum);
        rec(n-1, sum + n);
        System.out.println("n=" + n);
    }
    public static void main(String[] args) {
        System.out.println("rec: ");
        rec(5, 0);
        return ;

    }
}
