# Write your MySQL query statement below

with temp as(
    select product_id,MIN(year) as year from Sales group by product_id
)
select a.product_id,a.year as first_year ,a.quantity,a.price from Sales a right join temp b ON a.product_id=b.product_id AND a.year=b.year;