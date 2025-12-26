public class MaxNoOfWords {
    public static void main(String[] args) {
        String[] sentences = {"alice and bob love leetcode","i think so too","this is great thanks very much"};
        int l=0;
        for(int i=0;i<sentences.length;i++)
        {
           int temp = countWords(sentences[i]);
           if(l<temp)
           {
               l=temp;
           }
        }
        System.out.println(l);
    }
    public static int countWords(String s)
    {
        int c=0;
        char[] a = s.toCharArray();
        for(int i=0;i<a.length;i++)
        {
            if(a[i] == ' ')
            {
                c++;
            }
        }
        return (c+1);
    }
}
