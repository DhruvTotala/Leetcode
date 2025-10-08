# Write your MySQL query statement below
SELECT 
date_format(trans_date, '%Y-%m') as month,
country,
COUNT(id) as trans_count,
SUM(if(state = 'approved', 1, 0)) as approved_count,
SUM(amount) as trans_total_amount,
SUM(if(state = 'approved', amount, 0)) as approved_total_amount
FROM transactions
GROUP BY month, country; 