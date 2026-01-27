/*
 * Programmer  : HackOlympus 
 * Date        : 29 Jun 2021
 * Purpose     : Bear and Big Brother 
 */ 

import java.util.* ; 
import java.lang.* ; 

public class bear_and_big_brother
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        int l = scan.nextInt() ; 
        int b = scan.nextInt() ; 
        int x = 0 ; 
        while (l<=b)
        {
            l = l * 3 ; 
            b = b * 2 ;
            x++ ; 
        }
        System.out.println(x) ; 
    }

}  

