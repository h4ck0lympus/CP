/*
 * Programmer: HackOlympus  
 * Date      : 26 Jun 
 * Purpose   : Bit++  
 */ 

import java.util.* ; 
import java.lang.* ; 

public class bit 
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        String inc1 = "++X" ; 
        String inc2 = "X++" ; 
        String dec1 = "--X" ; 
        String dec2 = "X--" ; 

        int T = scan.nextInt() ;
        scan.nextLine() ; 
        int value = 0 ; 
        for (int i=0;i<T;i++)
        {
            String str = scan.nextLine() ; 
            if (str.equals(inc1) || str.equals(inc2)) value++ ; 
            else if  (str.equals(dec1) || str.equals(dec2)) value-- ; 
        }
        System.out.println(value) ; 
    }
}

