/*
 * Programmer  : HackOlympus 
 * Date        : 07 Jul 2021
 * Purpose     : Anton and Danik 
 */ 

import java.util.* ; 
import java.lang.* ; 

public class anton_and_danik
{
    public static void main(String[] args)
    {
        int A = 0 ; 
        int D = 0 ; 
        Scanner scan = new Scanner(System.in) ; 
        int g = scan.nextInt() ;
        scan.nextLine() ;
        String str = scan.nextLine() ; 
        for (int i=0;i<g;i++)
        {
            if (str.substring(i,i+1).equals("A")) A++ ; 
            else D++  ; 
        }
        if (A>D) System.out.println("Anton") ; 
        else if (D>A) System.out.println("Danik") ; 
        else System.out.println("Friendship") ; 
        
    }

}  

