-- Write your PostgreSQL query statement below


select a.employee_id from Employees a Where a.manager_id is not NULL and a.salary<30000 and (select COUNT(employee_id) from  Employees where a.manager_id=employee_id)=0. ORDER BY employee_id ASC;