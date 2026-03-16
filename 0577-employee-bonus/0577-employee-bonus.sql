# Write your MySQL query statement below

SELECT e1.name,e2.bonus FROM Employee e1 LEFT JOIN Bonus e2 ON e1.empId=e2.empId WHERE (bonus<1000 OR bonus IS NULL); 