# Write your MySQL query statement below
SELECT EmployeeUNI.unique_id AS unique_id, name 
FROM Employees 
LEFT JOIN EmployeeUNI ON Employees.id = EmployeeUNI.id;
