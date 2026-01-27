/*
 * Programmer: HackOlympus  
 * Date      : 26 Jun 
 * Purpose   : Watermelon  
 */ 

import java.util.* ; 
import java.lang.* ; 

class watermelon 
{
    public static void main(String[] args)
    {
        System.out.println("------------------------- START --------------------------\n") ; 
        final long startTime = System.currentTimeMillis(); 

        // main code :         
        Scanner scan = new Scanner(System.in) ; 
        int w = scan.nextInt() ; 
        if (w==2) System.out.println("NO") ; 
        else if (w % 2 == 0 ) System.out.println("YES") ; 
        else System.out.println("NO") ; 


        final long endTime = System.currentTimeMillis();
        System.out.println("Total execution time (ms): " + (float)(endTime - startTime)/1000);
        System.out.println("\n----------------------- FINISHED -------------------------") ; 
    }
}

