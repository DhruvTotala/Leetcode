# Write your MySQL query statement below
SELECT R.contest_id,
ROUND(COUNT(DISTINCT R.user_id) * 100/ (SELECT count(user_id) FROM users), 2) AS percentage
FROM Users AS u
RIGHT JOIN  Register AS R
ON u.user_id = R.user_id
GROUP BY R.contest_id
ORDER BY percentage DESC, R.contest_id ASC;