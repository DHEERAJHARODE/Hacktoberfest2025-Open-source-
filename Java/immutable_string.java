public class immutable_string 
{
    public static void main(String[] args) 
    {
        String str="yash";//immutable(cannot change)
        String str1="yash";//both str and str1 has same value and both has same address or memory
        str.concat(" patel");
        String str2=str.concat(" patel");//by creating new string 
        System.out.println(str);   // by this we can see string value does not change   
        System.out.println(str2); // it is copy by which we can add string value or change i 
        System.out.println(str1);// it is also same address as str both will print same value and because of same address it will execute fast
    }
    
}
