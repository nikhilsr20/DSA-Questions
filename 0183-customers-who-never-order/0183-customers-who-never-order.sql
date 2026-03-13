# Write your MySQL query statement below
-- SELECT name AS Customers
-- FROM Customers 
-- WHERE id NOT IN(SELECT customerID FROM Orders);
SELECT Customers.name AS Customers FROM Customers LEFT JOIN Orders ON Customers.id=Orders.customerId Where Orders.customerID is NULL