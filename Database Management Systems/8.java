import java.io.*;
import java.util.*;
import java.sql.*;

public class MainActivity
{
    public static void main(String args[]) throws Exception
    {
   	 //int rno, age;
   	 String c1, c2, c3, c4, c5, c6;
   	 Connection con = null;
   	 Statement st = null;
   	 ResultSet rs = null;
   	 int ch;
   	 boolean flag = true;
   	 Scanner scanner = new Scanner(System.in);
   	 
   	 try
   	 {
   		 Class.forName("com.mysql.jdbc.Driver");
   		 con = DriverManager.getConnection("jdbc:mysql://localhost:3306/student_database","username","password");
   		 
   		 do
   		 {
   			 System.out.println("Enter 1 to CREATE TABLE");
   			 System.out.println("Enter 2 to INSERT into TABLE");
   			 System.out.println("Enter 3 to DELETE from TABLE");
   			 System.out.println("Enter 4 to UPDATE data in TABLE");
   			 System.out.println("Enter 5 to VIEW ALL data from TABLE");
   			 System.out.println("Enter your choice: ");
   			 ch = Integer.parseInt(scanner.nextLine());
   			 
   			 switch(ch)
   			 {
   			 case 1:
   				 System.out.println("Enter name of table to be created: ");
   				 String tname = scanner.nextLine();
   				 System.out.println("Enter first column name: ");
   				 c1 = scanner.nextLine();
   				 System.out.println("Enter second column name: ");
   				 c2 = scanner.nextLine();
   				 System.out.println("Enter third column name: ");
   				 c3 = scanner.nextLine();
   				 
   				 String sql = "CREATE TABLE " + tname + " ( " +c1+ " INTEGER not NULL, " + c2 + " VARCHAR(255), " + c3 + " VARCHAR(255))";
   				 st = con.createStatement();
   				 st.execute(sql);
   				 System.out.println("Table is created\n\n");
   				 break;
   				 
   			 case 2:
   				 System.out.println("Enter table name: ");
   				 String in_tab = scanner.nextLine();
   				 System.out.println("Enter first column value: ");
   				 c4 = scanner.nextLine();
   				 System.out.println("Enter second column value: ");
   				 c5 = scanner.nextLine();
   				 System.out.println("Enter third column value: ");
   				 c6 = scanner.nextLine();
   				 String sql1  = "INSERT INTO " + in_tab + " VALUES(" + c4 + ",' " + c5 + "','" + c6 + "')";
   				 st = con.createStatement();
   				 st.execute(sql1);
   				 System.out.println("Row created\n\n");
   				 break;
   				 
   			 case 3:
   				 System.out.println("Enter ID to be deleted: ");
   				 String id1 = scanner.nextLine();
   				 st = con.createStatement();
   				 int x = st.executeUpdate("DELETE FROM stud WHERE id = " + id1);
   				 System.out.println("Deleted rows are: " + x);
   				 break;
   			 
   			 case 4:
   				 System.out.println("Enter ID to be updated: ");
   				 String id2 = scanner.nextLine();
   				 System.out.println("Enter marks to be updated: ");
   				 String mks = scanner.nextLine();
   				 String sql2 = "UPDATE stud SET MARKS = '" + mks + "' WHERE id = " + id2;
   				 st = con.createStatement();
   				 int u = st.executeUpdate(sql2);
   				 System.out.println("Updated rows are: "+u);
   				 break;
   				 
   			 case 5:
   				 String sql3 = "SELECT * from stud ";
   				 st = con.createStatement();
   				 rs = st.executeQuery(sql3);
   				 boolean rec = rs.next();
   				 while(!rec)
   				 {
   					 System.out.println("No records found");
   				 }
   				 
   				 do
   				 {
   					 c4 = rs.getString(1);
   					 c5 = rs.getString(2);
   					 c6 = rs.getString(3);
   					 System.out.println(c4 + "\t\t");
   					 System.out.println(c5 + "\t\t");
   					 System.out.println(c6 + "\t\t");
   				 } while(rs.next());
   				 break;
   			 
   			
   				 
   			 }
   			 System.out.println("Do you want to continue? (Y/N): ");
   			 String ans = scanner.nextLine();
   			 if(ans.equals("Y") || ans.equals("y"))
   				 flag = true;
   			 if(ans.equals("N") || ans.equals("n"))
   				 flag = false;
   			 
   		 } while(flag);
   	 }
   	 catch(Exception e)
   	 {
   		 System.out.println(e);
   	 }
    }
}





