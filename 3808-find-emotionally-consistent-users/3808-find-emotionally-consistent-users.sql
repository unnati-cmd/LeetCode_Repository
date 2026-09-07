# Write your MySQL query statement below
with cte as(
    select
        r.user_id,
        count(r.reaction) as total_reactions
    from reactions r
    group by r.user_id
    having count(r.reaction)>4
)
select 
    c.user_id,
    reaction as dominant_reaction,
    round(count(reaction) / c.total_reactions,2) as reaction_ratio
from cte c
inner join reactions r
    on c.user_id = r.user_id
group by r.user_id,r.reaction, c.total_reactions
having count(reaction) / c.total_reactions > 0.6
order by reaction_ratio desc,user_id asc;