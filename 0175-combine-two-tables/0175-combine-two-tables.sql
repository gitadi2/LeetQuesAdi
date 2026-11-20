# Write your MySQL query statement below

SELECT p.firstName,p.lastName,a.city,a.state
FROM Person p
LEFT JOIN Address a                    # Left Join: all the cols of Table Person will come first then joined ones
ON p.personId=a.personId