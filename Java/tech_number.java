package NumPrograms;

import java.util.Scanner;

public class TechNumber1 {
	private static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);	
		
		System.out.print("Please Enter Number to Check Tech Number = ");
		int tNum = sc.nextInt();
		
		int temp, firstHalf, secondHalf, Sqsum = 0, count = 0;
		
		for(temp = tNum; temp > 0; temp = temp/10)
		{
			count = count + 1;
		}
		
		if(count % 2 == 0)
		{
			temp = tNum;
			firstHalf  = temp % (int)Math.pow(10,  count /2);
			secondHalf = temp / (int)Math.pow(10,  count /2);
			
			Sqsum = (firstHalf + secondHalf) * (firstHalf + secondHalf);
			
			if(tNum == Sqsum)
			{
				System.out.println(tNum +  " is a Tech Number");
			}
			else
			{
				System.out.println(tNum +  " is Not a Tech Number");
			}
		}
		else 
		{
			System.out.println(tNum +  " is Not a Tech Number");
		}
	}

}
