import java.io.FileInputStream;
import java.io.IOException;

public class ChefAndBulbInvention {
  private static long solveSlow(int n, int p, int k) {
    long ans = 0;
    for (int i = 0; i < p % k; ++i) {
      ans += 1 + (n - i) / k;
    }
    ans += (p - p % k) / k;
    if (p % k == 0) {
      ans++;
    }
    return ans;
  }

  private static long solve(int n, int p, int k) {
    long ans = (long) (p % k * (1 + Math.floor((n + 0.0) / k)) - Math.floor(p % k * (p % k + 1.0) / (2F * k)));
    ans += (p - p % k) / k;
    if (p % k == 0) {
      ans++;
    }
    return ans;
  }

  public static void main(String[] args) throws IOException {
    FastReader fastReader = new FastReader(new FileInputStream("in"));
    int cases = fastReader.nextInt();
    while (cases-- > 0) {
      int n = fastReader.nextInt(), p = fastReader.nextInt(), k = fastReader.nextInt();
      System.out.println(n + " " + p + " " + k);
      System.out.println(solveSlow(n, p, k));
      System.out.println(solve(n, p, k));
    }
  }
}
