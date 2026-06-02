package java_dsa;

public class Rec_08 {
    // giving first nad last occurence of an element in a string
    public static void rec(String s, int idx, char element){

        if(idx == s.length()){
            return;
        }
        
        if(s.charAt(idx) == element){
            System.out.println("idx =" + idx);
        }
        rec(s, idx+1, element);    

    }

    public static void main(String[] args) {
        String s = "abcadefagh";
        rec(s, 0, 'a');
        return;

    }

}
