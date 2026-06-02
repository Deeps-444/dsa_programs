package java_dsa;
// will implement tower of hanoi
public class Rec_05 {

    public static void hanoi(int n, String src, String helper, String dest){
        //base case
        if(n==1){
            System.out.println("(Transfer disk " + n + " from " + src + " to " + dest);
            return;
        }

        //recursion
        hanoi(n-1, src, dest, helper);
        System.out.println("Transfer disk " + n + " from " + src + " to " + dest);
        hanoi(n-1, helper, src, dest);

    }
    public static void main(String[] args) {
        int n=3;
        hanoi(n, "S", "H", "D");
        return ;
    }

}
