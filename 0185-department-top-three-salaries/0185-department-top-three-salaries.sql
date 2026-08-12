# Write your MySQL query statement below
select t.Department, t.Employee, t.Salary 
from (select d.name as Department, e.name as Employee, e.salary as Salary,
Dense_rank() over(partition by e.departmentId order by e.salary desc) dt
from Employee e
join Department d
on e.departmentId = d.id) t
where t.dt <=3;