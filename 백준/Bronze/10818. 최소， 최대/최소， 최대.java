import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader((System.in)));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        ArrayList<Integer> arr = new ArrayList<>();
        for(int i = 0; i < n; ++i)
            arr.add(Integer.parseInt(st.nextToken()));

        arr.sort(Comparator.naturalOrder());

        StringBuilder sb = new StringBuilder();
        sb.append(arr.get(0)).append(' ').append(arr.get(n-1));
        System.out.println(sb);
    }
}