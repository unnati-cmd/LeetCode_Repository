# Write your MySQL query statement below
with cte as 
(
    select 
        e1.employee_id,
        e1.salary,
        (
            select e.employee_id
            from Employees e
            where e.employee_id = e1.manager_id
        ) as ID
    from Employees e1
    where e1.manager_id is not null
)
select cte.employee_id
from cte
where cte.ID is null and cte.salary<30000
order by cte.employee_id;