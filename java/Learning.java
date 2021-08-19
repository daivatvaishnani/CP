interface TopicA {
  void read();
}

interface TopicB {
  void read();
}

public class Learning implements TopicA, TopicB {
  @Override
  public void read() {

  }
}
