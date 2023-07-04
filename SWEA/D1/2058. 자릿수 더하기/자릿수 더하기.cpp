import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine()), tot = 0;
        while(n % 10 != 0) {
            tot += n % 10;
            n /= 10;
        }

        System.out.println(tot);
    }
}