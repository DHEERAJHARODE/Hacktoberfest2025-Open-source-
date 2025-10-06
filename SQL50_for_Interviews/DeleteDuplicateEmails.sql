delete p from Person p, Person q
where
p.email = q.email and p.id > q.id;