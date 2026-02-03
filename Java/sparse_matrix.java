public class SparseMatrix {

	public static void main(String[] args) {	
		int i, j, total = 0;
		
		int[][] sp_arr = {{0, 0, 0}, {0, 1, 0}, {5, 4, 9}, {3, 0, 0}};
		
		int rows = sp_arr.length;
		int columns = sp_arr[0].length;
			
		for(i = 0; i < rows ; i++) {
			for(j = 0; j < columns; j++){
				if(sp_arr[i][j] == 0) {
					total++;
				}
			}
		}	
		if(total > ((rows * columns)/2)) {
			System.out.println("\nMatrix is a Sparse Matrix");
		}
		else {
			System.out.println("\nMatrix is Not a Sparse Matrix");
		}
	}
}
