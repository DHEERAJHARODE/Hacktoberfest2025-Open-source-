-- การแบ่งข้อความที่มีตัวคั่นเป็น array ด้วย regexp_split_to_array
-- database: saturn
-- table: movie1000

select * from movie1000 limit 10;
-- regexp_split_to_array to Split String using different Delimiters
-- regexp_split_to_array(coloum ที่จะ split, ที่ถูกแบ่งด้วย ','(com-ma))
select title, genre, regexp_split_to_array(genre, ',') genre_a
	from movie1000 limit 10;
	
alter table movie1000
	add column genre_a varchar[];-- วาชา อาเรย์
	
update movie1000
	set genre_a = regexp_split_to_array(genre, ',');
	
select title, genre_a from movie1000 limit 10;

select title, genre_a 
	from movie1000
	where 'Music' = any(genre_a);
	
select title, genre_a 
	from movie1000
	where 'music' = any(genre_a); -- ต้องเป็น case sensitive, Music ต้องเป็นตัวใหญ่

select title, genre_a 
	from movie1000
	where 'music' ilike any(genre_a); -- เป็น case insensitive
	
select title, genre_a 
	from movie1000
	where 'music' ~* any(genre_a);
	
select title, unnest(genre_a) g
	from movie1000 limit 10;
	
with cte as (
select title, unnest(genre_a) g
	from movie1000
)
select g, count(g) count 
	from cte 
	group by g 
	order by count desc;
