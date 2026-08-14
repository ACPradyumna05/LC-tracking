-- Last updated: 14/08/2026, 15:36:20
# Write your MySQL query statement below
select name from Customer where NOT referee_id = 2 or referee_id IS NULL;