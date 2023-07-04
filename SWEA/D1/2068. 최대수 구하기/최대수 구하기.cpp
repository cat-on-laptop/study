import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());

        for(int tc = 1; tc <= T; ++tc) {
            int ans = 0;
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < 10; ++i) {
                int temp = Integer.parseInt(st.nextToken());
                ans = Math.max(ans, temp);
            }
            sb.append('#').append(tc).append(' ').append(ans).append('\n');
        }

        System.out.println(sb);
    }
}