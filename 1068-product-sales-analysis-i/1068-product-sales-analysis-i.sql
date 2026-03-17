# Write your MySQL query statement below
SELECT a.product_name,b.year,b.price FROM Sales b INNER JOIN Product a ON a.product_id=b.product_id;