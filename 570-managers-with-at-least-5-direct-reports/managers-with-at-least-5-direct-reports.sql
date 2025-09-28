# Write your MySQL query statement below
SELECT E.name
FROM Employee AS E
INNER JOIN Employee AS m ON E.id = m.managerId
GROUP BY m.managerID
HAVING COUNT(m.managerId) >= 5;