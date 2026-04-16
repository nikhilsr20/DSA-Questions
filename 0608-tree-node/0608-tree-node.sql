# Write your MySQL query statement below


select id, 
Case 
when p_id is NULL 
Then "Root"
WHEN id IN (SELECT p_id FROM Tree) THEN 'Inner'
ELSE 'Leaf'
End as type from Tree;