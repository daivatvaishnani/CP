public class Logger {
  static void log(Object message) {
    System.out.println(message);
  }

  static void log(String format, Object... args) {
    String message = String.format(format, args);
    System.out.println(message);
  }
}
