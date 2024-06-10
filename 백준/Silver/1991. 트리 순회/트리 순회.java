import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static char[] left = new char[28], right = new char[28];
    static int N;
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            char P = st.nextToken().charAt(0), L = st.nextToken().charAt(0), R = st.nextToken().charAt(0);
            P = (char)(P - 'A' + 1);
            L = L == '.' ? (char)0 : (char)(L - 'A' + 1);
            R = R == '.' ? (char)0 : (char)(R - 'A' + 1);
            left[P] = L;
            right[P] = R;
        }

        preOrder(1); sb.append('\n');
        inOrder(1); sb.append('\n');
        postOrder(1);
        System.out.println(sb);
    }

    static void preOrder(int curr) {
        sb.append((char)(curr + 'A' - 1));
        if (left[curr] != 0) preOrder(left[curr]);
        if (right[curr] != 0) preOrder(right[curr]);
    }

    static void inOrder(int curr) {
        if (left[curr] != 0) inOrder(left[curr]);
        sb.append((char)(curr + 'A' - 1));
        if (right[curr] != 0) inOrder(right[curr]);
    }

    static void postOrder(int curr) {
        if (left[curr] != 0) postOrder(left[curr]);
        if (right[curr] != 0) postOrder(right[curr]);
        sb.append((char)(curr + 'A' - 1));
    }
}