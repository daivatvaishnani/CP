import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.Random;

public class ism115ucs155 {
  private static final String file = "out/outp1";

  public static void main(String[] args) throws Exception {
    Random rand = new Random();
    int customer = 0;
    int timeSinceLastArrival = 0;
    int arrivalTime = 0;
    int serviceTime = 0;
    int timeServiceBegins = 0;
    int serviceEndTime = 0;
    int customerWaitTime = 0;
    int customerInSystemTime = 0;
    int idleTimeServer = 0;

    int serviceTotal = 0;
    int customerWaitTimeTotal = 0;
    int customerTimeInSystemTotal = 0;
    int idleServerTimeTotal = 0;

    int waitingCustomers = 0;

    try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(file))) {
      bufferedWriter.write(String.format("%44s", "-------------------------------------------\n"));
      bufferedWriter.write(String.format("%3s", "A" + " "));
      bufferedWriter.write(String.format("%5s", "B" + " "));
      bufferedWriter.write(String.format("%5s", "C" + " "));
      bufferedWriter.write(String.format("%5s", "D" + " "));
      bufferedWriter.write(String.format("%5s", "E" + " "));
      bufferedWriter.write(String.format("%5s", "F" + " "));
      bufferedWriter.write(String.format("%5s", "G" + " "));
      bufferedWriter.write(String.format("%5s", "H" + " "));
      bufferedWriter.write(String.format("%5s", "I" + " "));
      bufferedWriter.write(String.format("%44s", "\n-------------------------------------------\n"));

      for (customer = 0; customer < 20; customer++) {
        timeSinceLastArrival = rand.nextInt(10) + 1;
        arrivalTime += timeSinceLastArrival;
        serviceTime = rand.nextInt(10) + 1;
        timeServiceBegins = (arrivalTime > serviceEndTime) ? arrivalTime : serviceEndTime;
        customerWaitTime = (arrivalTime > serviceEndTime) ? 0 : serviceEndTime - arrivalTime;
        customerInSystemTime = serviceTime + customerWaitTime;
        idleTimeServer = (arrivalTime > serviceEndTime) ? (arrivalTime - serviceEndTime) : 0;

        serviceEndTime = timeServiceBegins + serviceTime;

        serviceTotal += serviceTime;
        customerWaitTimeTotal += customerWaitTime;
        customerTimeInSystemTotal += customerInSystemTime;
        idleServerTimeTotal += idleTimeServer;

        waitingCustomers = (customerWaitTime > 0) ? waitingCustomers : ++waitingCustomers;

        bufferedWriter.write(String.format("%3s", String.valueOf(customer + 1) + " "));
        bufferedWriter.write(String.format("%5s", String.valueOf(timeSinceLastArrival) + " "));
        bufferedWriter.write(String.format("%5s", String.valueOf(arrivalTime) + " "));
        bufferedWriter.write(String.format("%5s", String.valueOf(serviceTime) + " "));
        bufferedWriter.write(String.format("%5s", String.valueOf(timeServiceBegins) + " "));
        bufferedWriter.write(String.format("%5s", String.valueOf(customerWaitTime) + " "));
        bufferedWriter.write(String.format("%5s", String.valueOf(serviceEndTime) + " "));
        bufferedWriter.write(String.format("%5s", String.valueOf(customerInSystemTime) + " "));
        bufferedWriter.write(String.format("%5s", String.valueOf(idleTimeServer) + " "));
        bufferedWriter.write("\n");
      }
      bufferedWriter.write(String.format("%44s", "-------------------------------------------\n"));
      bufferedWriter.write(String.format("%18s", String.valueOf(serviceTotal) + " "));
      bufferedWriter.write(String.format("%10s", String.valueOf(customerWaitTimeTotal) + " "));
      bufferedWriter.write(String.format("%10s", String.valueOf(customerTimeInSystemTotal) + " "));
      bufferedWriter.write(String.format("%5s", String.valueOf(idleServerTimeTotal) + " "));
      bufferedWriter.write("\n");
      bufferedWriter.write(String.format("%44s", "-------------------------------------------\n\n"));

      bufferedWriter.write("Conclusions Of Simulation:\n\n");
      bufferedWriter.write("Average Waiting Time: " + String.valueOf((float) customerWaitTimeTotal / customer) + "(min)" + "\n");
      bufferedWriter.write("Probability(wait): " + String.valueOf((float) waitingCustomers / customer) + "\n");
      bufferedWriter.write("Probability of idle server: " + String.valueOf((float) idleServerTimeTotal / serviceEndTime) + "\n");
      bufferedWriter.write("Probability of server being busy: " + String.valueOf((float) 1 - (idleServerTimeTotal / serviceEndTime)) + "\n");
      bufferedWriter.write("Average Service Time: " + String.valueOf((float) serviceTotal / customer) + "(min)" + "\n");
      bufferedWriter.write("Average Time between arrivals: " + String.valueOf((float) arrivalTime / (customer - 1)) + "(min)" + "\n");
      bufferedWriter.write("Average waiting time of those who wait: " + String.valueOf((float) customerWaitTimeTotal / waitingCustomers) + "(min)" + "\n");
      bufferedWriter.write("Average time a customer spends in the system: " + String.valueOf((float) customerTimeInSystemTotal / customer) + "(min)" + "\n");

    } catch (Exception e) {
      e.printStackTrace();
    }
  }

}
