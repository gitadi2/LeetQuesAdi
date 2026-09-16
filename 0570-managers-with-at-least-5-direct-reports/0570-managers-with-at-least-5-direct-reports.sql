# Write your MySQL query statement below

SELECT a1.name 
FROM Employee as a1
JOIN Employee a2
ON a1.id=a2.managerID
GROUP BY a2.managerID
HAVING COUNT(*)>=5

