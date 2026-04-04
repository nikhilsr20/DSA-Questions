CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (Salary INT) AS $$
BEGIN
 IF N<1 Then 
    RETURN Query(SELECT NULL::INT AS salary);
 ELSE   
  RETURN QUERY 
    -- Write your PostgreSQL query statement below.
    select distinct Employee.salary from Employee order By salary desc LIMIT 1 OFFSET N-1;
    END IF;
      
  
END;
$$ LANGUAGE plpgsql;