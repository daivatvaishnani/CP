import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class FastReader {
  BufferedReader br;
  StringTokenizer st;

  FastReader(InputStream in) {
    br = new BufferedReader(new InputStreamReader(in));
  }

  String nextLine() throws IOException {
    return br.readLine();
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