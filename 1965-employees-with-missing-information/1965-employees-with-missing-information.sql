# Write your MySQL query statement below
with cte as (
    select 
        e1.employee_id,
        e1.name,
        s1.salary
    from Employees e1
    left join Salaries s1
        on e1.employee_id = s1.employee_id
    UNION
    select 
        s2.employee_id,
        e2.name,
        s2.salary
    from Employees e2
    right join Salaries s2
        on e2.employee_id = s2.employee_id
)
select cte.employee_id from cte
where cte.name is null or cte.salary is null
order by employee_id;