-- Write your PostgreSQL query statement below


select b.name as Department, a.name as Employee, a.salary as Salary From Employee a left join Department as b On a.departmentId = b.id Where (select Max(salary) From Employee where departmentId=a.departmentId) = a.salary;