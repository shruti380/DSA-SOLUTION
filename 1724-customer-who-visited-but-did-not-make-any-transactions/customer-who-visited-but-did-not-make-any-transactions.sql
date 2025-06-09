# Write your MySQL query statement below

SELECT v.customer_id, COUNT(customer_id) as count_no_trans 
FROM Visits v
LEFT JOIN Transactions t
ON v.visit_id  = t. visit_id   
Where t.transaction_id is NULL
GROUP BY v.customer_id ;
