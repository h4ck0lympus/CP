/*
 * Programmer  : HackOlympus 
 * Date        : 01 Jul 2021
 * Purpose     : Elephant 
 */ 

import java.util.* ; 
import java.lang.* ; 

public class elephant
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        int x = scan.nextInt() ; 
        int c = 0 ; 
        while (x>0){
            if (x >= 5) {
                x = x - 5 ; 
                c++ ; 
            }
            else if (x>=4){
                x = x -4 ; 
                c++ ; 
            }
            else if (x>=3){
                x= x-3 ; 
                c++ ; 
            }
            else if (x>=2){
                x = x-2 ; 
                c++ ; 
            }
            else if (x>=1){
                x=x-1 ; 
                c++ ; 
            }
        }
        System.out.println(c) ; 
    }

}  

