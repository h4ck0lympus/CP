/*
 * Programmer  : HackOlympus 
 * Date        : 01 Jul 2021
 * Purpose     : tram 
 */ 

import java.util.* ; 
import java.lang.* ; 

public class tram
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        int n = scan.nextInt() ; 
        int c = 0 ; 
        int x = 0 ; 
        for (int i=0;i<n;i++)
        {
            int a = scan.nextInt() ;
            c -= a ; 
            int b = scan.nextInt() ;
            c += b ;
            if (x < c) x = c ; 
        }
        System.out.println(x) ; 
    }

}  

