# Write your MySQL query statement below
SELECT prices.product_id, ROUND(SUM(price * units) / SUM(units), 2) AS average_price
FROM Prices JOIN UnitsSold 
ON prices.product_id = unitssold.product_id
AND purchase_date BETWEEN start_date AND end_date
GROUP BY product_id
