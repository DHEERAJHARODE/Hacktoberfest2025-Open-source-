// A naive recursive Java program to count number of ways to cover a distance with 1, 2 and 3 steps
import java.io.*;

class GFG
{
	// Function returns count of ways to cover 'dist'
	static int printCountRec(int dist)
	{
		// Base cases
		if (dist<0)
			return 0;
		if (dist==0)
			return 1;

		// Recur for all previous 3 and add the results
		return printCountRec(dist-1) +
			printCountRec(dist-2) +
			printCountRec(dist-3);
	}
	
	// driver program
	public static void main (String[] args)
	{
		int dist = 4;
		System.out.println(printCountRec(dist));
	}
}
