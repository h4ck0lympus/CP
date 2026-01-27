/*
 * Programmer  : HackOlympus 
 * Date        : 05 Jul 2021
 * Purpose     : Queue at the School 
 */ 

import java.util.* ; 
import java.lang.* ; 

class queue_at_the_school
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        int n = scan.nextInt() ; // total number 
        int t = scan.nextInt() ; // after what time .. 
        String q = scan.nextLine() ; 
        String res = "" ; 
        int i = 0 ; 
        while (i<n)
        {
            if (q.substring(i,i+1).equals("BG"))
            {
                res += q.substring(i,i+t) ; 
                i+=t ; 
            }
        }
        System.out.println(res) ; 
    }

}  

