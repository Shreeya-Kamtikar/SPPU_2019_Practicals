import java.util.*;

public class SJF {
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

    void shortestjobfirstalgorithm() {
        int waitingTime[] = new int[pno];
        int turnAroundTime[] = new int[pno];
        int finishtime[] = new int[pno];
        int curr_time = 0;
        int completed = 0;
        int rt[] = bt.clone(); // remaining time

        while (completed != pno) {
            int sj = -1;
            int mintime = Integer.MAX_VALUE;

            for (int i = 0; i < pno; i++) {
                if (at[i] <= curr_time && rt[i] < mintime && rt[i] > 0) {
                    sj = i;
                    mintime = rt[i];
                }
            }

            if (sj == -1)
                curr_time++;
            else {
                rt[sj]--;
                if (rt[sj] == 0) {
                    completed++;
                    finishtime[sj] = curr_time + 1;
                    turnAroundTime[sj] = finishtime[sj] - at[sj];
                    waitingTime[sj] = turnAroundTime[sj] - bt[sj];
                }

                curr_time++;
            }

        }

        float wtsum = 0;
        for (int n : waitingTime)
            wtsum += n;
        float averageWaitingTime = wtsum / pno;

        float tatsum = 0;
        for (int n : turnAroundTime)
            tatsum += n;
        float averageTurnAroundTime = tatsum / pno;

        System.out.println("\n\nSJF Scheduling Algorithm : ");
        System.out.println("ProcessID\t\tBurstTime\t\tArrivalTime\t\tWaitingTime\t\tTurnAroundTime");
        for (int i = 0; i < pno; i++) {
            System.out
                    .println(pid[i] + "\t\t\t" + bt[i] + "\t\t\t" + at[i] + "\t\t\t" + waitingTime[i] + "\t\t\t"
                            + turnAroundTime[i]);
        }

        System.out.println("\nAverage Waiting Time: " + averageWaitingTime);
        System.out.println("Average Turn Around Time: " + averageTurnAroundTime);

    }

    public static void main(String[] args) {
        SJF obj = new SJF();
        obj.getProcessData();
        obj.shortestjobfirstalgorithm();
    }
}
