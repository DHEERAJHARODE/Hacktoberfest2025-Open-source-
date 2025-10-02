class MyException extends Exception {// we can create our own custom exceptions............by extending the Exception
                                     // class............
    MyException(String message) {
        super(message);// calling the super class's constructor.....which prints the message of string
                       // type.......which user gives.....
    }
}

public class CustomException {
    public static void main(String[] args) throws Exception {
        System.out.println("Trying to trow custom exception....");
        throw new MyException("Hey this is an custom exception......");
    }
}
