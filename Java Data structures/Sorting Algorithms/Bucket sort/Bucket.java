import java.util.ArrayList;
import java.util.Collections;

public class Bucket {
    static void BucketSort(float[] arr) {
        int n = arr.length;
        ArrayList<Float>[] Bigbucket = new ArrayList[n];
        for (int i = 0; i < n; i++) {// for creating small buckets.................
            Bigbucket[i] = new ArrayList<Float>();
        }
        for (int i = 0; i < n; i++) {// To add elements...........
            int BucketIdx = (int) arr[i] * 10;
            Bigbucket[BucketIdx].add(arr[i]);
        }
        for (int i = 0; i < n; i++) {// to sort list individually..............
            Collections.sort(Bigbucket[i]);
        }
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < Bigbucket[i].size(); j++) {
                arr[idx] = Bigbucket[i].get(j);
                idx++;
            }
        }
    }

    public static void main(String[] args) {
        float[] arr = { 0.3f, 0.1f, 0.6f, 0.8f, 0.5f, 0.1f, 0.5f, 0.7f };
        BucketSort(arr);
        for (Float i : arr)
            System.out.println(i);
    }
}