-- /* Write your T-SQL query statement below */
with ctea1 as(
    select 
        u.user_id,
        u.name,
        count(rating) as total_count
    from movieRating mr
    join users u
        on mr.user_id = u.user_id
    group by u.user_id,u.name
),
ctea2 as (
    select 
        user_id,
        name,
        total_count,
        row_number() over(order by total_count desc,name asc) as rank
    from ctea1
),
cteb1 as (
    select 
        m.movie_id,
        title,
        avg(cast(rating as FLOAT)) as avg_rating
    from movies m
    join movieRating mr
        on m.movie_id = mr.movie_id
    where created_at >= '2020-02-01' and created_at < '2020-03-01'
    group by m.movie_id,title
),
cteb2 as (
    select
        movie_id,
        title,
        avg_rating,
        row_number() over(order by avg_rating desc, title asc) as rank
    from cteb1        
)
select name as results from ctea2 where rank = 1
union all
select title as results from cteb2 where rank = 1