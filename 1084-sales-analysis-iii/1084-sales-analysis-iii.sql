-- Write your PostgreSQL query statement below

Select Distinct a.product_id,a.product_name from Product a right join Sales b 
on a.product_id=b.product_id  group by a.product_id,a.product_name having MIN(sale_date)>='2019-01-01' and MAX(sale_date)<='2019-03-31';