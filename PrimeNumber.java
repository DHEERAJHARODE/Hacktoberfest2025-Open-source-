package primrnumber;

import java.util.Scanner;

public class PrimeNumber {
	public static void main(String ar[])
	{
		Scanner prime=new Scanner(System.in);
		System.out.println("Enter the no. that you want to check:");
		int a=prime.nextInt();
		int i,j;
		for(i=1;i<=a;i++)
		{
			for(j=0;j<i;j++)
			{
				System.out.print("*");
			}
			System.out.println("\n");
		}
		
	}
}
