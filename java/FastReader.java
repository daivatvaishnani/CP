import java.io.BufferedReader;
import java.io.IOException;
import java.io.Reader;
import java.util.StringTokenizer;

class FastReader extends BufferedReader {
	StringTokenizer st;

	FastReader(Reader in) {
		super(in);
	}

	String nextLine() throws IOException {
		return readLine();
	}

	String next() throws IOException {
		while (st == null || !st.hasMoreElements()) {
			st = new StringTokenizer(nextLine());
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
}