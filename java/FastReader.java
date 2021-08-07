import java.io.BufferedReader;
import java.io.IOException;
import java.io.Reader;
import java.util.StringTokenizer;

public class FastReader extends BufferedReader {
	StringTokenizer st;

	public FastReader(Reader in, int sz) {
		super(in, sz);
	}

	public FastReader(Reader in) {
		super(in);
	}

	private String next() throws IOException {
		while (st == null || !st.hasMoreElements()) {
			st = new StringTokenizer(readLine());
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	String nextLine() throws IOException {
		return readLine();
	}
}