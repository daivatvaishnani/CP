import java.io.IOException;
import java.io.InputStreamReader;

public class MochaAndHiking {
	static int[] solve(int[] arr, int n) {
		int[] path = new int[n + 1];
		if (arr[0] == 1) {
			path[0] = n + 1;
			for (int i = 1; i <= n; ++i) {
				path[i] = i;
			}
			return path;
		}
		if (arr[n - 1] == 0) {
			for (int i = 0; i < n; ++i) {
				path[i] = i + 1;
			}
			path[n] = n + 1;
			return path;
		}
		int div = -1;
		for (int i = 0; i < n - 1; ++i) {
			if (arr[i] == 0 && arr[i + 1] == 1) {
				div = i;
				break;
			}
 		}
		if (div != -1) {
			for (int i = 0; i <= div; ++i) {
				path[i] = i + 1;
			}
			path[div + 1] = n + 1;
			for (int i = div + 2; i <= n; ++i) {
				path[i] = i;
			}
			return path;
		}
		return new int[0];
	}

	public static void main(String[] args) throws IOException {
		FastReader fr = new FastReader(new InputStreamReader(System.in));
		int cases = fr.nextInt();
		while (cases-- > 0) {
			int n = fr.nextInt();
			int[] arr = new int[n];
			for (int i = 0; i < n; ++i) {
				arr[i] = fr.nextInt();
			}
			int[] path = solve(arr, n);
			if (path.length > 0) {
				for (int i : path) {
					System.out.print(i + " ");
				}
				System.out.println();
			} else {
				System.out.println("-1");
			}
		}
	}
}
