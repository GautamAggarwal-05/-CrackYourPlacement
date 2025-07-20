# Write your MySQL query statement below
select a.activity_date as day , count(distinct a.user_id) as active_users
from Activity a 
where a.activity_date BETWEEN '2019-06-28' and '2019-07-27'
group by a.activity_date;