/*
 * Programmer: HackOlympus  
 * Date      : 25 Jun 
 * Purpose   : String_tokenizer  
 */ 

import java.util.* ; 
import java.lang.* ; 

public class string_tokenizer 
{
    public static void main(String[] args)
    {
        System.out.println("------------------------- START --------------------------\n") ; 
        final long startTime = System.currentTimeMillis(); 

        // main code :         

        StringTokenizer st = new StringTokenizer("hello world") ; 
        while (st.hasMoreTokens()) 
        {
            System.out.println(st.nextToken());
        }




        final long endTime = System.currentTimeMillis();
        System.out.println("Total execution time (ms): " + (float)(endTime - startTime)/1000);
        System.out.println("\n----------------------- FINISHED -------------------------") ; 
    }
}

