CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
        select distinct salary from(
            select salary, 
                dense_rank()
                over(order by salary desc) dt
            from Employee) t
        where dt = N
  );
END