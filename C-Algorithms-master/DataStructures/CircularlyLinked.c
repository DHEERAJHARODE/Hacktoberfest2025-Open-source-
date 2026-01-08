//circular queue using arrays for integer data type
#include<stdio.h>

int q[6],top = -1,end = 6,pos=-1,value;

void push(){
	if((top == 0 && pos == end) || top - 1 == pos)
		printf("Que Overflow\n");
	else{
		pos = pos%end;
		if(top == -1)
			top++;
		printf("Enter the element\n");
		scanf("%d",&value);
		q[++pos] = value;
	}
}

void pop(){
	if(pos == -1)
		printf("Queue Underflow\n");
	else{
		value = q[top];
		printf("Element to be Deleted : %d\n",value);
		if(pos == top)
			top = pos = -1;
	    else
			top++;
	}
}

void Traverse(){
	int i = top;
	if (top == -1)
		{printf("Queue Empty\n");
			return;}
	while(1){
		i = i%end;
		printf("%d  ",q[i] );
		if(i == pos)
			break;
		i++;
	}
	printf("\n");
}

int main(){
	int choice ;
	do{
		printf("Select\n");
		printf("1 : Push \n2 : Pop \n3 : Traverse \n4 : Exit\n");
		printf("Your choice : ");
		scanf("%d",&choice);
		printf("\n");
		switch(choice){
			case 1:push();break;
			case 2:pop();break;
			case 3:Traverse();break;
			case 4:break;
			default:printf("Invalid Input\n");
		}
	}while(choice != 4);
}