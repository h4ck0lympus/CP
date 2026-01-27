/*
 * Programmer  : HackOlympus 
 * Date        : 05 Jul 2021
 * Purpose     : chat room 
 */ 

import java.util.* ; 
import java.lang.* ; 

public class chat_room
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        String inp = scan.nextLine() ;  
        String str = "hello" ; 
        String res = "" ; 
        for (int i=0;i<str.length();i++)
        {
            String a = str.substring(i,i+1) ; 
            for (int j=0;j<inp.length();j++)
            {
                if (a.equals(inp.substring(j,j+1))) 
                {
                    res += inp.substring(j,j+1) ; 
                    inp = inp.substring(j+1) ; 
                    break ; 
                }
            }
        }
        if (res.equals(str)) System.out.println("YES") ;
        else System.out.println("NO") ;  
    }

}  

