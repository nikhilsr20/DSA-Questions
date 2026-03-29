-- Write your PostgreSQL query statement below


select employee_id,
CASE
WHEN employee_id%2=1 AND name not LIKE 'M%'
THEN salary
ELSE 0
END as bonus
FROM Employees ORDER BY employee_id ASC;