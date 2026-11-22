# Write your MySQL query statement below

#---Method 1 ---
SELECT c.name AS Customers
FROM Customers c
LEFT JOIN Orders o
ON c.id=o.customerId
WHERE o.id IS NULL

