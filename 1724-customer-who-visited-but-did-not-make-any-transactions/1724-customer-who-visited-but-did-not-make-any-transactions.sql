# Write your MySQL query statement below
with no_trans as (
    select *
    from Visits
    where visit_id not in (
        select visit_id
        from Transactions
    )
)

select distinct customer_id,
       count(visit_id) as count_no_trans
from no_trans
group by 1