/*Prob. 1 Implement a solution for the following problem using Greedy method.  
Objective: 
We want to minimize the cost while maximizing throughput. 
 
Problem Details: 
Cost of assigning Virtual Machine (VM) to task: The cost matrix is given (you could use a random matrix or 
a matrix based on the specifics of the cloud system). 
VM capabilities: Each VM has certain available resources (CPU, memory). (Take an input from user) 
Task requirements: Each task needs a certain amount of CPU and memory. (Take an input from user)  */

// D:\VS_CODES\GraphTheory\Lab-12>javac VMTaskAssignment.java
// D:\VS_CODES\GraphTheory\Lab-12>java VMTaskAssignment      
// Enter the no of Virtual Machine : 
// 3
// Enter the no of Tasks : 
// 3
// Enter CPU capacity of VM1: 4
// Enter Memory capacity of VM1: 10
// Enter CPU capacity of VM2: 2
// Enter Memory capacity of VM2: 4
// Enter CPU capacity of VM3: 8
// Enter Memory capacity of VM3: 10
// Enter CPU capacity of Task1: 3
// Enter Memory capacity of Task1: 4
// Enter CPU capacity of Task2: 2
// Enter Memory capacity of Task2: 4
// Enter CPU capacity of Task3: 1
// Enter Memory capacity of Task3: 2
// Enter Cost Matrix (VMs x Tasks):
// Enter costs for VM1:
// 1 2 3
// Enter costs for VM2: 
// 3 1 5
// Enter costs for VM3: 
// 2 2 4

// Task Assignments (Task -> VM):
// Task1 -> VM1
// Task2 -> VM2
// Task3 -> VM1
// Total Cost = 5

import java.util.*;

public class VMTaskAssignment {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the no of Virtual Machine : ");
        int noVMs = sc.nextInt();
        System.out.println("Enter the no of Tasks : ");
        int noTask = sc.nextInt();

        int vmCPU [] = new int[noVMs];
        int vmMem [] = new int[noVMs];

        for(int i=0; i<noVMs; i++){
            System.out.print("Enter CPU capacity of VM" + (i + 1) + ": ");
            vmCPU[i] = sc.nextInt();
            System.out.print("Enter Memory capacity of VM" + (i + 1) + ": ");
            vmMem[i] = sc.nextInt();
        }

        int taskCPU [] = new int[noTask];
        int taskMem [] = new int[noTask];

        for(int i=0; i<noVMs; i++){
            System.out.print("Enter CPU capacity of Task" + (i + 1) + ": ");
            taskCPU[i] = sc.nextInt();
            System.out.print("Enter Memory capacity of Task" + (i + 1) + ": ");
            taskMem[i] = sc.nextInt();
        }

        int costMatrix[][] = new int[noVMs][noTask];
        System.out.println("\nEnter Cost Matrix (VMs x Tasks):");
        for (int i = 0; i < noVMs; i++) {
            System.out.println("Enter costs for VM" + (i + 1) + ": ");
            for (int j = 0; j < noTask; j++) {
                costMatrix[i][j] = sc.nextInt();
            }
        }

        int[] assignment = new int[noTask];
        Arrays.fill(assignment, -1);
        int totalCost = 0;

        for(int i=0; i<noTask; i++){
            int bestVM = -1;
            int minCost = Integer.MAX_VALUE;

            for (int j = 0; j < noVMs; j++) {
               if (vmCPU[j] >= taskCPU[i] && vmMem[j] >= taskMem[i]) {
                    if (costMatrix[j][i] < minCost) {
                        minCost = costMatrix[j][i];
                        bestVM = j;
                    }
                }
            }

            if (bestVM != -1) {
                assignment[i] = bestVM;
                totalCost += minCost;

                // Update VM resources
                vmCPU[bestVM] -= taskCPU[i];
                vmMem[bestVM] -= taskMem[i];
            }
            else {
                System.out.println("Task" + (i + 1) + " could not be assigned (Insufficient resources).");
            }
        }

        // Output results
        System.out.println("\nTask Assignments (Task -> VM):");
        for (int i = 0; i < noTask; i++) {
            if (assignment[i] != -1) {
                System.out.println("Task" + (i + 1) + " -> VM" + (assignment[i] + 1));
            } else {
                System.out.println("Task" + (i + 1) + " -> Not Assigned (Insufficient resources)");
            }
        }

        System.out.println("\nTotal Cost = " + totalCost);

        sc.close();
    }
}