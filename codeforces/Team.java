/*
 * Programmer: HackOlympus  
 * Date      : 26 Jun 
 * Purpose   : Team  
 */ 

import java.util.* ; 
import java.lang.* ; 

public class team 
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        int T =  scan.nextInt() ; 
        int c = 0 ; 
        for (int i=0;i<T;i++)
        {
            int[] arr = new int[3] ; 
            int sum = 0 ; 
            for (int j=0;j<arr.length;j++)
            {
                arr[j] = scan.nextInt() ;
                sum+=arr[j] ; 
            }   
            if (sum >=2) c++;
        }
        System.out.println(c) ; 
    }
}

