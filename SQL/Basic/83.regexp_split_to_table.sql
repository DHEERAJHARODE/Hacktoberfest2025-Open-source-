-- การแบ่งข้อความที่มีตัวคั่นออกเป็นแถวใน table ด้วย regexp_split_to_table
select * from movie1000

select title, 
	regexp_split_to_table(genre, ',') g
	from movie1000;
	
with cte as (
select  
	regexp_split_to_table(genre, ',') g
	from movie1000
)
select g, count(g) as count 
	from cte
	group by g
	order by count desc;
	
select rank, regexp_split_to_table(genre, ',')
	into movie_genre
	from movie1000;

