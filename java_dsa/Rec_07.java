package java_dsa;

public class Rec_07 {

    

    //reversing a string
    public static void rev(String s, int low, int high){
        //base case
        if(low >= high){
            // System.out.println("s = " + s);
            return;
        }

        //recursion
        // s.charAt(low) = s.charAt(high);
        char[] arr = s.toCharArray();
        char temp = s.charAt(high);
        arr[high] = arr[low];
        arr[low] = temp;
        s = new String(arr);
        System.out.println("s = " + s);
        rev(s, low + 1, high -1);
        
    }

    public static void main(String[] args) {
        String s = "abcde";
        System.out.println("s = " + s);
        rev(s, 0, s.length()-1);
        


        return;
    }


}
