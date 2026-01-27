/*
 * Programmer: HackOlympus  
 * Date      : 26 Jun 
 * Purpose   : Way_Too_Long_Words  
 */ 

import java.util.* ; 
import java.lang.* ; 

class way_too_long_words 
{
    public static void main(String[] args)
    {
        // main code :
        Scanner scan = new Scanner(System.in) ; 
        int T = scan.nextInt() ;
        scan.nextLine() ;
        for (int i=0;i<T;i++)
        {
            String str = scan.nextLine() ; 
            if (str.length() > 10)
            {
                String res = "" ; 
                res += str.substring(0,1) ; 
                Integer a =  str.substring(1,str.length()-1).length() ;
                res += a.toString() ; 
                res += str.substring(str.length()-1) ;
                System.out.println(res) ; 
            }
            else System.out.println(str) ; 
        }
    }   
}
