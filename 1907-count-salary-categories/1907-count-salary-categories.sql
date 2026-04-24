# Write your MySQL query statement below

with temp as(
    select account_id,
    income,case when income<20000 Then "Low Salary"
    when income>=20000 and income<=50000 then "Average Salary" 
    when income>50000 Then "High Salary"
    END
    as type from Accounts
) 
select type as category,Count(type) as accounts_count from temp group by type
UNION ALL
select 'Average Salary' as category,0 where (Select count(*) from temp where type='Average Salary') = 0
UNION ALL
select 'Low Salary' as category,0 where (Select count(*) from temp where type='Low Salary') = 0
UNION ALL
select 'HighSalary' as category,0 where (Select count(*) from temp where type='High Salary') = 0;


