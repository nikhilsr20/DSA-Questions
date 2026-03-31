-- Write your PostgreSQL query statement below


select b.book_id,a.title,a.author,a.genre,a.publication_year,a.total_copies as current_borrowers from library_books a right join borrowing_records b on a.book_id=b.book_id Where b.return_date is NULL
Group by b.book_id,a.title,a.author,a.genre,a.publication_year,a.total_copies having Count(*)=a.total_copies Order by a.total_copies Desc, a.title asc;