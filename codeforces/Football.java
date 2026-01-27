/*
 * Programmer  : HackOlympus 
 * Date        : 29 Jun 2021
 * Purpose     : Football 
 */ 

import java.util.* ; 
import java.lang.* ; 

public class football
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        String str = scan.nextLine() ; 
        
        if (str.contains("1111111") || str.contains("0000000")) System.out.println("YES") ;  
        else System.out.println("NO") ; 
    }

}  

