import java.util.*;
import javax.swing.JOptionPane;
import java.util.Scanner;
public class Practice4 {
  public static void main(String args[]) {
  String menuData = "Calculator\n";
						menuData  += "1. Addition\n" ;
						menuData += "2. Substraction\n";
						menuData += "3. Multiplication\n";
						menuData += "4. Division\n";
						menuData += "5. Modulus \n";
						menuData += "6. Exit \n";
						while(true){
					
						int choice = Integer.parseInt(JOptionPane.showInputDialog(menuData));
						switch(choice){
							case 1 : 
							int num1 = Integer.parseInt(JOptionPane.showInputDialog("Enter First Decimal Number : "));	
							int num2 = Integer.parseInt(JOptionPane.showInputDialog("Enter Second Decimal Number : "));
							int result = num1 + num2 ;
							JOptionPane.showMessageDialog(null,result);
							break;
							
							case 2 : 
							num1 = Integer.parseInt(JOptionPane.showInputDialog("Enter First Decimal Number : "));	
							num2 = Integer.parseInt(JOptionPane.showInputDialog("Enter Second Decimal Number : "));
							result = num1 - num2 ;
							JOptionPane.showMessageDialog(null,result);
							break;
							
							case 3 : 
							num1 = Integer.parseInt(JOptionPane.showInputDialog("Enter First Decimal Number : "));	
							num2 = Integer.parseInt(JOptionPane.showInputDialog("Enter Second Decimal Number : "));
							result = num1 * num2 ;
							JOptionPane.showMessageDialog(null,result);
							break;
							
							case 4 : 
							num1 = Integer.parseInt(JOptionPane.showInputDialog("Enter First Decimal Number : "));	
							num2 = Integer.parseInt(JOptionPane.showInputDialog("Enter Second Decimal Number : "));
							result = num1 / num2 ;
							JOptionPane.showMessageDialog(null,result);
							break;
							
							case 5 : 
							num1 = Integer.parseInt(JOptionPane.showInputDialog("Enter First Decimal Number : "));	
							num2 = Integer.parseInt(JOptionPane.showInputDialog("Enter Second Decimal Number : "));
							result = num1 % num2 ;
							JOptionPane.showMessageDialog(null,result);
							break;
						
					}if (choice==6) System.exit(0);
				}
