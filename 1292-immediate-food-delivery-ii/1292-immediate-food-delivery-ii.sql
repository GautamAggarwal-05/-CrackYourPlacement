# Write your MySQL query statement below
select 
ROUND(count(
CASE
    when d.order_date=d.customer_pref_delivery_date
    then 1
    end)*100/count(*),2)
AS  immediate_percentage
from Delivery d
join (
    select customer_id,min(order_date) as firstdate from Delivery
    group by customer_id
) firstorder on d.customer_id=firstorder.customer_id AND d.order_date=firstorder.firstdate;