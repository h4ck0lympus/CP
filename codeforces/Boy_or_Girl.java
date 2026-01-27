/*
 * Programmer  : HackOlympus 
 * Date        : 29 Jun 2021
 * Purpose     : Boy or Girl 
 */ 

import java.util.* ; 
import java.lang.* ; 

public class boy_or_girl
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        String str = scan.nextLine() ; 
        char[] strarr =  str.toCharArray() ; 
        ArrayList<Character> arr = new ArrayList<Character>() ; 
        for (int i=0;i<strarr.length;i++)
        {
            if (arr.indexOf(strarr[i]) < 0)
            {
                arr.add(strarr[i])  ; 
            }
        }
        if (arr.size() % 2 == 0) System.out.println("CHAT WITH HER!");
        else System.out.println("IGNORE HIM!");
    }

}  

