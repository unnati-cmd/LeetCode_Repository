SELECT 
    l.book_id,
    l.title,
    l.author,
    l.genre,
    l.publication_year,
    (
        SELECT COUNT(*)
        FROM borrowing_records r
        WHERE r.book_id = l.book_id
          AND r.return_date IS NULL
    ) AS current_borrowers
FROM library_books l
JOIN borrowing_records b
    ON l.book_id = b.book_id
GROUP BY 
    l.book_id,
    l.title,
    l.author,
    l.genre,
    l.publication_year,
    l.total_copies
HAVING 
    COUNT(CASE 
        WHEN b.return_date IS NULL THEN 1
    END) = l.total_copies
ORDER BY 
    current_borrowers DESC,
    l.title ASC;