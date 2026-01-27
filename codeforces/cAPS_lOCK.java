/*
 * Programmer  : HackOlympus 
 * Date        : 30 Jun 2021
 * Purpose     : cAPS lOCK 
 */ 

import java.util.* ; 
import java.lang.* ; 

public class caps_lock
{
    public static boolean isUpper(String str)
    {
        char[] arr = str.toCharArray() ; 
        for (int i=0;i<arr.length;i++)
        {
            if (!Character.isUpperCase(arr[i])) return false ; 
        }
        return true ; 
    }
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        String str = scan.nextLine() ;  
        
        if (isUpper(str)) {
            System.out.println(str.toLowerCase()) ;  
        }
        else if (!isUpper(str.substring(0,1)) && isUpper(str.substring(1)))
        {
            System.out.println(str.substring(0,1).toUpperCase() + str.substring(1).toLowerCase()); 
        }
        else System.out.println(str) ; 
        
    }

}  

