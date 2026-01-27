/*
 * Programmer  : HackOlympus 
 * Date        : 28 Jun 2021
 * Purpose     : Word Capitalization 
 */ 

import java.util.* ; 
import java.lang.* ; 

public class word_capitalization
{
    public static int ord(char a)
    {
        return (int) a ; 
    }
    public static void main(String[] args)
    {   
        Scanner scan = new Scanner(System.in) ; 
        String str = scan.nextLine() ;
        char a = str.charAt(0) ; 
        String res = "" ; 
        if (ord(a) >= 65 && ord(a) <= 90)
        {
            System.out.println(str) ; 
        }
        else {
            res += str.substring(0,1).toUpperCase() ;
            res += str.substring(1) ; 
            System.out.println(res) ; 
        }
    }

}  

