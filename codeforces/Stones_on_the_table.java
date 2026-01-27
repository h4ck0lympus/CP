/*
 * Programmer  : HackOlympus 
 * Date        : 29 Jun 2021
 * Purpose     : Stones on the table 
 */ 

import java.util.* ; 
import java.lang.* ; 

public class stones_on_the_table
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        int len = scan.nextInt() ; 
        scan.nextLine() ; 
        String str = scan.nextLine() ;
        int c = 0 ; 
        for (int i=0;i<len-1;i++)
        {
            if (str.substring(i,i+1).equals(str.substring(i+1,i+2))) c++ ; 
        }
        System.out.println(c) ; 
    }

}  

