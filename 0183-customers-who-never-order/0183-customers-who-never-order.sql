# Write your MySQL query statement below

#---Method 2---
SELECT c.name AS Customers 
FROM Customers c
WHERE c.id NOT  IN                   # Use id instead of name as name cant be un ique so misthings can happen
(SELECT c.id AS Customers             
FROM Customers c
INNER JOIN Orders o
ON c.id=o.customerId)
