-- Write your PostgreSQL query statement below

select machine_id,-ROUND(sum(
CASE 
    WHEN activity_type = 'start' THEN timestamp
    ELSE -timestamp
END)::numeric/(COUNT(*)/2),3) as processing_time from Activity Group by machine_id Order by machine_id asc;