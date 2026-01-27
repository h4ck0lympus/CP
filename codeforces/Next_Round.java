/*
 * Programmer: HackOlympus  
 * Date      : 26 Jun 
 * Purpose   : Next Round  
 */ 

import java.util.* ; 
import java.lang.* ; 

public class next_round 
{
    public static void main(String[] args)
    {
        // n(total) k(kth place) 
        Scanner scan = new Scanner(System.in) ; 
        int n = scan.nextInt() ; 
        int k = scan.nextInt() ; 
        
        int[] arr = new int[n] ; 

        for (int i =0;i<n;i++)
        {
            arr[i] = scan.nextInt() ; 
        }
        
        int kth = arr[k-1] ;
        int c = 0; 
        for (int i : arr)
        {
            if (i >= kth && i > 0) c++ ;  
        }
        System.out.println(c) ; 
    }
}

