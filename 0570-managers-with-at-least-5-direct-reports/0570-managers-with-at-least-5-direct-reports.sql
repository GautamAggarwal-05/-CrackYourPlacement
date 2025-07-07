select name
from employee
where id in (select managerid from employee Group by managerid having count(*)>=5);
