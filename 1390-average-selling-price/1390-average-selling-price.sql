# Write your MySQL query statement below
select p.product_id, (CASE 
WHEN ROUND(SUM(p.price * u.units)/SUM(u.units),2) IS NULL THEN 0
ELSE  ROUND(SUM(p.price * u.units)/SUM(u.units),2) END) AS average_price
from Prices p
left join UnitsSold u on p.product_id=u.product_id AND u.purchase_date >= p.start_date AND u.purchase_date <= p.end_date
group by p.product_id