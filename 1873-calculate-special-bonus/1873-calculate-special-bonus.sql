# Write your MySQL query statement below
select 
    employee_id,
    case
        when employee_id%2=1 and name not like 'M%' then salary*1
        else salary*0
    end as bonus
from Employees
order by employee_id;