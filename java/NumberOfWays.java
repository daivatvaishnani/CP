import java.io.IOException;
import java.io.InputStreamReader;

public class NumberOfWays {
  public static long solve(long[] arr, int n) {
    long ans = 0;
    long[] sum = new long[n];
    long[] cnt = new long[n];
    sum[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      sum[i] = sum[i + 1] + arr[i];
    }
    if (sum[0] % 3 != 0) return 0;
    cnt[n - 1] = arr[n - 1] == sum[0] / 3 ? 1 : 0;
    for (int i = n - 2; i >= 0; --i) {
      cnt[i] = cnt[i + 1] + (sum[i] == sum[0] / 3 ? 1 : 0);
    }
    for (int i = 0; i < n - 2; ++i) {
      if (sum[0] - sum[i + 1] == sum[0] / 3) {
        ans += cnt[i + 2];
      }
    }
    return ans;
  }

  public static void main(String[] args) throws IOException {
    FastReader fr = new FastReader(System.in);
    int n = fr.nextInt();
    long[] arr = new long[n];
    for (int i = 0; i < n; ++i) {
      arr[i] = fr.nextInt();
    }
    System.out.println(solve(arr, n));
  }
}
