with cte as(
    select
        employee_id,
        department_id,
        count(*) over(
            partition by employee_id
        ) as Counter,
        primary_flag
    from Employee
),
cte2 as (
    select employee_id,
        department_id,
        case
            when counter = 1 and primary_flag = 'N' then 'Y'
            when counter >= 2 and primary_flag = 'Y' then 'Y'
            else 'F'
        end as Flags
        from cte
)
select 
    employee_id,
    department_id
from cte2
where flags = 'Y'