import java.io.*;

class BinarySearch
{
public static void main(String args[]) throws IOException
{

BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

int a[]={7, 10, 12, 34, 45,51, 60, 78, 81, 92};

int key, low=0, high=a.length-1, mid=0;

System.out.print("Enter the integer to search:");        
key=Integer.parseInt(br.readLine());

while(low<=high){

mid=(low+high)/2;

if (key==a[mid])
break;

else if(key<a[mid])
high=mid-1;

else
low=mid+1;
}

if(low<=high)
System.out.println(key+" found at index "+mid);

else
System.out.println(key+" not found");
}
}
