package java_dsa;

// we want to multiply x^n
public class Rec_04 {
    public static int rec(int x, int n){
        if(x==0){
            return 0;
        }
        if(n==1) return 1;

        int ans = x * rec(x, n-1);
        System.out.println("ans = " + ans);
        return ans;
    }
    public static void main(String[] args) {
        rec(2, 8);
        return ;
    }
}
