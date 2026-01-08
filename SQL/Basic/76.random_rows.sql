-- การสุ่มแถวและเทคนิคแบ่งแถวในตารางออกเป็น 70:30
-- database: saturn

-- learn how to use and apply function random()
select * from province;

select random(); -- ฟังก์ชั่นนี้จะส่ง่าเป็นตัวเลขทศนิยม 0-1 ออกมา

select name, random() from province;

select name, random() from province order by random();

select name, random() from province order by random() limit 1;

select count(*) from province;

-- เอา 70%, 30%
select count(*), count(*) * .7, count(*) * .3 from province;

-- use floor() to round number down(ปัดลง)
select count(*), floor(count(*) * .7), count(*) * .3 from province;

--select name, random() from province order by random() limit 53;
select name, random() from province order by random() limit (select floor(count(*) * .7) from province);

-- split into 70:30 (training, test)
drop table if exists training, test;

select * 
    into training
    from province order by random() limit (select floor(count(*) * .7) from province);

select * from training; --53 แถว

-- ทุกแถวที่มีอยู่ในตาราง province แต่ไม่มีอยู่ใน ตาราง training -- ที่เหลือ 24 แถว
select * from province
EXCEPT
select * from training;

with cte as (
    select * from province
    EXCEPT
    select * from training
)
select *
    into test 
    from cte;

select * from test; --24 rows
select * from training; --53 rows


