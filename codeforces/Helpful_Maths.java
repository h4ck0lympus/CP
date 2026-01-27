/*
 * Programmer  : HackOlympus 
 * Date        : 27 Jun 2021
 * Purpose     : Helpful Maths 
 */ 

import java.util.* ; 
import java.lang.* ;

public class helpful_maths
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        String str = scan.nextLine();
        String[] arr = str.split("\\+",0) ;
        
        // int[] tarr = {8,1,4,9,4} ; 
        
        Arrays.sort(arr) ; 
        for (int i=0;i<arr.length;i++)
        {
            if (i==arr.length-1) System.out.print(arr[i]) ;
            else System.out.print(arr[i]+"+") ; 
        }
        System.out.println() ; 

    }

}  

