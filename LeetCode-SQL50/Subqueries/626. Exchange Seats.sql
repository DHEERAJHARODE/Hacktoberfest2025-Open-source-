# Write your MySQL query statement below
SELECT  (
CASE
    WHEN MOD(id,2) != 0 AND counts != id THEN id+1
    WHEN MOD(id,2) != 0 AND counts = id THEN id
    ELSE id-1 
END
) AS id, student
FROM seat, (
    SELECT COUNT(*) AS counts
    FROM seat
) AS alias
ORDER BY id ASC
