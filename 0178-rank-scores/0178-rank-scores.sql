-- Write your PostgreSQL query statement below

Select score, DENSE_RANK() OVER (Order BY score DESC) as rank from Scores;