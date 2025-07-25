# Write your MySQL query statement below
select t.x,t.y,t.z,
case 
when t.x+t.y>t.z AND t.y+t.z>t.x AND t.z+t.x>t.y
then 'Yes'
else 'No'
end
as triangle
from Triangle t;
