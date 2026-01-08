-- การแบ่งข้อมูลในคอลัมน์ออกจากกันด้วย string_to_array()
-- use string_to_array() to split full name into first and last name column
-- database: saturn
-- table: movie1000, topmovie
SELECT * from movie1000

select director from movie1000;

select director, 
    string_to_array(director, ' ') from movie1000; -- ใช้ string_to_array ผ่านตัว คอลัม director เข้าไป โดยข้อมูลที่จะ split ถูกคั้นด้วย space bar

-- common table expression
with cte as (
select director, 
    string_to_array(director, ' ') as names from movie1000    
)
select names[1] fname, names[2] lname from cte;

select * from movie1000;

drop table if exists topmovie;
select title, year, director 
    into topmovie
    from movie1000;

SELECT * from topmovie;

alter table topmovie
    add column fname varchar(50),
    add column lname varchar(50);


select * from topmovie;

with cte as (
select *, 
    string_to_array(director, ' ') as names from topmovie    
)
update topmovie
    set fname=cte.names[1], lname=cte.names[2]
    from cte where topmovie.director=cte.director;

select director, fname, lname from topmovie;
