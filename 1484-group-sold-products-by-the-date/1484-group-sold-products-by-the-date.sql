# Write your MySQL query statement below


Select sell_date,Count(Distinct product) as num_sold,Group_Concat(DISTINCT product order by product separator ',') AS products From Activities Group by sell_date;