# Write your MySQL query statement below

SELECT email AS Email
FROM Person 
GROUP BY email
HAVING COUNT(DISTINCT id)>1        #Having is used inplace of where clause for filtering purpose 