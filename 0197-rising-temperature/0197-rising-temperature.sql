# Write your MySQL query statement below
select t.id
from Weather t
join Weather p
on datediff(t.recordDate,p.recordDate) = 1 
and t.temperature>p.temperature;