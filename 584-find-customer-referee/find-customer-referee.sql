# Write your MySQL query statement below
SELECT name
FROM customer
where referee_id is NULL OR
referee_id != 2;