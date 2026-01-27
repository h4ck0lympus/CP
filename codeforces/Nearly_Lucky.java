/*
 * Programmer  : HackOlympus 
 * Date        : 05 Jul 2021
 * Purpose     : Nearly_Lucky 
 */ 

import java.util.* ; 
import java.lang.* ; 

public class Nearly_Lucky
{
    public static boolean isLucky(long n)
    {
        boolean ok ; 
        if (n != 0) ok = true ; 
        else ok = false ; 
        while (n > 0 && ok) 
        {
            if (n % 10 == 4 || n%10 == 7){
                n = n / 10 ;     
            }
            else ok = false ; 
        }
        return ok ; 
    }
    public static long numOfLuck(long n)
    {
        long c = 0 ; 
        while (n>0)
        {
            if (n%10 == 4 || n % 10 == 7) 
            {
                c++ ; 
                n = n / 10 ; 
            }
            else  n = n / 10 ; 

        }
        return c ; 
    }
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        long n = scan.nextLong() ; 
        n = numOfLuck(n) ;  
        if (isLucky(n)) System.out.println("YES"); 
        else System.out.println("NO") ; 
    }

}  

