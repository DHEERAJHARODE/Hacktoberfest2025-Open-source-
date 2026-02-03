//LONGEST COMMON SUBSEQUENCE LENGTH in Dynamic Programming
import java.util.Scanner;

public class lcs {

  public static void main(String[] args) {
  
    String a="Sonali";
    String b="Ashutosh";
    char[] s1=a.toCharArray();
    char[] s2=b.toCharArray();
    int x=s1.length+1;
    int y=s2.length+1;
    int[][] mat=new int[x+1][y+1];
    for(int i=0;i<x;i++) {
      for(int j=0;j<y;j++) {
        if(i==0 || j==0) {
          mat[i][j]=0;
        }else if(s1[i-1]==s2[j-1]) {
          mat[i][j]=1+mat[i-1][j-1];
        }else {
          mat[i][j]=Math.max(mat[i][j-1],mat[i-1][j]);
        }
        
      }
    }
    System.out.println(mat[x-1][y-1]);
  }
}
