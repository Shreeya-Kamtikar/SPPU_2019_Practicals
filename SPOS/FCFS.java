import java.util.Scanner;

public class FCFS {
    int bt[];
    int at[];
    String[] pid;
    int pno; // number of processes
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

    void firstComeFirstServeAlgorithm() {
        int finishTime[] = new int[pno];
        int waitingTime[] = new int[pno];
        int turnAroundTime[] = new int[pno];
        sortAccordingArrivalTime(at, bt, pid);

        // calculating waiting & turn-around time for each process
        finishTime[0] = at[0] + bt[0];
        turnAroundTime[0] = finishTime[0] - at[0];
        waitingTime[0] = turnAroundTime[0] - bt[0];
        for (int i = 1; i < pno; i++) {
            int nxt_at = at[i];
            int prev_ft = finishTime[i-1];
            if(nxt_at <= prev_ft)
                finishTime[i] = prev_ft + bt[i];
            else
                finishTime[i] = nxt_at + bt[i];

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

        System.out.println("\n\nFCFS Scheduling Algorithm : ");
        System.out.println("ProcessID\t\tBurstTime\t\tArrivalTime\t\tFinishTime\t\tWaitingTime\t\tTurnAroundTime");
        for (int i = 0; i < pno; i++) {
            System.out.println(pid[i] + "\t\t\t" + bt[i] + "\t\t\t" + at[i] + "\t\t\t" + finishTime[i] + "\t\t\t"
                    + waitingTime[i] + "\t\t\t" + turnAroundTime[i]);
        }

        System.out.println("\nAverage Waiting Time: " + averageWaitingTime);
        System.out.println("Average Turn Around Time: " + averageTurnAroundTime);
    }

    public static void main(String[] args) {
        FCFS obj = new FCFS();
        obj.getProcessData();
        obj.firstComeFirstServeAlgorithm();
    }
}