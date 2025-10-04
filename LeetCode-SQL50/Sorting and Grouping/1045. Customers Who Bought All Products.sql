# Write your MySQL query statement below
SELECT customer_id 
FROM Customer
GROUP BY customer_id
HAVING SUM(DISTINCT product_key) = (SELECT SUM(product_key) FROM Product)
