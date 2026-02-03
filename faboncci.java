Input: N = 10 
Output: 0 1 1 2 3 5 8 13 21 34 
Here first term of Fibonacci is 0 and second is 1, so that 3rd term = first(o) + second(1) etc and so on.

// Java program for the above approach

class GFG {

	// Function to print N Fibonacci Number
	static void Fibonacci(int N)
	{
		int num1 = 0, num2 = 1;

		int counter = 0;

		// Iterate till counter is N
		while (counter < N) {

			// Print the number
			System.out.print(num1 + " ");

			// Swap
			int num3 = num2 + num1;
			num1 = num2;
			num2 = num3;
			counter = counter + 1;
		}
	}

	// Driver Code
	public static void main(String args[])
	{
		// Given Number N
		int N = 10;

		// Function Call
		Fibonacci(N);
	}
}
