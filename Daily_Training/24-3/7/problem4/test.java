/**
 *    author:  HONG-LOU
 *    created: 2022-08-20 21:39:16
**/
import java.io.*;
import java.util.*;

public class Main {
    static class Solve {
        void solve() {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[] s = new int[n + 1];
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                s[i + 1] = s[i] + x;
            }
            for (int i = 0; i < m; i++) {
                int l = sc.nextInt(), r = sc.nextInt();
                out.println(s[r] - s[l - 1]);
            }
        }
    }
    static FastScanner sc = new FastScanner();
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int tt = 1;

        Solve s = new Solve();
        for (int i = 0; i < tt; i++) {
            s.solve();
        }
        out.close();
    }

    static void sort(int[] a) {
        ArrayList<Integer> l = new ArrayList<>();
        for (int i : a) l.add(i);
        Collections.sort(l);
        for (int i = 0; i < a.length; i++) a[i] = l.get(i);
    }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = nextInt();
            return a;
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }
}