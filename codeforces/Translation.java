/*
 * Programmer  : HackOlympus 
 * Date        : 06 Jul 2021
 * Purpose     : Translation 
 */ 

import java.util.* ; 
import java.lang.* ; 

public class Translation
{
    public static String reverse(String str)
    {
        String rev = "" ; 
        for (int i=str.length()-1;i>=0;i--)
        {
            rev += str.substring(i,i+1) ; 
        }
        return rev ; 
    }
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        String x = scan.nextLine() ;
        String y = scan.nextLine() ;
        if (y.equals(reverse(x))) System.out.println("YES") ; 
        else System.out.println("NO") ;
    }

}  

