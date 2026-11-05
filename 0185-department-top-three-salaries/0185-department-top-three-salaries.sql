/* Write your T-SQL query statement below */
with cte as (
    select 
        d.name as Department,
        e.departmentId,
        e.name as Employee,
        salary as Salary,
        Dense_rank() over(partition by departmentId order by salary desc) as rn
    from employee e
    join Department d
        on e.departmentId = d.id
)
select 
    Department,
    Employee,
    Salary
from cte
where rn<=3;