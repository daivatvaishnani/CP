import java.util.PriorityQueue;
import java.util.Queue;

public class LearnGenerics {
  static class Sample<T extends Comparable> {
    Queue<T> queue;

    public Sample() {
      queue = new PriorityQueue<T>();
    }
  }
}
