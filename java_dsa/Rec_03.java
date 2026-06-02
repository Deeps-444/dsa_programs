package java_dsa;

public class Rec_03 {
    public static int rec(int n){
        if(n==0){
            return 1;
        }
        int x = n * rec(n-1);
        System.out.println("x= "+ x);
        return x;

        
    }
    public static void main(String[] args) {
        int fact = rec(5);
        System.out.println("5! =" + fact);
        return ;
    }
}
