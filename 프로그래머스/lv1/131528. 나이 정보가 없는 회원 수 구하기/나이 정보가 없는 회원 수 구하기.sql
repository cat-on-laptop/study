-- 코드를 입력하세요
# SELECT SUM(AGE is NULL) AS USERS
# FROM USER_INFO;

SELECT COUNT(*) AS USERS
FROM USER_INFO
WHERE AGE is NULL