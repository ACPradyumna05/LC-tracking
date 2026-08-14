-- Last updated: 14/08/2026, 15:35:27
# Write your MySQL query statement below
select tweet_id from Tweets where char_length(content)>15;