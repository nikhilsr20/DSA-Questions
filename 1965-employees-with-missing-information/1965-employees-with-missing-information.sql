-- Write your PostgreSQL query statement below
SELECT COALESCE(a.employee_id, b.employee_id) AS employee_id
FROM Employees a
FULL JOIN Salaries b 
ON a.employee_id = b.employee_id WHERE a.name is NULL 
or b.salary is NULL;