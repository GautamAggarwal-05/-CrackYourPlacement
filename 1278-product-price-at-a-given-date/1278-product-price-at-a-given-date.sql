select p1.product_id,
coalesce(
(select new_price
from Products p2 
where p1.product_id=p2.product_id and p2.change_date<='2019-08-16' 
order by p2.change_date desc limit 1),
10) as price
from Products p1
group by p1.product_id