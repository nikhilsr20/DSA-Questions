# Write your MySQL query statement below

Select b.unique_id,a.name From Employees a Left join EmployeeUNI b ON a.id=b.id;