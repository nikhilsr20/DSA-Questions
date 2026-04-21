-- Write your PostgreSQL query statement below
select ROUND((SELECT COUNT(*)
FROM (
    SELECT DISTINCT ON (customer_id) *
    FROM Delivery
    ORDER BY customer_id, order_date
) t
WHERE t.order_date = t.customer_pref_delivery_date)*100.0/(select count(distinct b.customer_id)from Delivery b),2) as immediate_percentage;