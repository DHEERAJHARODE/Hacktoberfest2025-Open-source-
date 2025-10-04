# Write your MySQL query statement below
SELECT max(num) AS num
FROM MyNumbers
WHERE num IN (
    SELECT num FROM MyNumbers GROUP BY num HAVING COUNT(*) = 1
)
