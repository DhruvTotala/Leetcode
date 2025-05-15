WITH stadium_with_rnk AS
(
    SELECT id, visit_date, people, rnk, (id - rnk) AS island
    FROM (
        SELECT id, visit_date, people, RANK() OVER(ORDER BY id) AS rnk
        FROM Stadium
        WHERE people >= 100) AS t0
)
SELECT id, visit_date, people 
FROM stadium_with_rnk
WHERE island IN (SELECT island 
                 FROM stadium_with_rnk 
                 GROUP BY island 
                 HAVING COUNT(*) >= 3)
ORDER BY visit_date