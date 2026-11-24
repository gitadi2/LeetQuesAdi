# Write your MySQL query statement below

#--By Using the Common Table Expression Concept---
WITH cte AS 
(SELECT customer_number, COUNT(order_number) AS NumOrd
FROM Orders 
GROUP BY customer_number)

#--Now Selecting the Max No. of Orders from the cte ---
SELECT customer_number
FROM cte
WHERE NumOrd=(SELECT MAX(NumOrd) FROM cte)
