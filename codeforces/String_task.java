/*
 * Programmer: HackOlympus  
 * Date      : 26 Jun 
 * Purpose   : String task  
 */ 

import java.util.* ; 
import java.lang.* ; 

public class string_task 
{
    public static String deleteVow(String str)
    {
        String a = "" ; 
        for (int i=0;i<str.length();i++)
        {
            if ((ord(str.charAt(i)) != 65 && ord(str.charAt(i)) != 69 && ord(str.charAt(i)) != 73 && ord(str.charAt(i)) != 79 && ord(str.charAt(i)) != 85 && ord(str.charAt(i)) != 89) && 
                (ord(str.charAt(i)) != 97 && ord(str.charAt(i)) != 101 && ord(str.charAt(i)) != 105 && ord(str.charAt(i)) != 111 && ord(str.charAt(i)) != 117 && ord(str.charAt(i)) != 121)) 
            {
                a += str.substring(i,i+1) ; 
            }
        }
        return a; 
    }

    public static int ord(char i)
    { 
        return (int) i ; 
    }

    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in); 
        String str = scan.nextLine() ; 
        str = deleteVow(str) ; 
        String res = "" ; 
        for (int i=0;i<str.length();i++)
        {
            res += "." + str.substring(i,i+1) ; 
        }

        System.out.println(res.toLowerCase()) ; 
    }
}

