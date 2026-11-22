# Write your MySQL query statement below
SELECT name 
FROM Customer
WHERE referee_id<>2       # <> means Not equal to in SQL 
OR referee_id IS NULL