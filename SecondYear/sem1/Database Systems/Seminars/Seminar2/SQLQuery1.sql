USE ParcDistractii;

--DBCC CHECKIDENT ('[Vizitatori]', RESEED, 0);


INSERT INTO Sectiuni(nume_s, descriere)
VALUES ('Entrance Plaza', 'Zona de acces'),
	('Thrill Zone', 'Rollercoastere, drop towers'),
	('Family attraction zone', 'Carsuele clasice'),
	('Kiddie Area', 'Mini carusele'),
	('Food zone', 'Zona cu mancare'),
	('Entertainment Zone', 'Zona de spectacole si evenimnete'),
	('Zone administrative', 'Mentenata si vestiare');


SELECT * 
FROM Sectiuni
WHERE nume_s LIKE 'F%'

SELECT *
FROM Sectiuni
WHERE nume_s LIKE '%e' AND nume_s LIKE '%__%'

UPDATE Sectiuni SET descriere = 'Zona de acces!!'
WHERE nume_s = 'Entrance Plaza'

--SELECT * FROM Sectiuni;

INSERT INTO Categorii (nume_c)
VALUES
    ('Adulti'),
    ('Copii'),
    ('Familie'),
    ('Adolescenti'),
    ('Seniori'),
    ('VIP'),
    ('Grupuri');

UPDATE Categorii SET nume_c = 'Tineri'
WHERE nume_c = 'Adolescenti'

UPDATE Categorii SET nume_c = 'Pensionari'
WHERE nume_c = 'Seniori'

SELECT * 
FROM Categorii
WHERE nume_c = 'Pensionari' OR nume_c = 'Copii'

--SELECT * FROM Categorii;

INSERT INTO Atractii (nume_a, descriere, varsta_minima, id_s)
VALUES
    ('Mega Coaster', 'Rollercoaster de mare viteza', 14, 2),
    ('Drop Tower', 'Turn cu cadere libera', 16, 2),
    ('Carusel Magic', 'Carusel pentru intreaga familie', 3, 3),
    ('Mini Tren', 'Tren pentru copii', 2, 4),
    ('Casa Oglinzilor', 'Atractie cu oglinzi deformante', 6, 3),
    ('Scena Principala', 'Spectacole si concerte', 0, 6),
    ('Masinute Electrice', 'Masinute pentru copii si adulti', 5, 4);

DELETE FROM Atractii WHERE nume_a = 'Mega Coaster'

UPDATE Atractii SET varsta_minima = 3,
                    descriere = 'Modificata'
WHERE nume_a = 'Mega Coaster'

--SELECT * FROM Atractii;

INSERT INTO Vizitatori (nume_v, email, id_c)
VALUES
    ('Andrei Popescu', 'andrei.popescu@email.com', 1),
    ('Maria Ionescu', 'maria.ionescu@email.com', 2),
    ('Alex Dumitru', 'alex.dumitru@email.com', 3),
    ('Elena Stan', 'elena.stan@email.com', 4),
    ('Mihai Radu', 'mihai.radu@email.com', 5),
    ('Ioana Matei', 'ioana.matei@email.com', 6),
    ('Vlad Georgescu', 'vlad.georgescu@email.com', 7);

UPDATE Vizitatori set nume_v = 'Stefania Niki'
WHERE  id_c = 1

--SELECT * FROM Vizitatori;

INSERT INTO Note (id_a, id_v, nota)
VALUES
    (1, 1, 5),
    (2, 1, 4),
    (3, 2, 5),
    (4, 3, 4),
    (5, 4, 3),
    (6, 5, 5),
    (7, 6, 4);

UPDATE Note SET nota = 5
WHERE id_a = 2 AND id_v = 1;

DELETE FROM Note WHERE id_a = 2 AND id_v = 1;

--SELECT * FROM Note;


--INSERT INTO Atractii(nume_a,descriere,varsta_minima,id_s)

--interogare care afiseaza toti vizitatorii care nu au dat nicio nota niciunei atractii
SELECT V.nume_v
FROM Vizitatori V
WHERE NOT EXISTS
(
    SELECT *
    FROM Note N
    WHERE N.id_v = V.id_v
)

--interogare care afiseaza numele vizitatorilor nota si numele atractiei evaluate

SELECT V.nume_v, A.nume_a 
FROM Vizitatori V
INNER JOIN Note N
ON V.id_v = N.id_v
INNER JOIN Atractii A
ON A.id_a = N.id_a

--interogare care afiseaza numele vizitatorilor si numarul de note pe care l au dat atractiilor(se vor include si numele vizitatorile care nu au dat nicio nota)
SELECT V.nume_v,COUNT(N.nota) AS Nr_note
FROM Vizitatori V
LEFT JOIN Note N
ON V.id_v = N.id_v
GROUP BY V.id_v

--scrieti o interogare care afiseaza valorile distincte ale notelor date distractiilor
SELECT DISTINCT N.nota
FROM Note N


--interogare pt sectiunile care au cel putin o atractie asociata(se vor include si atactiile care nu au nicio sectiune asociata)

SELECT S.nume_s, A.nume_a, A.descriere
FROM Sectiuni S
RIGHT JOIN Atractii A
    ON S.id_s = A.id_s;


--interogare care afiseaza numele si varsta minima si nr de note pt toate atractiile care au primit cel putin 2 note
SELECT A.nume_a, A.varsta_minima,COUNT(A.id_a) AS NR_NOTE
FROM Atractii A
INNER JOIN Note N
ON A.id_a = N.id_a
GROUP BY A.id_a,A.nume_a,A.varsta_minima
HAVING COUNT(A.id_a) >= 2

--interogare care afiseaza numele categoriei , numele vizitatorului, nota , numele atactiei si descrierea atractiei
SELECT C.nume_c, V.nume_v, N.nota, A.nume_a, A.descriere
FROM Categorii C
INNER JOIN Vizitatori V ON C.id_c = V.id_c
INNER JOIN Note N ON V.id_v = N.id_v
INNER JOIN Atractii A ON N.id_a = A.id_a
WHERE C.nume_c <> 'Adult';


SELECT A.nume_a
FROM Atractii A
WHERE A.id_a NOT IN
(
    SELECT N.id_a
    FROM Note N
    WHERE N.nota = 9 

)
AND A.id_a IN
(
    SELECT N.id_a
    FROM Note N
    WHERE N.nota = 10 

)

