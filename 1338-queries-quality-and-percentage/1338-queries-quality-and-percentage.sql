# Write your MySQL query statement below
select q.query_name,
ROUND(AVG(q.rating/q.position),2) AS quality,
ROUND((
    count(Case
        when q.rating < 3
        then 1
        END
))*100/(count(q.query_name)),2) AS poor_query_percentage
from Queries q
group by q.query_name