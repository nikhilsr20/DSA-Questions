-- Write your PostgreSQL query statement below



(select a.name as results from Users a right join MovieRating b on a.user_id=b.user_id group by a.name ORDER BY COUNT(*) DESC, a.name ASC LIMIT 1)
UNION ALL
(select a.title as results from Movies a right join MovieRating b on a.movie_id=b.movie_id WHERE EXTRACT(YEAR FROM b.created_at) = 2020 
  AND EXTRACT(MONTH FROM b.created_at) = 2
   group by a.title 
HAVING AVG(b.rating) = (
    SELECT MAX(avg_rating)
    FROM (
        SELECT AVG(r2.rating) AS avg_rating
        FROM MovieRating r2
        WHERE EXTRACT(YEAR FROM r2.created_at) = 2020 
          AND EXTRACT(MONTH FROM r2.created_at) = 2
        GROUP BY r2.movie_id
    ) t
)
ORDER BY a.title ASC
LIMIT 1
);