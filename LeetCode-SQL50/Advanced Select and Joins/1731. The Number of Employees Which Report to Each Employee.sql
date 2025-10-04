# Write your MySQL query statement below

SELECT a.employee_id, a.name, COUNT(*) AS reports_count, ROUND(AVG(b.age)) AS average_age
FROM Employees a, Employees b
WHERE a.employee_id = b.reports_to
GROUP BY 1
ORDER BY 1
