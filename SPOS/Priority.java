import java.util.*;

public class Priority {
    int bt[];
    int at[];
    String[] pid;
    int prt[]; // priority
    int pno; // number of processes
    Scanner scanner = new Scanner(System.in);

    void getProcessData() {
        System.out.print("Enter the number of processes: ");
        pno = scanner.nextInt();
        bt = new int[pno];
        at = new int[pno];
        prt = new int[pno];
        pid = new String[pno];
        String st = "P";
        for (int i = 0; i < pno; i++) {
            pid[i] = st.concat(Integer.toString(i + 1));
            System.out.print("Enter the burst time for " + pid[i] + ": ");
            bt[i] = scanner.nextInt();
            System.out.print("Enter the arrival time for " + pid[i] + ": ");
            at[i] = scanner.nextInt();
            System.out.print("Enter the priority for " + pid[i] + ": ");
            prt[i] = scanner.nextInt();
        }
        scanner.close();
    }

    void sortAccordingArrivalTimeandPriority(int at[], int bt[], int prt[], String pid[]) {
        int temp;
        String stemp;
        for (int i = 0; i < pno; i++) {
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

                    // swapping priority
                    temp = prt[j];
                    prt[j] = prt[j + 1];
                    prt[j + 1] = temp;
                }
                // sorting according to priority when arrival timings are same
                if (at[j] == at[j + 1]) {
                    if (prt[j] > prt[j + 1]) {
                        // swapping arrival time
                        temp = at[j];
                        at[j] = at[j + 1];
                        at[j + 1] = temp;

                        // swapping burst time
                        temp = bt[j];
                        bt[j] = bt[j + 1];
                        bt[j + 1] = temp;

                        // swapping priority
                        temp = prt[j];
                        prt[j] = prt[j + 1];
                        prt[j + 1] = temp;

                        // swapping process identity
                        stemp = pid[j];
                        pid[j] = pid[j + 1];
                        pid[j + 1] = stemp;

                    }
                }
            }
        }
    }

    void priorityNonPreemptiveAlgorithm() {
        int finishTime[] = new int[pno];
        int waitingTime[] = new int[pno];
        int turnAroundTime[] = new int[pno];
        sortAccordingArrivalTimeandPriority(at, bt, prt, pid);

        finishTime[0] = at[0] + bt[0];
        turnAroundTime[0] = finishTime[0] - at[0];
        waitingTime[0] = turnAroundTime[0] - bt[0];

        for (int i = 1; i < pno; i++) {
            finishTime[i] = bt[i] + finishTime[i - 1];
            turnAroundTime[i] = finishTime[i] - at[i];
            waitingTime[i] = turnAroundTime[i] - bt[i];
        }

        float wtsum = 0;
        for (int n : waitingTime)
            wtsum += n;
        float averageWaitingTime = wtsum / pno;

        float tatsum = 0;
        for (int n : turnAroundTime)
            tatsum += n;
        float averageTurnAroundTime = tatsum / pno;

        System.out.println("\n\nPriority(Non-Preemptive) Scheduling Algorithm : ");
        System.out.println("ProcessID\t\tBurstTime\t\tArrivalTime\t\tFinishTime\t\tWaitingTime\t\tTurnAroundTime");
        for (int i = 0; i < pno; i++) {
            System.out.println(pid[i] + "\t\t\t" + bt[i] + "\t\t\t" + at[i] + "\t\t\t" + finishTime[i] + "\t\t\t"
                    + waitingTime[i] + "\t\t\t" + turnAroundTime[i]);
        }

        System.out.println("\nAverage Waiting Time: " + averageWaitingTime);
        System.out.println("Average Turn Around Time: " + averageTurnAroundTime);

    }

    public static void main(String[] args) {
        Priority obj = new Priority();
        obj.getProcessData();
        obj.priorityNonPreemptiveAlgorithm();
    }
}
