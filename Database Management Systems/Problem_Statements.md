### Statement 2A: Design and Develop SQL DDL statements which demonstrate the use of SQL objects such as Table, View, Index, Sequence, Synonym
    1. Create table Customers with schema (cust_id, cust_name, product, quantity, total_price)
    2. Use sequence/ auto-increment for incrementing customer ID and Insert 5 customer records to the table Customers
    3. Alter the table Customers by adding one column ‘price_per_qnty’
    4. Create view ‘Cust_View’ on Customers displaying customer ID, customer name
    5. Update the view ‘Cust_View’ to display customer ID, product, total price
    6. Drop the view ‘Cust_View’
    7. Create index ‘Cust_index’ on customer name
    8. Drop index ‘Cust_index’
    9. Use sequence/ auto-increment for incrementing customer ID
    10. Use the name alias for table Customers (rename the table in query)
    11. Drop the table Customers

### Statement 2B: Design at least 10 SQL queries for suitable database application using SQL DML statements:Insert, Select, Update, Delete with operators, functions, and set operators.
    1. Create table Student with schema (roll_no, name, division, branch, city, marks)
    2. Insert 10 records to the table students
    3. List all the student names with their corresponding city
    4. List all the distinct names of the students
    5. List all the records of the students with all the attributes
    6. List all the students whose marks are greater than 75
    7. List all the students whose name starts with the alphabet ‘S’
    8. List all the students whose marks are in the range of 50 to 60
    9. List all the students whose branch is ‘computer’ and city is ‘Pune’
    10. Update the branch of a student to ‘IT’ whose roll number is 9
    11. Delete the student records whose division is ‘BE’
    12. Create another table TE_Students with Schema( roll_no, name)
    13. List all the roll numbers unionly in the relations Student and TE_Students
    14. Display name of all the students belonging to relation Student in Upper case
    15. Display the binary and hex equivalent of marks for all the students belonging to Student relation
   
### Statement 3: Design at least 10 SQL queries for suitable database application using SQL DML statements:all types of Join, SubQuery and View.
    1. Create table Customers with schema (ID, name, age, address, salary)
    2. Create table Orders with Schema(O_ID, o_date, customer_id, amount)
    3. Insert 5 records to each table keeping few customer ids common to both the tables
    4. Perform the inner join on customers and orders table to enlist the id, name, amount and o_date
    5. Perform the left outer join on customers and orders table to enlist the id, name, amount and o_date
    6. Perform the right outer join on customers and orders table to enlist the id, name, amount and o_date
    7. Perform the full outer join on customers and orders table to enlist the id, name, amount and o_date by using ‘union all’ set operation
    8. Perform the self join on customers table to enlist the pair of customers belonging to same address
    9. Perform the Cross/ Cartesian join on customers and orders table to enlist the id, name, amount and o_date
    10. Design the sub query with select statement for displaying all the details of the customers having salary greater than 20000
    11. Create a backup table- ‘cust_bkp’ of the table customers by using insert statement with the subquery
    12. Update the salaries by 10% of all the customers(in customers table) having age greater than or equals to 24 by using sub query with update clause( by using backup table cust_bkp)
    13. Delete all the customers having age greater than 26 by using delete clause with the subquery

### Statement 4: To study unnamed PL/ SQL code blocks by using Control structure and Exception handling.
Write a PL/ SQL block of code for the following requirements:-
- Schema:
     1. Borrower(Rollin, Name, DateofIssue, NameofBook, Status)
     2. Fine(Roll_no,Date,Amt)
- Accept roll_no & name of book from user.
- Check the number of days (from date of issue), if days are between 15 to 30 then fine amount will be Rs 5 per day. If no. of days>30, per day fine will be Rs 50 per day & for days less than 30, Rs. 5 per day. After submitting the book, status will change from I to R. If the condition of fine is true, then details will be stored into a fine table

### Statement 5: To study Cursors: (All types: Implicit, Explicit, Cursor FOR Loop, Parameterized Cursor)
Write a PL/SQL block of code using parameterized Cursor, that will merge the data available in the newly created table N_RollCall with the data available in the table O_Roll-call. If the data in the first table already exists in the second table then that data should be skipped.

### Statement 6 : PL/SQL Stored Procedure and Stored Function
Write a Stored Procedure namely proc_Grade for the categorization of students. If marks scored by students in examination is <=1500 and marks>=990 then students will be placed in distinction category if marks scored are between 989 and900 category is first class, if marks 899 and 825 category is Higher Second Class. Write a PL/SQL block for using procedures created with the above requirement. Stud_Marks(name, total_marks) Result(Roll,Name, Class)

### Statement 7 : To study Database Trigger (All Types: Row level and Statement level triggers, Before and After Triggers).
Write a database trigger on Library table. The System should keep track of the records that are being updated or deleted. The old value of updated or deleted records should be added in Library Audit table.

### Statement 8 : Implement MYSQL database connectivity with Java.Implement Database navigation operations (add, delete, edit,) using JDBC.

### Statement 9 : Design and Develop MongoDB Queries using CRUD operations. 
    1. Create Collection Employee
    2. Insert 5 documents to Employee
    3. Read all the documents
    4. Display all the documents in a formatted manner
    5. Insert another 3 documents with a single insert command
    6. Insert one document using save() method instead of insert() method
    7. Read all the employees whose name is ‘Joe’ and age is 25
    8. Read all the employees whose salary is greater than 5000
    9. Update the department of employee ‘Joe’ from ‘Production’ to ‘Operations’
    10. Increment the salary of ‘Joe’ by Rs. 2000
    11. Add email Id for ‘Joe’ (using $AddToSet modifier with update)
    12. Remove all the documents for the employees belonging to ‘Operations’ department
    13. Sort all the documents according to the name of employees
    14. Display only first three documents
    15. Display all the documents except first 4
    16. Use all the administrative commands of MongoDB

### Statement 10 : Implement aggregation and indexing with suitable examples using MongoDB.
    1. Create Collection Product
    2. Insert the documents by considering the keys name, company, cost
    3. Aggregate the documents in the collection by grouping company name and displaying minimum and maximum price of product for the same company
    4. Show the sorted result on the basis of company
    5. Display number of documents in the collection
    6. Display distinct company names in the collection
    7. Display company name with its count for documents
    8. Limit the result for one document only
    9. Limit the result by skipping first two documents
    10. Insert 10 documents by using for loop in the collection staff by considering keys Staff_id, staff_name,age
    11. Find the document where Staff_id is 2 and explain different parameters for running the query. Observe the number of scanned objects, time in milliseconds, type of cursor etc.
    12. create index on staff_name
    13. Run the query for point no 11 and observe the change in values for different parameters of the query
    14. Find the document of the staff where age is 40 and staff_name is ‘Karan’. Observe the index name used for running the query
    15. create the index on age and Staff_name
    16. Run the query for point no. 14 and observe the index used for running the querying
    17. Drop the index created on age and Staff_name and run the query for point no. 14 again and observe the type of index
    18. Drop the index created on Staff_name and run the query for pint no. 11 and observe the type of index
    19. Create a unique index on Staff_name and try inserting documents with the duplicate Staff_names. Observe the result

### Statement 11 :  Implement Map Reduce operation with suitable example using MongoDB.
Create collection Staff with keys name, age and address. Apply Map Reduce operation over Staff collection to display the name of staff and sum of ages of the staff 
having same name.

### Statement 12 : Write a program to implement MongoDB database connectivity with Java. Implement Database navigation operations (add, delete, edit etc. ) using JDBC.
