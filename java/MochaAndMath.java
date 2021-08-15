import java.io.IOException;
import java.io.InputStreamReader;

public class MochaAndMath {
	static long solve(long[] arr, int n) {
		long ans = arr[0];
		for (int i = 1; i < n; ++i) {
			ans &= arr[i];
		}
		return ans;
	}

	public static void main(String[] args) throws IOException {
		FastReader fr = new FastReader(new InputStreamReader(System.in));
		int cases = fr.nextInt();
		while (cases-- > 0) {
			int n = fr.nextInt();
			long[] arr = new long[n];
			for (int i = 0; i < n; ++i) {
				arr[i] = fr.nextLong();
			}
			System.out.println(solve(arr, n));
		}
	}
}
