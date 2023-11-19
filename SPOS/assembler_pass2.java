import java.util.*;
import java.io.*;

public class assembler_pass2 {

    public static void main(String args[]) {
        String input = null;
        String temp = null, t1 = null, t2 = null;
        String ss = null, ll = null;
        String pvalue, address;
        try {
            BufferedReader br1 = new BufferedReader(new FileReader("src\\module\\IC.txt"));
            BufferedReader br2 = new BufferedReader(new FileReader("src\\module\\ST.txt"));
            BufferedReader br3 = new BufferedReader(new FileReader("src\\module\\LT.txt"));
            File f = new File("src\\module\\Output.txt");
            PrintWriter p = new PrintWriter(f);

            while ((input = br1.readLine()) != null) {
                StringTokenizer st1 = new StringTokenizer(input, " ");
                while (st1.hasMoreTokens()) {
                    temp = st1.nextToken();
                    if (temp.equals("IS") || temp.equals("DL"))
                        p.print(" ");
                    else if (temp.matches("\\d*") && temp.length() > 0 && st1.hasMoreTokens())
                        p.print(temp + " ");
                    else if (temp.matches("\\d*") && temp.length() > 0 && !(st1.hasMoreTokens()))
                        p.print(temp);
                    else {
                        if (temp.charAt(0) == 'S') {
                            char a;
                            int aa;
                            a = temp.charAt(1);
                            aa = Character.getNumericValue(a);
                            while ((t1 = br2.readLine()) != null) {
                                StringTokenizer st2 = new StringTokenizer(t1, " ");
                                ss = st2.nextToken();
                                int index = Integer.parseInt(ss);
                                if (index == a) {
                                    pvalue = st2.nextToken();
                                    address = st2.nextToken();
                                    p.println(address);
                                }
                            }

                        } else if (temp.charAt(0) == 'L') {
                            char a;
                            int aa;
                            a = temp.charAt(1);
                            aa = Character.getNumericValue(a);
                            while ((t2 = br3.readLine()) != null) {
                                StringTokenizer st3 = new StringTokenizer(t2, " ");
                                ll = st3.nextToken();
                                int index = Integer.parseInt(ll);
                                if (index == a) {
                                    pvalue = st3.nextToken();
                                    address = st3.nextToken();
                                    p.println(address);
                                }
                            }
                        } else {
                            p.print(" ");
                        }
                    }
                }
            }
            p.close();
            br1.close();
            br2.close();
            br3.close();
        }

        catch (Exception e) {
            e.printStackTrace();
        }
    }

}
