-- การสืบค้นข้อมูลใน array
drop table if exists applicant;

create table applicant(
    id int PRIMARY key,
    name varchar(50) not null,
    skills varchar(50)[] -- array of skills
);

insert into applicant(id, name, skills) values (1, 'Peter', '{C,Java,SQL}');

insert into applicant(id, name, skills) values 
    (2, 'Mike', '{"C","Java","SQL"}'),
    (3, 'Ann', '{Word,Excel 2016,PowerPoint}'),
    (4, 'Jane', '{"One, Two, Three","Word"}'),
    (5, 'Sharon', '{Python,SQL,C,C++,C#,Java}'),
    (6, 'John', '{MySQL,SQLite,C}');

select * from applicant;

select * from applicant
    where 'SQL' = any(skills); -- (ฟังก์ชั่น any() คือการหาตัวใดตัวนึ่งของ array) เป็นการหาคอลัมที่เป็นตัว array ที่เป็น character varying[]

select * from applicant
    where 'SQL' = any(skills) and 'Python' = any(skills);

-- @> contains (มีหรือป่าวใน array ไม่ต้องมีครบก็ได้)
select * from applicant
    where skills @> array['SQL','Python']::varchar[];

select * from applicant
    where 'SQL' = any(skills) or 'MySQL' = any(skills);

select id, name, unnest(skills) skill from applicant;

with cte as (
    select id, name, unnest(skills) skill from applicant
)
select id, name, skill 
    from cte
    where skill ilike '%Sql%' or skill ilike 'C%';

with cte as (
    select id, name, unnest(skills) skill from applicant
)
select distinct id, name
    from cte
    where skill ilike '%Sql%' or skill ilike '%C%';
