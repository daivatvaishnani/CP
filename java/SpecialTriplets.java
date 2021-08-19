import java.io.IOException;
import java.io.InputStreamReader;

public class SpecialTriplets {
  private static long solve(int n) {
    long ans = 0;
    if (n <= 1) {
      return 0;
    }
    for (int c = 1; c <= n; ++c) {
      for (int b = 2 * c; b <= n; b += c) {
        ans += Math.floor((n - c + 0.0) / b) + 1;
      }
    }
    return ans;
  }

  public static void main(String[] args) throws IOException {
    FastReader fastReader = new FastReader(System.in);
    int cases = fastReader.nextInt();
    while (cases-- > 0) {
      int n = fastReader.nextInt();
      System.out.println(solve(n));
    }
  }
}
