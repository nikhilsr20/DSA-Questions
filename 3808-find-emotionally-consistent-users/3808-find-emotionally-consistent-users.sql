-- Write your PostgreSQL query statement below
WITH temp AS (
    SELECT user_id, COUNT(*) AS total
    FROM reactions
    GROUP BY user_id
),
temp2 AS (
    SELECT user_id, reaction, COUNT(*) AS total
    FROM reactions
    GROUP BY user_id, reaction
)

select a.user_id,reaction as dominant_reaction, Round((b.total::numeric/a.total),2) as reaction_ratio from temp a left join temp2 b On a.user_id=b.user_id where a.total>=5 and (b.total::numeric/a.total)>=0.6 order by reaction_ratio Desc, user_id asc;
-- Write your PostgreSQL query statement below