#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class ArrayADT
{
	private:
		int capacity;
		int lastindex;
		int *ptr;
		protected:
			void doublearray(int cap);
			void halfarray(int cap);
		public:
	void createarray(int cap);
	void insert(int index,int data);
	void append(int data);		
    void del(int index);
	void edit(int index,int data);  
    int count();
    int search(int data);
    int getitem(int index);
 ~ArrayADT()
 {
 	delete[]ptr;
 }
 void 
};
int ArrayADT::getitem(int index)
{
	if(index<0||index>lastindex)
	{
		cout<<"\noperation failed:invalid index";
	}
	else
	{
		return ptr[index];
	}
}
int ArrayADT::search(int data)
{
	int i;
	for(i=0;i<=lastindex;i++)
	if(ptr[i]==data)
	return i;
	else 
	return -1;
}
int ArrayADT::count()
{
	return lastindex+1;
}
void ArrayADT::edit(int index,int data)
{
	if(index<0 ||index>lastindex)
	{
	cout<<"operation fail:invalid index";
	}
	else
	{
		ptr[index]=data;
	}
}

void ArrayADT::del(int index)
{
	int i;
	if(index<0 || index>lastindex)
	{
		cout<<"\ninvalid index";
	}
	else
	{
		for(i=index;i<lastindex;i++)
		ptr[i]=ptr[i+1];
		lastindex--;
	}
}
void ArrayADT::insert(int index,int data)
{
	int i;
	if(index<0 || index>lastindex+1)
	{
		cout<<"\n invalid index of an array";
	}
	else if(lastindex+1==capacity)
	{
		cout<<"operation failed:array overflow";
	}
	else
	{
		for(i=lastindex;i>=index;i--)
		ptr[i]=ptr[i+1];
	    ptr[index]=data;
		lastindex++; 
	}
}
void ArrayADT::append(int data)
{
	int index;
	if(lastindex+1==capacity)
	{
		cout<<"\noperation failed:array overflow";
	}
	else
	{
		lastindex++;
		ptr[lastindex]=data;
	}
}
void ArrayADT::createarray(int cap)
{
	ptr=new int[cap];
	capacity=cap;
	lastindex=-1;
}
int menu()
{
	int choice;
	cout<<"\n1.append";
	cout<<"\n2.insert";
	cout<<"\n3.delete";
	cout<<"\n4.edit";
	cout<<"\n5.search";
	cout<<"\n6.exit";
	cout<<"\n enter your choice";
	cin>>choice;
	return choice;
}
void viewarrayADT(ArrayADT &arr)
{
	int i;
	cout<<"endl";
	for(i=0;i<arr.count();i++)
	{
		cout<<arr.getitem(i)<<" ";
	}
}
int main()
{
	int data,index;
	ArrayADT arr;
	arr.createarray(6);
	while(true)//loop infinite hai isliye condition true
	{
		system("cls");
		cout<<"\n total elements in array: "<<arr.count();
		viewarrayADT(arr);
		switch(menu())
		{
			case 1:
				cout<<"enter data to append";
				cin>>data;
				arr.append(data);
				break;
				case 2:
					cout<<"enter data to insert";
					cin>>data;
					cout<<"enter index to insert";
					cin>>index;
					arr.insert(index,data);
				 break;
				 case 3:
				 	cout<<"enter index for deletion";
					 cin>>index;
					 arr.del(index);
					 break;
					 case 4:
					 cout<<"enter index to edit";
					 cin>>index;
					 cout<<"enter data to edit";
					 cin>>data;
					 arr.edit(index,data);
					 break;
					 case 5:
					 cout<<"enter data to search";
					 cin>>data;
					 index=arr.search(data);
					 if(index==-1)
					 cout<<"search failed";
					 else
					 cout<<"element found at index="<<index;
					 break;
					 case 6:
					 exit(0);
					 default:
					 cout<<"invalid choice";
				}
				
		}
	getch();
		

}
