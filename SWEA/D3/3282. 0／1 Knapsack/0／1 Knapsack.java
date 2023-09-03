import java.io.*;
import java.util.*;

public class Solution{
    static int[][] dp = new int[105][1005]; // dp[n][k] := 1~n번까지 k의 무게로 담았을 때 얻는 최대의 가치
    static int[] v = new int[105], c = new int[105];
    // v[i] := i번째 물건의 부피, c[i] := i번째 물건의 가치
    static int n, k;
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());

        for(int tc = 1; tc <= t; ++tc) {
            st = new StringTokenizer(br.readLine());
            // input
            n = Integer.parseInt(st.nextToken()); k = Integer.parseInt(st.nextToken());
            for(int i = 1; i <= n; ++i) {
                st = new StringTokenizer(br.readLine());
                v[i] = Integer.parseInt(st.nextToken());
                c[i] = Integer.parseInt(st.nextToken());
            }

            // tabulation
            for(int i = 1; i <= n; ++i) {
                for(int j = 0; j <= k; ++j) {
                    // 현재 것을 선택하지 않은 경우와 선택하는 경우
                    dp[i][j] = j >= v[i] ? Math.max(dp[i-1][j], dp[i-1][j-v[i]] + c[i]) : dp[i-1][j];
                }
            }

            sb.append("#").append(tc).append(' ').append(dp[n][k]).append('\n');
        }
        System.out.print(sb);
    }
}