/*
 * Programmer  : HackOlympus 
 * Date        : 27 Jun 2021
 * Purpose     : Beautiful Matrix 
 */ 

import java.util.* ; 
import java.lang.* ; 

public class beautiful_matrix
{
    public static int[] getRowPos(int[][] arr)
    {
        int[] res = new int[2] ; 
        for (int row =0;row<arr.length;row++)
        {
            for (int col = 0;col<arr[0].length;col++)
            {
                if (arr[row][col] == 1) 
                {
                    res[0] = row ; 
                    res[1] = col ; 
                    return res ; 
                }
            }
        }
        return res ; 
    }
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in) ; 
        // step 1 do something for input 
        int[][] arr = new int[5][5] ; 

        for (int row=0;row<5;row++)
        {
            for (int col=0;col<5;col++)
            {
                arr[row][col] = scan.nextInt() ; 
            }
        }
        
        int row = 2 ; // 5 / 2  
        int col = 2 ; // 5 / 2 
        
        int[] pos  = getRowPos(arr) ; 
        int total = 0 ; 
        total += Math.abs(pos[0] - row) ; 
        total += Math.abs(pos[1] - col) ; 
        System.out.println(total) ; 
    }

}  

