//2011. Final Value of Variable After Performing Operations
class Operations{
        public static int finalValueAfterOperations(String[] operations) {
        int X=0;
        for(int i =0;i<operations.length;i++)
        {
            if(operations[i].equals("++X") || operations[i].equals("X++") )
            {
                X = X + 1;
            }
            else if( operations[i].equals("--X") || operations[i].equals("X--") ) {
                X = X - 1;
            }
            else {
                continue;
            }
        }
        return X;
    }
    public static void main(String[] args)
    {
        //String[] a = {"--X","X++","X++"};
        String[] a = {"++X","++X","X++"};
        System.out.println(finalValueAfterOperations(a));
    }
}