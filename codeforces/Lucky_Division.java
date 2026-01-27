/*
 * Programmer  : HackOlympus 
 * Date        : 29 Jun 2021
 * Purpose     : Lucky Division 
 */ 

import java.util.* ; 
import java.lang.* ; 

public class lucky_division
{
    public static boolean isLucky(int num)
    {
        int x = num ; 
        while (((x%10 == 4) || (x%10 == 7) && x >0))
        {
            x = x / 10 ; 
        }
        return (x==0) ; 
    }
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        int x = scan.nextInt() ; 

        if (isLucky(x)) System.out.println("YES") ; 
        else if (x % 4 == 0 || x%7==0 || x%47 ==0) System.out.println("YES") ; 
        else System.out.println("NO") ; 
    }

}  

