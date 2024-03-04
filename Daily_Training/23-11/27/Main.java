/**
 *    author:  HONG-LOU
 *    created: 2022-09-08 06:27:48
**/
import java.io.*; import java.util.*;

public class Main {

  static class Solver {

    static HashMap<Long, Long> m = new HashMap<>();

    static int mod = (int)1e9 + 7;
    
    public void solve() {
      long a = readl(), b = readl();
      Solution sol = new Solution();
      print(sol.fib(a) + "\n" + sol.fib(b) + "\n");
      print(a == 0 ? 0 : work(a - 1) + "\n");
      print(b == 0 ? 0 : work(b - 1));
    }

    public Long work(Long x) {
      if(x == 1 || x == 0) return (long)1;
      if(m.get(x) != null) return m.get(x);
      long res = 0, t= x / 2;
      if(x % 2 == 1) res = work(t) * (work(t - 1) + work(t + 1)) % mod;
      else res = work(t) * work(t) % mod + work(t - 1) * work(t - 1) % mod;
      m.put(x, res % mod);
      return res % mod;
    }
  }

  public static void main(String[] args) {
    Solver s = new Solver(); s.solve(); gg.close();
  }

  static FastScanner in = new FastScanner();
  static PrintWriter gg = new PrintWriter(System.out);

  static void sort(int[] a) {
    ArrayList<Integer> l = new ArrayList<>();
    for (int i : a) l.add(i); Collections.sort(l);
    for (int i = 0; i < a.length; i++) a[i] = l.get(i);
  }

  static int read() { return Integer.parseInt(in.next()); }
  static long readl() { return Long.parseLong(in.next()); }
  static String reads() { return in.next(); }
  static long max(long a, long b) { return a > b ? a : b; }
  static long min(long a, long b) { return a > b ? b : a; }
  static long abs(long x) { return x > 0 ? x : -x; }
  static long gcd(long a, long b) { return b > 0 ? gcd(b, a % b) : a; }
  static void print(Object x) { gg.print(x); }
  static void println(Object x) { gg.println(x); }
  static void printf(String s, Object... args) { gg.printf(s, args); }
  static int [] read(int n) { return in.readArray(n); }

  static class FastScanner {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(""); String next() {
      while (!st.hasMoreTokens()) try {
          st = new StringTokenizer(br.readLine());
        } catch (IOException e) {
          e.printStackTrace();
        }
      return st.nextToken();
    }
    int[] readArray(int n) {
      int [] a = new int[n]; for (int i = 0; i < n; i++) a[i] = read(); return a;
    }
  }
}

class Solution {
  static int mod = (int)1e9 + 7;
  public Long fib(Long n) {
    double sqrt5 = Math.sqrt(5);
    double fibN = Math.pow((1 + sqrt5) / 2, n) - Math.pow((1 - sqrt5) / 2, n);
    return (Long) Math.round(fibN / sqrt5) % mod;
  }
}
