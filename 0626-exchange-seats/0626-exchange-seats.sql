# Write your MySQL query statement below

select s1.id,Case
When id%2=1 And  s1.id != (SELECT MAX(id) FROM Seat) Then (select s.student from Seat s where s1.id+1=s.id)
When id%2=1 And  s1.id = (SELECT MAX(id) FROM Seat) Then (select s.student from Seat s where s1.id=s.id)
Else (select s.student from Seat s where s1.id-1=s.id)
END as student From Seat s1;