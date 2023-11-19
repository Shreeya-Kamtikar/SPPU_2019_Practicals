import java.util.*;

public class RR {
    int bt[];
    int at[];
    String[] pid;
    int pno; // number of processes
    int q; // quantum time
    float sum;
    Scanner scanner = new Scanner(System.in);

    void getProcessData() {
        System.out.print("Enter the number of processes: ");
        pno = scanner.nextInt();
        bt = new int[pno];
        at = new int[pno];
        pid = new String[pno];
        String st = "P";
        for (int i = 0; i < pno; i++) {
            pid[i] = st.concat(Integer.toString(i + 1));
            System.out.print("Enter the arrival time for " + pid[i] + ": ");
            at[i] = scanner.nextInt();
            System.out.print("Enter the burst time for " + pid[i] + ": ");
            bt[i] = scanner.nextInt();

        }
        System.out.println("Enter the quantum time: ");
        q = scanner.nextInt();
        scanner.close();
    }

    void sortAccordingArrivalTime(int at[], int bt[], String pid[]) {
        boolean swapped;
        int temp;
        String stemp;
        for (int i = 0; i < pno; i++) {
            swapped = false;
            for (int j = 0; j < pno - i - 1; j++) {
                if (at[j] > at[j + 1]) {
                    // swapping arrival time
                    temp = at[j];
                    at[j] = at[j + 1];
                    at[j + 1] = temp;

                    // swapping burst time
                    temp = bt[j];
                    bt[j] = bt[j + 1];
                    bt[j + 1] = temp;

                    // swapping process id
                    stemp = pid[j];
                    pid[j] = pid[j + 1];
                    pid[j + 1] = stemp;

                    // enhanced bubble sort
                    swapped = true;
                }
            }
            if (swapped == false) {
                break;
            }
        }
    }

    void roundrobinalgorithm() {
        int bursttime[] = bt.clone();
        int waitingTime[] = new int[pno];
        int turnAroundTime[] = new int[pno];
        sortAccordingArrivalTime(at, bt, pid);

        // Round robin implement
        do {
            for (int i = 0; i < pno; i++) {
                if (bt[i] > q) 
                {
                    bt[i] -= q;
                    for (int j = 0; j < pno; j++) {
                        if ((j != i) && (bt[j] != 0))
                            waitingTime[j] += q;
                    }
                } 
                else {
                    for (int j = 0; j < pno; j++) {
                        if ((j != i) && (bt[j] != 0))
                            waitingTime[j] += bt[i];
                    }
                    bt[i] = 0;
                }
            }
            sum = 0;
            for (int k = 0; k < pno; k++)
                sum = sum + bt[k];
        } while (sum != 0);

        for (int i = 0; i < pno; i++)
            turnAroundTime[i] = waitingTime[i] + bursttime[i];

        float wtsum = 0;
        for (int n : waitingTime)
            wtsum += n;
        float averageWaitingTime = wtsum / pno;

        float tatsum = 0;
        for (int n : turnAroundTime)
            tatsum += n;
        float averageTurnAroundTime = tatsum / pno;

        System.out.println("\n\nRR Scheduling Algorithm : ");
        System.out.println("ProcessID\t\tBurstTime\t\tArrivalTime\t\tWaitingTime\t\tTurnAroundTime");
        for (int i = 0; i < pno; i++) {
            System.out
                    .println(pid[i] + "\t\t\t" + bursttime[i] + "\t\t\t" + at[i] + "\t\t\t" + waitingTime[i] + "\t\t\t"
                            + turnAroundTime[i]);
        }

        System.out.println("\nAverage Waiting Time: " + averageWaitingTime);
        System.out.println("Average Turn Around Time: " + averageTurnAroundTime);
    }

    public static void main(String[] args) {
        RR obj = new RR();
        obj.getProcessData();
        obj.roundrobinalgorithm();
    }
}
