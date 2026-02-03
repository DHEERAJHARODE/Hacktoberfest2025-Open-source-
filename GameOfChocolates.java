//problem
/*Bunty and Dolly are playing a game, described as follows.
Game Description: -
There are two boxes having A and B number of chocolates respectively. Both can eat L (L ≥ 1) chocolates from any one box or L chocolates from both the boxes in one move. They play the game alternatively and the last one to eat the chocolate will be the winner.
As Bunty wants to impress Dolly, he wants to make Dolly the winner. You have to help Bunty in deciding who should play first. Assume that both the players play optimally.*/

class GameOfChocolates{
    boolean game(int A, int B){
        // Code Here
        int diff=Math.abs(A-B);
        double gr=(1+Math.sqrt(5))/2;
        double ans=diff*gr;
        return Math.min(A,B)!=(int)ans;
    }
    
}

/*explanation
This problem is based on Wythoff's array algo.

There is formula for the finding golden ratio, i.e.  	φ =(1+√5)/2. 

Later this golder ratio will be multiply with absulute difference between 2 inputs.

If result of that should not be same as minimum number of input for winning.*/
