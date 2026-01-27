/*
 * Programmer  : HackOlympus 
 * Date        : 04 Jul 2021
 * Purpose     : insertion_sort 
 */ 

import java.util.* ; 
import java.lang.* ; 

public class insertion_sort
{
    public static void main(String[] args)
    {   
        long start = System.currentTimeMillis();
        int[] arr = {521, 109, 733, 569, 304, 244, 958, 336} ;
        for (int i=0;i<arr.length;i++)
        {
            for (int j=0;j<arr.length-1;j++)
            {
                if (arr[j] > arr[j+1])
                {   
                    int temp = arr[j] ; 
                    arr[j] = arr[j+1] ; 
                    arr[j+1] = temp ;
                }
            }
        }
        long stop = System.currentTimeMillis();
        for (int i:arr){System.out.print(i+" ") ;} 
        System.out.println() ; 

        System.out.println("time taken(ms) : " + (stop-start)) ; 
    }

}  

