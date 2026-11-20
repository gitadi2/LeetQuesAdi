# Write your MySQL query statement below

# Using the Left Join first
SELECT e1.name AS Employee 
FROM Employee e1
LEFT JOIN Employee e2
ON e1.managerId=e2.id
WHERE e1.salary>e2.salary       # e1--for Employee and e2-- for the manager 

