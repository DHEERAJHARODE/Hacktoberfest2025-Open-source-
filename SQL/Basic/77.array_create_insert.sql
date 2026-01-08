-- การสร้างคอลัมน์ที่เก็บ array (เก็บค่าได้หลายค่า)
drop table if exists applicant;

create table applicant(
    id int PRIMARY key,
    name varchar(50) not null,
    skills varchar(50)[] -- array of skills
);

insert into applicant(id, name, skills) values (1, 'Peter', '{C,Java,SQL}');

select * from applicant;

insert into applicant(id, name, skills) values 
    (2, 'Mike', '{"C","Java","SQL"}'), --เก็บข้อมูลเป็น array
    (3, 'Ann', '{Word,Excel 2016,PowerPoint}'),
    (4, 'Jane', '{"One, Two, Three","Word"}'),
    (5, 'Sharon', '{Python,SQL,C,C++,C#,Java}'),
    (6, 'John', '{MySQL,SQLite,C}');

select * from applicant;

select name, skills, array_length(skills, 1) from applicant;

--array ใน postgres จะเริ่มจาก 1 ไม่ใช่ 0
select name, skills, skills[4] from applicant; 

drop table if exists appl_info;
create table appl_info(
    id int PRIMARY key,
    name varchar(50) not null 
);

drop table if exists appln_skills;
create table appl_skills(
    id int,
    skills varchar(50)
);

insert into appl_info(id, name) values(1, 'Peter');
insert into appl_skills(id, skills) values(1, 'C'), (1, 'Java'), (1, 'SQL');
select * from appl_skills;

insert into appl_info(id, name) values(6, 'John');
insert into appl_skills(id, skills) values(6, 'MySQL'), (6, 'SQLite'), (6, 'C');
select * from appl_skills;

-- unnest() จะ return a result table ที่เป็น array ให้มี 1 row สำหรับแต่ละองค์ประกอบของ array
select id, unnest(skills) skill from applicant;
