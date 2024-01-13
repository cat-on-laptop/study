import java.io.*;

public class Main{
	static int t;
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		t = Integer.parseInt(br.readLine());
		for(int tc = 0; tc < t; ++tc) {
			long n = Long.parseLong(br.readLine());
			if(n == 0 || n == 1) {
				sb.append("2\n");
				continue;
			}
			solution(n);
			
		}
		System.out.print(sb);
	}
	static void solution(long x) {
		if (isPrime(x)) {
			sb.append(String.valueOf(x)).append('\n');
			return;
		}
		solution(x + 1);
	}
	
	static boolean isPrime(long x) {
//		for(long i = 2; i * i <= x; ++i) {
//			if(x % i == 0) return false;
//		}
//		return true;
		int cnt = 0;
		for(long i = 2; i * i <= x; ++i) {
			if(x % i == 0) ++cnt;
			if(cnt > 0) break;
		}
		return cnt < 1;
	}
}