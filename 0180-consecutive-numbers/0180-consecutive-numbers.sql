-- Write your PostgreSQL query statement below

select Distinct a.num as ConsecutiveNums from Logs a where a.num=(select num from Logs where a.id-1=id ) and a.num=(select num from Logs where a.id-2=id );