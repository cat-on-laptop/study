import java.util.*;
import java.io.*;

public class 백준 1654{
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int K, N;
	static long[] arr;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// input
		st = new StringTokenizer(br.readLine());
		K = Integer.parseInt(st.nextToken()); N = Integer.parseInt(st.nextToken());
		arr = new long[K];
		for(int i = 0; i < K; ++i) arr[i] = Long.parseLong(br.readLine());
		
		long ans = parametricSearch();
		
		sb.append(String.valueOf(ans)).append('\n');
		System.out.print(sb);
		
	}
	
	static boolean isOk(long l) {
		// l의 길이만큼 랜선들을 자를 때, 문제의 요구조건인 N개를 넘을 수 있는지를 리
		int tot = 0;
		for(int i = 0; i < K; ++i) tot += arr[i] / l;
		
		return tot >= N;
	}
	
	static long parametricSearch() {
		// 랜선의 길이를 매개로 하여 랜선을 자를 때 
		// 가능한 최대의 길이 리턴하는 이분탐
		long l = 0, r = (1 << 31) - 1, ans = -1;
		while (l <= r) {
			long mid = l + ((r - l) >> 1);
			// overflow 방지하기 위한 trick
			if(isOk(mid)) {
				ans = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		return ans;
	}
}
