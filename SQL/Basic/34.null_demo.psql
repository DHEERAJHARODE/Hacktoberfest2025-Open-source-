รู้จักกับค่า null และการประยุกต์ใช้
-- null concept
drop table if exists emp_null;

select * from employee limit 10;

-- create emp_null table
select * 
    into emp_null 
    from employee limit 10;

select * from emp_null;

update emp_null
    set lname=null where empid in (3, 8);
select * from emp_null;

update emp_null
    set dob=null where empid in (2, 7, 10);

select * from emp_null;

select * from emp_null where dob is null;

select * from emp_null where lname is null;
select * from emp_null where lname is not null;

update emp_null 
    set weight_kg = null
    where empid in (1, 3, 5);

select * from emp_null;

select count(weight_kg) from emp_null;

select avg(weight_kg) from emp_null;

# 75.714

update emp_null
    set weight_kg = 75.714
    where weight_kg is null;

select * from emp_null;

update emp_null 
    set weight_kg = null
    where empid in (1, 3, 5);

select * from emp_null;

update emp_null
    set weight_kg = (select avg(weight_kg) from emp_null)
    where weight_kg is null;

select * from emp_null;