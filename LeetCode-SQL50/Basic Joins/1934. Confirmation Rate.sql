# Write your MySQL query statement below
SELECT s.user_id, ROUND(SUM(CASE WHEN c.action = 'confirmed' then 1 else 0 END)/COUNT(*),2) AS confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c
ON s.user_id = c.user_id
GROUP BY user_id
