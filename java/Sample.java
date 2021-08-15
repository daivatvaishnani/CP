import java.io.FileReader;
import java.io.IOException;

public class Sample {
  public static void main(String[] args) {
    try (
      FastReader reader = new FastReader(new FileReader("in"))
    ) {
      int numTestCases = reader.nextInt();
      for (int i = 1; i <= numTestCases; ++i) {
        Logger.log("processing test case: %d", i);
        int numElements = reader.nextInt();
        for (int j = 0; j < numElements; ++j) {
          int num = reader.nextInt();
          Logger.log(num);
        }
        String s = reader.nextLine();
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
