/*
 * Programmer  : HackOlympus 
 * Date        : 01 Jul 2021
 * Purpose     : word 
 */ 

import java.util.* ; 
import java.lang.* ; 

public class word
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        String word = scan.nextLine() ; 
        char[] arr = word.toCharArray() ; 
        int upper = 0 ; 
        int lower = 0 ; 
        for (int i=0;i<arr.length;i++)
        {
            if (Character.isUpperCase(arr[i])) upper++ ; 
            else if (Character.isLowerCase(arr[i])) lower++ ;
        }
        if (upper > lower) System.out.println(word.toUpperCase()) ; 
        else if (upper <= lower) System.out.println(word.toLowerCase()) ; 
    }

}  

