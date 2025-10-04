# Write your MySQL query statement below
SELECT person_name 
FROM 
(
  SELECT person_name, SUM(weight) OVER(ORDER BY turn) as com_weight
  FROM queue
) alias
WHERE com_weight <= 1000
ORDER BY com_weight DESC
LIMIT 1
