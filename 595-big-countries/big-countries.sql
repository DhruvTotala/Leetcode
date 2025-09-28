# Write your MySQL query statement below
SELECT name, population, area
from world
where population >= 25000000 OR
area >= 3000000;