-- Write your PostgreSQL query statement below


select product_id,'store1' as store , store1 as price from Products Where store1 IS NOT NULL 

UNION ALL

select product_id,'store2' as store , store2 as price from Products Where store2 IS NOT NULL 


UNION ALL

select product_id,'store3' as store , store3 as price from Products Where store3 IS NOT NULL 
;
