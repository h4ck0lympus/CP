/*
 * Programmer  : HackOlympus 
 * Date        : 29 Jun 2021
 * Purpose     : Soldier and Bananas 
 */ 

import java.util.* ; 
import java.lang.* ; 

public class soldier_and_bananas
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        int k = scan.nextInt() ;
        int n = scan.nextInt() ; 
        int w = scan.nextInt() ; 
        int x = 0 ; 
        for (int i=1;i<=w;i++)
        {
            x += k * i ; 
        }
        if (x-n > 0) System.out.println(x-n) ; 
        else System.out.println(0) ; 
    }

}  

