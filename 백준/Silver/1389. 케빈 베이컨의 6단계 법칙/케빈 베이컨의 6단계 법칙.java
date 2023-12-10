import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
    static int[] visited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        visited = new int[N + 1];
        int[] rst = new int[N+1];

        for(int i = 0; i <= N; ++i) 
            arr.add(new ArrayList<Integer>());

        for(int i = 0; i < M; ++i) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            arr.get(a).add(b);
            arr.get(b).add(a);
        }

        int min = Integer.MAX_VALUE;
        
        for(int i = 1; i <= N; ++i) {
            rst[i] = bfs(i);
            min = Math.min(min, rst[i]);
        }
        
        for(int i = 1;i<=N;++i)
            if(min == rst[i]) {
                System.out.println(i);
                break;
            }
    }

    static int bfs(int node) {
        for(int i = 1; i <= N; ++i)
            visited[i] = 0;
        visited[node] = 1;
        
        Queue<Integer> q = new LinkedList<>();
        q.add(node);

        while(!q.isEmpty()) {
            int curr = q.poll();
            
            for(int x : arr.get(curr)) {
                if (visited[x] > 0) continue;

                visited[x] = visited[curr] + 1;
                q.add(x);
            }
        }

        int tot = 0;
        for(int i = 1; i <= N; ++i) 
            tot += visited[i] - 1;
        
        return tot;
    }
}

