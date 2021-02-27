SELECT round(avg(rating), 2) FROM ratings
JOIN movies
ON movies.id = ratings.movie_id
WHERE year = 2012;