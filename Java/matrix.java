public class matrix {
    public static void main(String[] args) {
        int i, j;
        int[][] m = new int[6][6];
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 6; j++) {
                m[i][j] = (int) ((Math.random() * 5) % 2);

            }
        }
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 6; j++) {
                System.out.print(m[i][j] + " ");
            }
            System.out.println();
        }

        System.out.println("rows having odd nos of 1s");
        int c = 0;
        for (i = 0; i < 6; i++) {
            c = 0;
            for (j = 0; j < 6; j++) {
                if (m[i][j] == 1) {
                    c++;
                }
            }
            if (c % 2 != 0) {
                System.out.println("Row " + (i + 1) + " have ODD no of 1s");
            }   
        }
       

        System.out.println("columns having odd nos of 1s");

        for (i = 0; i < 6; i++) {
            c = 0;
            for (j = 0; j < 6; j++) {
                if (m[j][i] == 1) {
                    c++;
                }
            }
            if (c % 2 != 0) {
                System.out.println("Column " + (i + 1) + " have ODD no of 1s");
            }
        
        }
        
    }
}
