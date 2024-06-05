import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; ++i) {
            String s = br.readLine();
            int tot = 0, temp = 0;
            for(char x : s.toCharArray()) {
                if (x == 'O') tot += ++temp;
                else temp = 0;
            }
            sb.append(tot).append('\n');
        }
        System.out.print(sb);
    }
}