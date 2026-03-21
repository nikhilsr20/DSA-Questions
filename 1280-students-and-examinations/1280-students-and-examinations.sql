# Write your MySQL query statement below



SELECT a.student_id,a.student_name, a.subject_name,count(e.subject_name) as attended_exams FROM (SELECT *
FROM Students
CROSS JOIN Subjects) a LEFT JOIN Examinations e ON a.subject_name=e.subject_name AND a.student_id=e.student_id GROUP BY a.student_id, a.student_name, a.subject_name ORDER BY a.student_id ASC;
