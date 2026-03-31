-- Write your PostgreSQL query statement below


select user_id,count(*) as prompt_count,Round((sum(tokens)::numeric)/count(*),2) as avg_tokens
From prompts group by user_id 
having count(*)>2 and (max(tokens)> Round((sum(tokens)::numeric)/count(*),2)) order by avg_tokens desc,user_id asc;