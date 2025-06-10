# Write your MySQL query statement below

SELECT w1.id
FROM Weather w1
INNER JOIN Weather w2
ON DATEDIFF(w1.recordDate,w2.recordDate)=1
AND w1.temperature>w2.temperature;


-- WHERE SUBDATE(w2.recordDate,1)=w1.recordDate;
-- Above line means that whenever we subtract the we date from 1 we should get w1.recordDate;