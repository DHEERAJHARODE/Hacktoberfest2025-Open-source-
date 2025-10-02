public class Quick {
    static int Findpi(int[] arr, int st, int end) {
        int count = 0;
        int piv = arr[st];
        for (int i = st + 1; i <= end; i++) {// i=1;
            if (piv > arr[i]) {// piv>=arr[st+i];
                count++;
            }
        }
        int pividx = st + count;
        int temp = arr[pividx];
        arr[pividx] = arr[st];
        arr[st] = temp;
        int i = st, j = end;
        while (i < pividx && j > pividx) {
            while (arr[i] < piv)
                i++;
            while (arr[j] >= piv)
                j--;
            if (i < pividx && j > pividx) {
                int tempo = arr[i];
                arr[i] = arr[j];
                arr[j] = tempo;
                i++;
                j--;
            }
        }
        return pividx;
    }

    static void SortQuick(int[] arr, int st, int end) {
        if (st >= end) {
            return;
        }
        int pi = Findpi(arr, st, end);
        SortQuick(arr, st, pi - 1);
        SortQuick(arr, pi + 1, end);
    }

    public static void main(String[] args) {
        int[] arr = { 6, 5, 4, 3, 2, 3, 9, 1, 5, 6, 3, 0, 2, 1 };
        int n = arr.length;
        SortQuick(arr, 0, n - 1);
        for (int i : arr) {
            System.out.print(i + ", ");
        }
    }
}