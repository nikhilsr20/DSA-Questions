# Write your MySQL query statement below

SELECT p.project_id,ROUND(AVG(q.experience_years),2) as average_years FROM Project p LEFT JOIN Employee q ON p.employee_id=q.employee_id GROUP BY p.project_id;