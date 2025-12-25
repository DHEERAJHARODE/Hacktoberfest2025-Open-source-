#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int heap_size;

void max_heapify(int heap[],int i){
	
	int left = 2*i;
	int right = 2*i + 1;
	int largest = i;
	
	if(left <= heap_size && heap[left] > heap[largest])
		largest = left;
	
	if(right <= heap_size && heap[right] > heap[largest])
		largest = right;
		
	if(largest!=i){
		
		swap(heap[largest],heap[i]);
		
		max_heapify(heap,largest);
	}
	
	
		
	
}

void build_max_heap(int heap[]){
	
	for(int i=(heap_size/2);i>=1;i--)
		max_heapify(heap,i);
}
void print(int heap[],int heap_size){
	
	for(int i=1;i<=(heap_size/2);i++){
		
		if(2*i <= heap_size)
			cout<<"Left child of "<<heap[i]<<" is "<<heap[2*i]<<endl;
		if(2*i +1 <= heap_size)
			cout<<"Right child of "<<heap[i]<<" is "<<heap[2*i + 1]<<endl;
		
		cout << endl;
	}
	
	cout<<"Root of tree is "<<heap[1]<<" with no parent of course"<<endl;
		
	
	
	cout<<"Leaves of this heaps are :- "<<endl;
	
	for(int i=((heap_size/2)+1);i<=heap_size;i++){
		
		cout<<heap[i]<<"	";
	}
}

void heap_sort(int heap[]){
	
	
	build_max_heap(heap);
	
	for(int i=heap_size;i>=2;i--){
		
		swap(heap[1],heap[i]);
		max_heapify(heap,1);
		
	}
}
int main(){
	
	cout<<"Enter your heap size"<<endl;
	cin>>heap_size;
	int heap[heap_size];
	
	for(int i=1;i<=heap_size;i++){
		
		cout<<"Enter the "<<i<<"th element of th heap"<<endl;
		cin>>heap[i];
		
	}
  
	
	cout<<endl;
	
	heap_sort(heap);
	
	print(heap,heap_size);
	
}
