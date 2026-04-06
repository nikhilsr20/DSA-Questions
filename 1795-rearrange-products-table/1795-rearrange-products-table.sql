-- Write your PostgreSQL query statement below
SELECT p.product_id, s.store, s.price
FROM Products p,
LATERAL (
    VALUES 
        ('store1', p.store1),
        ('store2', p.store2),
        ('store3', p.store3)
) AS s(store, price)
WHERE s.price IS NOT NULL;