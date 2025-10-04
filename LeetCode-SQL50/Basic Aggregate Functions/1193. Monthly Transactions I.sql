# Write your MySQL query statement below
SELECT 
  LEFT(trans_date,7) AS month, 
  country, 
  COUNT(id) AS trans_count, 
  SUM(state = 'approved') AS approved_count, 
  SUM(amount) as trans_total_amount, 
  SUM(CASE 
    WHEN state = 'approved' THEN amount 
    ELSE 0 
    END) AS approved_total_amount
FROM Transactions
GROUP BY month, country
