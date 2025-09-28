# Write your MySQL query statement below
SELECT p.product_name, year, price 
FROM Product as p
JOIN Sales as s ON s.product_id = p.product_id;
