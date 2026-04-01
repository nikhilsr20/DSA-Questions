-- Write your PostgreSQL query statement below
select query_name,
ROUND(sum(rating::numeric/position)/count(*),2) as quality,
ROUND((COUNT(CASE WHEN rating < 3 THEN 1 END)::numeric / COUNT(*)) * 100 ,2)
  AS poor_query_percentage
from Queries group by query_name;
