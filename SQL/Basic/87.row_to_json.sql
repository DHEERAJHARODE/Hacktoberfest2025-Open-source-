-- การแปลงแถวข้อมูลให้เป็น JSON ด้วย row_to_json()
-- database: saturn
-- table: province
-- topic: export query results to JSON

select * from province;

select row_to_json(province) from province;

select row_to_json(row(p_id, name)) 
    from province limit 5;

with cte as (
    select p_id, name 
    from province
    where region='S'
)
select row_to_json(cte) from cte;

copy (
    with cte as (
        select p_id, name 
        from province
        where region='S'
    )
    select row_to_json(cte) from cte
) to 'c:/temp/south.json';

