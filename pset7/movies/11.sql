SELECT title FROM movies
JOIN ratings, stars
ON movies.id = ratings.movie_id AND movies.id = stars.movie_id
WHERE person_id IN (SELECT id FROM people WHERE name = "Chadwick Boseman")
ORDER BY rating DESC
LIMIT 5;