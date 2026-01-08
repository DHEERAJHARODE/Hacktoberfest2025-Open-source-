-- การ update ค่าใน array คอลัมน์ และการลบแถว
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

update applicant
    set skills = '{Python,R,SPSS}'
    where id=1;

update applicant
    set skills[1] = 'C++'
    where id=2;

update applicant
    set skills[5] = 'Swift'
    where id=2;

update applicant
    set skills[4] = 'Objective-C'
    where id=2;

update applicant
    set skills[4] = 'Objective-C'
    where id=1;

select * from applicant;
-- array_append(anyarray, anyelement) เอา anyelement ต่อท้ายใน colume (anyarray) 
update applicant
    set skills = array_append(skills, 'Go') -- เอา Go ต่อท้ายใน colume skills
    where id=1;
select * from applicant;

select * from applicant;
-- array_replace(anyarray, anyelement1, anyelement2) แทนที่ด้วย anyelement2 ที่ตำแหน่ง anyelement1 ใน array
update applicant
    set skills = array_replace(skills, 'SQL', 'PostgreSQL');
select * from applicant;

select * from applicant;
-- array_remove(anyarray, anyelement) ลบ element ใน array
update applicant
    set skills = array_remove(skills, 'Java');
select * from applicant;

-- delete
select * from applicant;
delete from applicant
    where 'C++' = any(skills);
select * from applicant;
