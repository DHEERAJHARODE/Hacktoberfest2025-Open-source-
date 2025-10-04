# Write your MySQL query statement below
SELECT DISTINCT employee_id, department_id
FROM Employee 
WHERE employee_id IN
    (
    SELECT employee_id
    FROM Employee
    GROUP BY 1
    HAVING COUNT(*) = 1
    )
    OR primary_flag = 'Y'
ORDER BY 1
