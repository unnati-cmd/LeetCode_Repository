/* Write your T-SQL query statement below */
select t.Department, t.Employee, t.Salary
from (select d.name as Department, e.name as Employee, e.salary,
dense_rank() over(partition by departmentId order by salary desc) as dt
from Employee e
join Department d
on e.departmentId = d.id) t
where dt = 1;