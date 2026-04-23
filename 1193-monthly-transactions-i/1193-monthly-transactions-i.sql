# Write your MySQL query statement below

select Date_Format(trans_date,'%Y-%m') as month,country,count(*)as trans_count,COUNT(CASE WHEN state = 'approved' THEN 1 END) as approved_count, SUM(amount) AS  trans_total_amount,sum(CASE WHEN state = 'approved' THEN amount Else 0 END) as approved_total_amount from Transactions group by month,country;