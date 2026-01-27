/*
 * Programmer: HackOlympus  
 * Date      : 25 Jun 
 * Purpose   : SpaceSeperatedInput  
 */ 

import java.util.* ; 
import java.lang.* ; 

public class space_seperated_input 
{
    public static void main(String[] args)
    {
        System.out.println("------------------------- START --------------------------\n") ; 
        final long startTime = System.currentTimeMillis(); 
        
        Scanner scan= new Scanner(System.in) ; 

        // main code :         
        int n = scan.nextInt() ; 
        int k=  scan.nextInt() ; 
        int count = 0 ; 
        for (int i=0;i<n;i++)
        {
            int t = scan.nextInt() ; 
          
            if (t % k == 0) count++ ; 
        }
        System.out.println(count) ; 
        



        final long endTime = System.currentTimeMillis();
        System.out.println("Total execution time (ms): " + (float)(endTime - startTime)/1000);
        System.out.println("\n----------------------- FINISHED -------------------------") ; 
    }
}

