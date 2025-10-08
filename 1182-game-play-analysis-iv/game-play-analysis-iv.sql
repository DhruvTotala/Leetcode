# Write your MySQL query statement below
SELECT ROUND(COUNT(DISTINCT player_id) / (SELECT COUNT(DISTINCT player_id) FROM ACTIVITY), 2) as
fraction
FROM ACTIVITY
WHERE (player_id, DATE_SUB(event_date, INTERVAL 1 DAY)) IN(
SELECT player_id, MIN(event_date) as first_login
FROM ACTIVITY
GROUP By player_id);