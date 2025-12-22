public class numberPlate {
    public static void main(String[] args) {
        int ch1='A'+(int)(Math.random() *('Z'-'A'));
        int ch2='A'+(int)(Math.random() *('Z'-'A'));
        int ch3='A'+(int)(Math.random() *('Z'-'A'));
    
        int d1=(int)(Math.random() * 10);
        int d2=(int)(Math.random() * 10);
        int d3=(int)(Math.random() * 10);
        int d4=(int)(Math.random() * 10);

        System.out.println(""+(char)ch1+(char)ch2+(char)ch3+d1+d2+d3+d4);
    }
}
