import java.io.FileReader;
import java.io.IOException;

public class MochaAndRedBlue {
  static int getScore(char[] s, int i) {
    if (i > 0 && s[i - 1] == s[i]) {
      return 1;
    }
    return 0;
  }

  static int getInt(char c) {
    if (c == 'B') return 0;
    if (c == 'R') return 1;
    return 2;
  }

  static char getChar(int i) {
    if (i == 0) return 'B';
    if (i == 1) return 'R';
    return '?';
  }

  static String solve(String s, int n) {
    int ans = 0;
    return s;
  }

  public static void main(String[] args) throws IOException {
    FastReader fr = new FastReader(new FileReader("in"));
    int cases = fr.nextInt();
    while (cases-- > 0) {
      int n = fr.nextInt();
      String s = fr.next();
      System.out.println(solve(s, n));
    }
  }
}
