package java;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.Random;

public class ism215ucs155 {
    private static final String file = "out/outp2";

    public static void main(String[] args) throws Exception {
        Random rand = new Random();
        int customer = 0;
        int timeSinceLastArrival = 0;
        int arrivalTime = 0;
        int serviceTime = 0;
        int timeServiceBegins = 0;
        int serviceEndTimeA = 0;
        int serviceEndTimeB = 0;
        int customerWaitTime = 0;
        boolean usage;

        int serviceTotalA = 0;
        int serviceTotalB = 0;
        int customerWaitTimeTotal = 0;

        try (BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(file))) {
            bufferedWriter.write("-----------------------------------------------\n");
            bufferedWriter.write(String.format("%3s", "A" + " "));
            bufferedWriter.write(String.format("%5s", "C" + " "));
            bufferedWriter.write(String.format("%5s", "D" + " "));
            bufferedWriter.write(String.format("%5s", "F" + " "));
            bufferedWriter.write(String.format("%5s", "G" + " "));
            bufferedWriter.write(String.format("%5s", "H" + " "));
            bufferedWriter.write(String.format("%5s", "I" + " "));
            bufferedWriter.write(String.format("%5s", "J" + " "));
            bufferedWriter.write(String.format("%5s", "I" + " "));
            bufferedWriter.write(String.format("%5s", "L" + " "));
            bufferedWriter.write("\n-----------------------------------------------\n");

            for (customer = 0; customer < 20; customer++) {
                timeSinceLastArrival = rand.nextInt(10) + 1;
                arrivalTime += timeSinceLastArrival;
                if (arrivalTime >= serviceEndTimeA) {
                    serviceTime = rand.nextInt(6) + 1;
                    timeServiceBegins = arrivalTime;
                    serviceEndTimeA = timeServiceBegins + serviceTime;
                    serviceTotalA += serviceTime;
                    usage = true;
                } else if (arrivalTime >= serviceEndTimeB) {
                    serviceTime = rand.nextInt(6) + 1;
                    timeServiceBegins = arrivalTime;
                    serviceEndTimeB = timeServiceBegins + serviceTime;
                    serviceTotalB += serviceTime;
                    usage = false;
                } else if (serviceEndTimeA <= serviceEndTimeB) {
                    serviceTime = rand.nextInt(6) + 1;
                    timeServiceBegins = serviceEndTimeA;
                    customerWaitTime = serviceEndTimeA - arrivalTime;
                    serviceEndTimeA = timeServiceBegins + serviceTime;
                    serviceTotalA += serviceTime;
                    usage = true;
                } else {
                    serviceTime = rand.nextInt(6) + 1;
                    timeServiceBegins = serviceEndTimeB;
                    customerWaitTime = serviceEndTimeB - arrivalTime;
                    serviceEndTimeB = timeServiceBegins + serviceTime;
                    serviceTotalB += serviceTime;
                    usage = false;
                }

                customerWaitTimeTotal += customerWaitTime;

                bufferedWriter.write(String.format("%3s", String.valueOf(customer + 1) + " "));
                bufferedWriter.write(String.format("%5s", String.valueOf(timeSinceLastArrival) + " "));
                bufferedWriter.write(String.format("%5s", String.valueOf(arrivalTime) + " "));
                if (usage) {
                    //Able
                    bufferedWriter.write(String.format("%5s", String.valueOf(timeServiceBegins) + " "));
                    bufferedWriter.write(String.format("%5s", String.valueOf(serviceTime) + " "));
                    bufferedWriter.write(String.format("%5s", String.valueOf(serviceEndTimeA) + " "));

                    //print NULL values for Baker's column here ....
                    bufferedWriter.write(String.format("%5s", "-"));
                    bufferedWriter.write(String.format("%5s", "-"));
                    bufferedWriter.write(String.format("%5s", "-"));
                } else {
                    //print NULL values for Able's column here ....
                    bufferedWriter.write(String.format("%5s", "-"));
                    bufferedWriter.write(String.format("%5s", "-"));
                    bufferedWriter.write(String.format("%5s", "-"));

                    //Baker
                    bufferedWriter.write(String.format("%5s", String.valueOf(timeServiceBegins) + " "));
                    bufferedWriter.write(String.format("%5s", String.valueOf(serviceTime) + " "));
                    bufferedWriter.write(String.format("%5s", String.valueOf(serviceEndTimeB) + " "));
                }

                bufferedWriter.write(String.format("%5s", String.valueOf(customerWaitTime) + " "));

                bufferedWriter.write(String.format("\n"));
            }
            bufferedWriter.write("-----------------------------------------------\n");
            bufferedWriter.write(String.format("%22s", String.valueOf(serviceTotalA)));
            bufferedWriter.write(String.format("%15s", String.valueOf(serviceTotalB)));
            bufferedWriter.write(String.format("%10s", String.valueOf(customerWaitTimeTotal)));
            bufferedWriter.write("\n-----------------------------------------------\n\n");

            bufferedWriter.write(String.format("Over the %d-minute period Able was busy %.2f%% of the time.\n",
                    Math.max(serviceEndTimeA, serviceEndTimeB),
                    (float) serviceTotalA / (serviceTotalA + serviceTotalB) * 100.0));
            bufferedWriter.write(String.format("Baker was busy only %.2f%% of the time.\n",
                    (float) serviceTotalB / (serviceTotalA + serviceTotalB) * 100.0));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}