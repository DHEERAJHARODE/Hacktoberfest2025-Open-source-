
class MostPeopleSleep{
	int sleepHours;
	
	MostPeopleSleep(int sleepHours)
	{
		this.sleepHours= sleepHours;
	}
	
	MostPeopleSleep()
	{
		
		
	}
	
	void Print()
	{
		System.out.println("sleep hours: "+sleepHours);
		System.out.println();
	}
}

class SomePeopleWalk extends MostPeopleSleep{
	int sleepHours, walkHours;
	
	SomePeopleWalk()
	{
		
	}
	
	SomePeopleWalk(int sleepHours, int walkHours )
	{
		this.sleepHours = sleepHours;
		this.walkHours= walkHours;
	}
	
	void Print()
	{
		System.out.println("sleep hours: "+sleepHours);
		System.out.println("walk hours: "+walkHours);
		System.out.println();
	}
}

class FewPeopleJog extends SomePeopleWalk{
	int  sleepHours,walkHours,jogHours;
	
	FewPeopleJog(int sleepHours, int walkHours, int jogHours)
	{
		this.sleepHours = sleepHours;
		this.walkHours = walkHours;
		this.jogHours = jogHours;
	}
	
	void Print()
	{
		System.out.println("sleep hours: "+sleepHours);
		System.out.println("walk hours: "+walkHours);
		System.out.println("jog hours: "+jogHours);
		System.out.println();
	}
	
}

public class FunctionOverriding {

	public static void main(String[] args) {
	MostPeopleSleep objectone= new MostPeopleSleep(5);
	objectone.Print();
	objectone = new SomePeopleWalk(2,3);
	objectone.Print();
	objectone = new FewPeopleJog(1,2,2);
	objectone.Print();

	}

}
