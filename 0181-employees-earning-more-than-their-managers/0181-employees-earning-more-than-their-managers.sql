# Write your MySQL query statement below

# Using the Inner Join first
SELECT e1.name AS Employee 
FROM Employee e1
INNER JOIN Employee e2         # Inner Join-- Gotta join where the values are NOT NULL for the managerId
ON e1.managerId=e2.id
WHERE e1.salary>e2.salary       # e1--for Employee and e2-- for the manager 

