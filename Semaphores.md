Semaphore is one of the simplest and prominent techniques to manage and avoid deadlocks.
Semaphore is a simple integer variable shared between processes/threads to avoid deadlocks or to manage concurrent processes.
This variable is used to solve the critical section problem and to achieve process synchronization.

This is the operation of semaphores:


//Code section
P(Semaphore s){
  while(s==0);
  s=s-1;
}
V(Semaphore s){
  s=s+1;
}

//Code Section ends

P is called wait or sleep operation. V is called signal/ wake-up operation.


Process P1
//Some code or instruction
P(s);
  //Critical Setion
V(s);
  //Remainder Section
  

If there are 2 process P1 and P2 and a semaphore variable is initialised to value 1. 
Assume that P1 calls P, enters in its critical section, semaphore value becomes 0.
Now P2 cannot enter critical section. It'll wait until s>0
s can be greater than 0 only when P1 finishes its critical section and calls V operation.


//For detailed article visit: https://www.geeksforgeeks.org/semaphores-in-process-synchronization/
