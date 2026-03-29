-- Write your PostgreSQL query statement below


Select a.product_id,
    COALESCE(
        ROUND(
            SUM(price * units)::numeric / NULLIF(SUM(units), 0),
            2
        ),
        0
    ) AS average_price FROM Prices a LEFT JOIN UnitsSold b ON a.product_id=b.product_id AND b.purchase_date>=a.start_date and b.purchase_date<=a.end_date Group BY a.product_id; 