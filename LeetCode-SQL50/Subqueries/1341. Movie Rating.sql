# Write your MySQL query statement below
(SELECT u.name AS results 
  FROM MovieRating AS mr 
  LEFT JOIN  Users AS u 
  USING (user_id) 
  GROUP BY user_id 
  ORDER BY COUNT(movie_id) DESC, u.name ASC LIMIT 1) 
 
 UNION ALL 
 
 (SELECT m.title  
  FROM MovieRating AS mr 
  LEFT JOIN Movies AS m 
  USING (movie_id) 
  WHERE created_at BETWEEN '2020-02-01' AND '2020-02-29' 
  GROUP BY movie_id 
  ORDER BY AVG(rating) DESC, m.title ASC LIMIT 1)
