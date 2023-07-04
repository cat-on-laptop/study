import java.util.*;
import java.io.*;

public class Solution {
    public static int[] arr;
    public static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; ++i) arr[i] = Integer.parseInt(st.nextToken());

        Arrays.sort(arr);

        System.out.println(arr[n >> 1]);
    }
}