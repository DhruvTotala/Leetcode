# Write your MySQL query statement below
SELECT s.student_id, s.student_name, sub.subject_name,
COUNT(E.subject_name) AS attended_exams
FROM Students AS s
CROSS JOIN Subjects AS sub
LEFT JOIN Examinations AS E
ON s.student_id = E.student_id AND E.subject_name = sub.subject_name
GROUP BY s.student_id, s.student_name, sub.subject_name
ORDER BY s.student_id, sub.subject_name;