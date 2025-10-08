# Write your MySQL query statement below
SELECT 
ROUND(SUM(if(min_order_date = min_customer_pref_delivery_date, 1, 0)) * 100 / COUNT(min_order_date), 2) as immediate_percentage
FROM 
(SELECT delivery_id, 
customer_id,
MIN(order_date) as min_order_date,
MIN(customer_pref_delivery_date) as min_customer_pref_delivery_date
FROM Delivery
GROUP BY customer_id) as new_table;