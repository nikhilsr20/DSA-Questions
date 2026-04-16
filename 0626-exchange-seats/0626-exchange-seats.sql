# Write your MySQL query statement below

select id,
case 
when id%2=0 Then lag(student,1) over (order by id)
Else lead(student,1,student) over (order by id)
End
as student 
from Seat;