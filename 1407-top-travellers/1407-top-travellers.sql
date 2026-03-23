# Write your MySQL query statement below
SELECT a.name, COALESCE(SUM(b.distance), 0) AS travelled_distance
FROM Users a
LEFT JOIN Rides b ON b.user_id = a.id
GROUP BY a.name,b.user_id
 ORDER BY travelled_distance
  DESC,name ASC;