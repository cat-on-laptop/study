import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;
public class Main {
    static int w, h, answer;
    static int[][] map;
    static boolean[][] visited;
    static int[] dx = { -1, -1, 0, 1, 1, 1, 0, -1 };
    static int[] dy = { 0, 1, 1, 1, 0, -1, -1, -1 };
    private void DFS(int x, int y) {
        for (int i = 0; i < 8; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (nextX < 0 || nextX >= h || nextY < 0 || nextY >= w) continue;
            if (map[nextX][nextY] == 1 && !visited[nextX][nextY]) {
                visited[nextX][nextY] = true;
                DFS(nextX, nextY);
            }
        }
    }
    public static void main(String[] args) throws IOException {
        Main main = new Main();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        while ((w = Integer.parseInt(st.nextToken())) > 0 && (h = Integer.parseInt(st.nextToken())) > 0) {
            map = new int[h][w];
            visited = new boolean[h][w];
            answer = 0;
            for (int i = 0; i < h; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < w; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (map[i][j] == 1 && !visited[i][j]) {
                        answer++;
                        visited[i][j] = true;
                        main.DFS(i, j);
                    }
                }
            }
            System.out.println(answer);
            st = new StringTokenizer(br.readLine());
        }
    }
}