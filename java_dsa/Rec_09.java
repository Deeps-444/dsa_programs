package java_dsa;

public class Rec_09 {
    // move all x to the end of string
    public static void rec(String s, int idx){
        if(idx == s.length()){
            return;
        }

        if(s.charAt(idx) != 'x'){
            System.out.print(s.charAt(idx));
        }
        rec(s, idx+1);
        if(s.charAt(idx) == 'x'){
            System.out.print(s.charAt(idx));
        }
    }

    public static void main(String[] args) {
        String s = "axbcxxe";
        System.out.println("s before: " + s);
        System.out.println("s after: ");
        rec(s, 0);

        return;
    }

}
