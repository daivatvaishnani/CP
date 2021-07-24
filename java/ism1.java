import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.Random;

public class ism1 {
    private static final String file = "outp";

    public static void main(String[] args) throws Exception {
        Random rand = new Random();
        int customerNo = 0, ctimeSLA = 0, caTime = 0, csTime = 0, ctimeSB = 0, cserviceET = 0, ccustomerWT = 0, customerIST = 0, cidleTS = 0;

        int cserviceT = 0, ccustomerWTT = 0, ccustomerTIST = 0, cidleSTT = 0, cwaitingC = 0;

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

            for (customerNo = 0; customerNo < 20; customerNo++) {
                timeSLA = rand.nextInt(10) + 1;
                aTime += timeSLA;
                sTime = rand.nextInt(10) + 1;
                timeSB = (aTime > serviceET) ? aTime : serviceET;
                customerWT = (aTime > serviceET) ? 0 : serviceET - aTime;
                customerIST = sTime + customerWT;
                idleTS = (aTime > serviceET) ? (aTime - serviceET) : 0;

                serviceET = timeSB + sTime;

                serviceT += sTime;
                customerWTT += customerWT;
                customerTIST += customerIST;
                idleSTT += idleTS;

                waitingC = (customerWT > 0) ? waitingC : ++waitingC;

                bufferedWriter.write(String.format("%3s", String.valueOf(customerNo + 1) + " "));
                bufferedWriter.write(String.format("%5s", String.valueOf(timeSLA) + " "));
                bufferedWriter.write(String.format("%5s", String.valueOf(aTime) + " "));
                bufferedWriter.write(String.format("%5s", String.valueOf(sTime) + " "));
                bufferedWriter.write(String.format("%5s", String.valueOf(timeSB) + " "));
                bufferedWriter.write(String.format("%5s", String.valueOf(customerWT) + " "));
                bufferedWriter.write(String.format("%5s", String.valueOf(serviceET) + " "));
                bufferedWriter.write(String.format("%5s", String.valueOf(customerIST) + " "));
                bufferedWriter.write(String.format("%5s", String.valueOf(idleTS) + " "));
                bufferedWriter.write("\n");
            }
            bufferedWriter.write(String.format("%44s", "-------------------------------------------\n"));
            bufferedWriter.write(String.format("%18s", String.valueOf(serviceT) + " "));
            bufferedWriter.write(String.format("%10s", String.valueOf(customerWTT) + " "));
            bufferedWriter.write(String.format("%10s", String.valueOf(customerTIST) + " "));
            bufferedWriter.write(String.format("%5s", String.valueOf(idleSTT) + " "));
            bufferedWriter.write("\n");
            bufferedWriter.write(String.format("%44s", "-------------------------------------------\n\n"));

            bufferedWriter.write("Average Waiting Time: " + String.valueOf((float) customerWTT / customerNo) + "(min)" + "\n");
            bufferedWriter.write("Probability(wait): " + String.valueOf((float) waitingC / customerNo) + "\n");
            bufferedWriter.write("Probability of idle server: " + String.valueOf((float) idleSTT / serviceET) + "\n");
            bufferedWriter.write("Probability of server being busy: " + String.valueOf((float) 1 - (idleSTT / serviceET)) + "\n");
            bufferedWriter.write("Average Service Time: " + String.valueOf((float) serviceT / customerNo) + "(min)" + "\n");
            bufferedWriter.write("Average Time between arrivals: " + String.valueOf((float) aTime / (customerNo - 1)) + "(min)" + "\n");
            bufferedWriter.write("Average waiting time of those who wait: " + String.valueOf((float) customerWTT / waitingC) + "(min)" + "\n");
            bufferedWriter.write("Average time a customer spends in the system: " + String.valueOf((float) customerTIST / customerNo) + "(min)" + "\n");

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
