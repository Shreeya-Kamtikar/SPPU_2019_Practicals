Connected to:
Oracle Database 11g Express Edition Release 11.2.0.2.0 - 64bit Production

SQL> create table library(bno number, name varchar2(20), author varchar2(20), allowed_days number);

SQL> insert into library values (101,'Hunger Games','Suzanne Collins',10);

SQL> insert into library values (102,'Divergent','Veronica Roth',10);

SQL> insert into library values (103,'Maze Runner','James Dashner',10);

SQL> insert into library values (104,'Wimpy Kid','Jeff Kinney',10);

SQL> create table lib_audit(bno number, old_allowed_days number, new_allowed_days number);

SQL> create or replace trigger t1 before update or delete on library
for each row
begin
insert into lib_audit values (:old.bno, :old.allowed_days, :new.allowed_days);
end;  

Trigger created.

SQL> update library set allowed_days=08 where bno = 101;

SQL> select * from library;

SQL> select * from lib_audit;

SQL> update library set allowed_days = 15 where bno = 104;

SQL> select * from library;

SQL> select * from lib_audit;

SQL> delete from library where bno = 101;

SQL> select * from lib_audit;


