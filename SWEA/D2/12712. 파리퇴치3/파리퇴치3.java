import java.util.*;
import java.io.*;

public class Solution {
    public static int[][] arr;
    public static int n, m;
    public static int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    public static int[][] dir2 = {{-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());

        for(int tc = 1; tc <= T; ++tc) {
            int ans = 0;
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken()); m = Integer.parseInt(st.nextToken());
            arr = new int[n][n];
            for(int i = 0; i < n; ++i) {
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < n; ++j)
                    arr[i][j] = Integer.parseInt(st.nextToken());
            }

            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    int temp = Math.max(cross(i, j), cross2(i, j));
                    ans = Math.max(temp, ans);
                }
            }
            sb.append('#').append(tc).append(' ').append(ans).append('\n');
        }
        System.out.println(sb);
    }
    public static boolean inRange(int row, int col) {
        return 0 <= row && row < n && 0 <= col && col < n;
    }
    public static int cross(int row, int col) {
        int cnt = arr[row][col];
        for(int i = 1; i <= m - 1; ++i) {
            for(int d = 0; d < 4; ++d) {
                int nr = row + i * dir[d][0], nc = col + i * dir[d][1];
                if(inRange(nr, nc)) cnt += arr[nr][nc];
            }
        }
        return cnt;
    }

    public static int cross2(int row, int col) {
        int cnt = arr[row][col];
        for(int i = 1; i <= m - 1; ++i) {
            for(int d = 0; d < 4; ++d) {
                int nr = row + i * dir2[d][0], nc = col + i * dir2[d][1];
                if(inRange(nr, nc)) cnt += arr[nr][nc];
            }
        }
        return cnt;
    }
}