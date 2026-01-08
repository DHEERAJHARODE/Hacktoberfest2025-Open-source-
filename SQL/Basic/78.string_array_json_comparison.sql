-- เปรียบเทียบการเก็บข้อมูลแบบ text, array และ json

drop table if exists staff;
create table staff(
    id int primary key,
    name varchar(50),
    skills text
);

insert into staff(id, name, skills) values
    (1, 'Peter', 'C|Java|SQL'),
    (2, 'Jane', 'C++|Python'),
    (3, 'Ann', 'Word|Excel|PowerPoint'),
    (4, 'Bruce', 'Swift|Objective-C|Word|Excel|PowerPoint');

select * from staff;

alter table staff 
    add column skills_a text[], -- type text[] เป็น array เพื่อให้้รู้ว่าคอลัมน์นั้นเก็บได้หลายค่า
    add column skills_j jsonb;

select * from staff;
-- string ไปเป็น array
select name, skills, regexp_split_to_array(skills, '\|') from staff;

update staff set skills_a = regexp_split_to_array(skills, '\|');
select * from staff;
---------------------
-- string ไปเป็น json
select name, skills, array_to_json(regexp_split_to_array(skills, '\|')) from staff;

update staff set skills_j = array_to_json(regexp_split_to_array(skills, '\|'));
select * from staff;
--------------------
select * from staff where 'Python' = any(skills_a); -- check from array
select * from staff where skills like '%Python%';
select * from staff where skills_j ? 'Python'; -- check from json

select * from staff where skills like '%C%';
select * from staff where 'C' = any(skills_a);
select * from staff where skills_j ? 'C';

select name, skills_a, skills_a[1], skills_j->0, skills_j->>0 from staff;