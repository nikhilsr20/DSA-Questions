# Write your MySQL query statement below

SELECT DISTINCT Email FROM (SELECT e1.email AS Email FROM Person e1 JOIN Person e2 ON e1.email = e2.email WHERE e1.id != e2.id) AS temp;