# Write your MySQL query statement below
select w2.id
from Weather w1
join Weather w2 on w2.temperature>w1.temperature and DATEDIFF(w2.recordDate,w1.recordDate) = 1