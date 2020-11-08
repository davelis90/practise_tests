/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Main
{
	public static void main(String[] args) {
	    Solution sol = new Solution();
	    int[] A = {1, 3, 6, 4, 1, 2};
	    int[] B = {1, 2, 3};
        int[] C = {-1, -3};
	    int answer = sol.solution(A);
		System.out.println("Hello World");
	}
	
}

class Solution {
    public int solution(int[] A) {
        // sort array
        Arrays.sort(A);
        // System.out.println(Arrays.toString(A));
        int positive_counter = 1;
        
        // remove duplicate elements
        Set mySet = new HashSet(Arrays.asList(A));
        mySet.toArray(A);
        System.out.println(Arrays.toString(mySet));
        return 0;
    }
}
