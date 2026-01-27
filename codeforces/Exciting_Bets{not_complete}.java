/*
 * Programmer  : HackOlympus 
 * Date        : 07 Jul 2021
 * Purpose     : Exciting Bets 
 */ 

import java.util.* ; 
import java.lang.* ; 

class exciting_bets
{

    public static int gcd(int a,int b)
    {
        if (b==1) return a ; 
        return gcd(b,a%b) ; 

    }
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        int t = scan.nextInt() ; 
        for (int i=0;i<t;i++)
        {
            int a = scan.nextInt() ; 
            int b = scan.nextInt() ; 
            if (a==b) System.out.println("0 0") ; 
            else if (Math.abs(a-b)==1) System.out.println("1 0") ; 
            else{
                int max = 0 ; 
                int c = 0 ; 
                for (int j=0;j<Math.abs(a-b);j++)
                {
                    if (a < b && gcd(a,b) > max) max = gcd(a,b) ;
                    else if (a>b && gcd(a,b) < max) max = gcd(a,b) ;
                    c++ ;
                    a++ ; 
                    b++ ; 
                }
                System.out.println(max + " " + c) ; 
            }
        }
    }

}  

