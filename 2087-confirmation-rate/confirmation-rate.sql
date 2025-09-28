# Write your MySQL query statement below
SELECT s.user_id, 
     IFNULL(ROUND(SUM(action = 'confirmed') / COUNT(*), 2), 0.00) AS confirmation_rate
FROM Signups AS s
LEFT JOIN Confirmations AS c ON c.user_id = s.user_id
GROUP BY s.user_id;
