package module;

import java.util.*;
import java.io.*;

public class assembler_pass1 {
    static int address = 0;
    static int sadd[] = new int[10];
    static int ladd[] = new int[10];

    public static void main(String[] args) throws IOException {
        String IS[] = { "ADD", "SUB", "MUL", "MOVER", "MOVEM" };
        String AD[] = { "START", "END" };
        String DL[] = { "DC", "DS" };
        String RG[] = { "AREG", "BREG", "CREG" };

        int lc = 0, scount = 0, lcount = 0, k = 0, flag = 0, flag2 = 0;
        String temp = null;
        String sv[] = new String[10];
        String lv[] = new String[10];
        String input = null;

        try {
            BufferedReader br = new BufferedReader(new FileReader("src\\module\\input"));
            File f1 = new File("src\\module\\IC");
            File f2 = new File("src\\module\\ST");
            File f3 = new File("src\\module\\LT");

            PrintWriter p1 = new PrintWriter(f1);
            PrintWriter p2 = new PrintWriter(f2);
            PrintWriter p3 = new PrintWriter(f3);

            while ((input = br.readLine()) != null) {
                StringTokenizer st = new StringTokenizer(input, " ");
                while (st.hasMoreTokens()) {
                    temp = st.nextToken();
                    if (temp.matches("\\d*") && temp.length() > 2) {
                        lc = Integer.parseInt(temp);
                        p1.println("C " + lc);
                        address = lc - 1;
                    } else {
                        // CHECK FOR AD
                        for (int i = 0; i < AD.length; i++) {
                            if (temp.equals(AD[i]))
                                p1.print("AD " + (i + 1) + " ");
                        }
                        // CHECK FOR IS
                        for (int i = 0; i < IS.length; i++) {
                            if (temp.equals(IS[i]))
                                p1.print("IS " + (i + 1) + " ");
                        }
                        // CHECK FOR RG
                        for (int i = 0; i < RG.length; i++) {
                            if (temp.equals(RG[i])) {
                                p1.print("RG " + (i + 1) + " ");
                                flag = 1;
                            }
                        }
                        // CHECK FOR DL
                        for (int i = 0; i < DL.length; i++) {
                            if (temp.equals(DL[i]))
                                p1.print("DL " + (i + 1) + " ");
                        }

                        // symbol table
                        if (temp.length() == 1 && !(st.hasMoreTokens()) && flag == 1) {
                            if (Arrays.asList(sv).contains(temp)) {
                                for (int i = 0; i < scount; i++) {
                                    if (sv[i].equals(temp)) {
                                        p1.print("S " + i);
                                        flag2 = 1;
                                    } else
                                        flag2 = 0;
                                }
                            }

                            else {
                                p1.print("S " + scount);
                                sv[scount] = temp;
                                flag2 = 1;
                                scount++;
                            }
                        }

                        if (temp.length() == 1 && (st.hasMoreTokens())) {
                            p1.print(temp + " ");
                            sadd[k] = address;
                            k++;
                        }

                        if (temp.charAt(0) == '=') {
                            p1.print("L " + lcount);
                            lv[lcount] = temp;
                            lcount++;
                        }
                        if (!st.hasMoreTokens())
                            p1.println();

                        if (temp.equals("DS")) {
                            int a = Integer.parseInt(st.nextToken());
                            address += a - 1;
                            p1.println();
                        }

                    }
                }
                address++;
            }
            address--;
            p1.close();

            for (int i = 0; i < lcount; i++) {
                ladd[i] = address - 1;
                address++;
            }
            for (int i = 0; i < scount; i++) {
                p2.println(i + "\t" + sv[i] + "\t" + sadd[i]);
            }
            p2.close();
            for (int i = 0; i < lcount; i++) {
                p3.println(i + "\t" + lv[i] + "\t" + ladd[i]);
            }
            p3.close();
            br.close();
        }

        catch (Exception e) {

        }
    }
}
