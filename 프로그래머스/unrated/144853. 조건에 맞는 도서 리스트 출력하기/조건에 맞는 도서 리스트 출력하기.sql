select BOOK_ID, date_format(PUBLISHED_DATE, '%Y-%m-%d') as PUBLISHED_DATE
from book
where left(published_date, 4) = '2021' and category = '인문'
order by published_date asc;
