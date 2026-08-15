# Write your MySQL query statement below
select distinct actor_id,director_id 
from(
    select actor_id,director_id,
    lead(director_id) over(partition by actor_id order by actor_id,director_id) as first,
    lag(director_id) over(partition by actor_id order by actor_id,director_id) as second
    from ActorDirector
    order by actor_id,director_id
) t
where t.first = t.director_id and t.second = t.director_id;