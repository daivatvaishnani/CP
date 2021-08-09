import java.io.BufferedReader;
import java.io.IOException;
import java.io.Reader;
import java.util.StringTokenizer;

class FastReader extends BufferedReader {
	StringTokenizer st;

	FastReader(Reader in, int sz) {
		super(in, sz);
	}

	FastReader(Reader in) {
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