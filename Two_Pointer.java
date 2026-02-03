import java.util.Arrays;
import java.util.List;

public class PairSum {
	// Two pointer technique based solution to find
	// if there is a pair in A[0..N-1] with a given sum.
	public static int isPairSum(List<Integer> A, int N,
								int X)
	{
		// represents first pointer
		int i = 0;

		// represents second pointer
		int j = N - 1;

		while (i < j) {
			// If we find a pair
			if (A.get(i) + A.get(j) == X)
				return 1;

			// If sum of elements at current
			// pointers is less, we move towards
			// higher values by doing i++
			else if (A.get(i) + A.get(j) < X)
				i++;

			// If sum of elements at current
			// pointers is more, we move towards
			// lower values by doing j--
			else
				j--;
		}
		return 0;
	}

	// Driver code
	public static void main(String[] args)
	{
		// array declaration
		List<Integer> arr
			= Arrays.asList(2, 3, 5, 8, 9, 10, 11);

		// value to search
		int val = 17;

		// size of the array
		int arrSize = arr.size();

		// array should be sorted before using the
		// two-pointer technique
		arr.sort(null);

		// Function call
		System.out.println(isPairSum(arr, arrSize, val)
						!= 0);
	}
}
