USE SalaFitnessDB;

INSERT INTO Tip_Abonament (denumire, pret, durata_zile)
VALUES
	('Standard', 100.00, 30),
	('Personal Trainer Lunar', 350.00, 30),
	('Anual Standard', 1100.00, 365),
	('Personal Trainer Anual', 3000.00, 365);


SELECT *
FROM Tip_Abonament;

INSERT INTO Membru (nume, prenume, telefon, email, data_nasterii)
VALUES
    ('Popescu', 'Andrei', '0721111111', 'andrei.popescu@gmail.com', '2002-04-15'),
    ('Ionescu', 'Maria', '0722222222', 'maria.ionescu@gmail.com', '1998-07-21'),
    ('Dumitru', 'Alexandru', '0723333333', 'alex.dumitru@gmail.com', '2000-11-03'),
    ('Stan', 'Elena', '0724444444', 'elena.stan@gmail.com', '2003-02-18'),
    ('Radu', 'Mihai', '0725555555', 'mihai.radu@gmail.com', '1995-09-12'),
    ('Munteanu', 'Ioana', '0726666666', 'ioana.munteanu@gmail.com', '2001-06-25'),
    ('Dobre', 'Vlad', '0727777777', 'vlad.dobre@gmail.com', '1999-12-08'),
    ('Marin', 'Ana', '0728888888', 'ana.marin@gmail.com', '2004-03-30'),
    ('Tudor', 'Cristian', '0729999999', 'cristian.tudor@gmail.com', '1997-08-14'),
    ('Florea', 'Gabriela', '0720000000', 'gabriela.florea@gmail.com', '2002-10-05');


SELECT *
FROM Membru;


INSERT INTO Antrenor (nume, prenume, specializare, telefon, salariu, data_angajarii)
VALUES
    ('Popa', 'Mihai', 'Fitness', '0731111111', 4500.00, '2022-03-15'),
    ('Marinescu', 'Andreea', 'Yoga', '0732222222', 4000.00, '2023-06-01'),
    ('Dumitrescu', 'Vlad', 'Bodybuilding', '0733333333', 5200.00, '2021-09-10'),
    ('Stan', 'Cristina', 'Pilates', '0734444444', 4200.00, '2024-01-20'),
    ('Radu', 'Alexandru', 'Cardio', '0735555555', 4300.00, '2022-11-05'),
    ('Ionescu', 'Elena', 'Fitness', '0736666666', 4600.00, '2023-02-12'),
    ('Munteanu', 'Robert', 'CrossFit', '0737777777', 5500.00, '2020-07-18'),
    ('Tudor', 'Ioana', 'Yoga', '0738888888', 4100.00, '2024-05-10'),
    ('Dobre', 'Andrei', 'Bodybuilding', '0739999999', 5000.00, '2021-04-25'),
    ('Florea', 'Gabriela', 'Pilates', '0730000000', 4400.00, '2023-09-15');


SELECT *
FROM Antrenor;


INSERT INTO Clasa_Grup (denumire, descriere, nivel_dificultate)
VALUES
    ('Body Pump', 'Antrenament cu greutati pentru toate grupele musculare', 'Mediu'),
    ('Yoga', 'Exercitii pentru flexibilitate, echilibru si relaxare', 'Usor'),
    ('Pilates', 'Exercitii pentru postura si musculatura trunchiului', 'Mediu'),
    ('Spinning', 'Antrenament cardio pe biciclete', 'Mediu'),
    ('CrossFit', 'Antrenament functional de intensitate ridicata', 'Avansat'),
    ('Aerobic', 'Antrenament cardio pe muzica', 'Usor'),
    ('Zumba', 'Dans si exercitii cardio', 'Mediu'),
    ('Functional Training', 'Exercitii pentru forta si mobilitate', 'Avansat'),
    ('Stretching', 'Exercitii pentru flexibilitate si mobilitate', 'Usor'),
    ('HIIT', 'Antrenament pe intervale de intensitate ridicata', 'Avansat');


SELECT *
FROM Clasa_Grup;


INSERT INTO Abonament_Membru (id_tip_abonament, id_membru, pret_platit, data_inceput, data_sfarsit, status)
VALUES
    (1, 1, 100.00, '2026-10-01', '2026-10-30', 'Activ'),
    (2, 2, 350.00, '2026-10-05', '2026-11-03', 'Activ'),
    (3, 3, 1100.00, '2026-01-01', '2026-12-31', 'Activ'),
    (4, 4, 3000.00, '2025-10-01', '2026-09-30', 'Expirat'),
    (1, 5, 100.00, '2026-09-01', '2026-09-30', 'Expirat'),
    (2, 6, 350.00, '2026-10-10', '2026-11-08', 'Activ'),
    (3, 7, 1100.00, '2026-03-01', '2027-02-28', 'Activ'),
    (1, 8, 100.00, '2026-10-15', '2026-11-13', 'Activ'),
    (4, 9, 3000.00, '2026-01-01', '2026-12-31', 'Activ'),
    (2, 10, 350.00, '2026-08-01', '2026-08-30', 'Anulat');

SELECT * 
FROM Abonament_Membru;


INSERT INTO Plata (id_abonament, suma, data_plata, metoda_plata)
VALUES
(1, 50.00, '2026-10-01', 'Card'),
(1, 50.00, '2026-10-05', 'Numerar'),
(2, 200.00, '2026-10-05', 'Card'),
(2, 150.00, '2026-10-10', 'Transfer bancar'),
(3, 1100.00, '2026-01-01', 'Card'),
(4, 1500.00, '2025-10-01', 'Card'),
(4, 1500.00, '2025-10-15', 'Numerar'),
(5, 100.00, '2026-09-01', 'Numerar'),
(6, 350.00, '2026-10-10', 'Card'),
(9, 1500.00, '2026-01-01', 'Transfer bancar');


SELECT *
FROM Plata;


SELECT p.id_abonament, COUNT(*) AS numar_plati, SUM(suma) AS total_platit,a.pret_platit as pret_total_de_platit
FROM Plata p
LEFT JOIN Abonament_Membru a
ON p.id_abonament = a.id_abonament
GROUP BY p.id_abonament,a.pret_platit;


INSERT INTO Zona (denumire, descriere, capacitate_maxima)
VALUES
    ('Zona de fitness', 'Aparate si greutati pentru antrenamente', 30),
    ('Zona de cardio', 'Benzi de alergare si biciclete stationare', 20),
    ('Zona de yoga si pilates', 'Spatiu pentru yoga, pilates si stretching', 15),
    ('Zona de aerobic', 'Spatiu pentru aerobic si Zumba', 25),
    ('Zona de greutati', 'Ganterele, bare si greutati libere', 20),
    ('Zona pentru clase de grup', 'Spatiu pentru Body Pump, HIIT si alte clase', 25);

SELECT *
FROM Zona


INSERT INTO Programare_Clasa(id_clasa, id_antrenor, id_zona, data_ora_start, durata_minute)
VALUES
    (2, 1, 1, '2026-10-10 09:00:00', 60),
    (3, 1, 1, '2026-10-15 10:00:00', 60),
    (1, 2, 3, '2026-10-12 11:00:00', 60),
    (1, 1, 1, '2026-10-22 09:00:00', 60),
    (2, 2, 3, '2026-10-22 10:00:00', 60),
    (3, 4, 3, '2026-10-22 11:00:00', 50),
    (4, 5, 2, '2026-10-22 12:00:00', 45),
    (5, 7, 5, '2026-10-22 14:00:00', 60),
    (6, 6, 4, '2026-10-22 15:00:00', 45),
    (7, 8, 4, '2026-10-22 16:00:00', 60),
    (8, 3, 6, '2026-10-23 09:00:00', 60),
    (9, 2, 3, '2026-10-23 10:00:00', 30),
    (10, 9, 1, '2026-10-23 11:00:00', 45);

SELECT *
FROM Programare_Clasa;

SELECT id_programare, id_clasa, id_antrenor, id_zona, data_ora_start
FROM Programare_Clasa
ORDER BY id_programare;

INSERT INTO Inscriere_Clasa
    (id_programare, id_membru, data_inscrierii, status_prezenta)
VALUES
    (2, 1, '2026-10-19', 'Prezent'),
    (2, 2, '2026-10-20', 'Prezent'),
    (3, 3, '2026-10-18', 'Inscris'),
    (3, 4, '2026-10-21', 'Prezent'),
    (4, 5, '2026-10-17', 'Absent'),
    (5, 6, '2026-10-20', 'Inscris'),
    (6, 7, '2026-10-16', 'Prezent'),
    (7, 8, '2026-10-21', 'Inscris'),
    (8, 9, '2026-10-19', 'Anulat'),
    (9, 1, '2026-10-20', 'Inscris');

SELECT *
FROM Inscriere_Clasa;


INSERT INTO Echipament
    (id_zona, denumire, marca, data_achizitie, stare)
VALUES
    (1, 'Banda de alergare', 'Technogym', '2024-03-15', 'Functional'),
    (2, 'Bicicleta stationara', 'Life Fitness', '2023-06-20', 'Functional'),
    (1, 'Aparat pentru extensii picioare', 'Technogym', '2024-01-10', 'Functional'),
    (5, 'Set gantere', 'Decathlon', '2023-09-05', 'Functional'),
    (6, 'Saltele fitness', 'Reebok', '2024-05-12', 'Functional'),
    (2, 'Bicicleta eliptica', 'NordicTrack', '2022-11-18', 'Necesita revizie'),
    (1, 'Banca pentru impins', 'Hammer Strength', '2023-04-22', 'Functional'),
    (5, 'Bara olimpica', 'Eleiko', '2024-02-08', 'Functional'),
    (3, 'Saltele yoga', 'Domyos', '2024-07-14', 'Functional'),
    (1, 'Aparat pentru tractiuni', 'Technogym', '2022-08-30', 'Necesita reparatie');

SELECT *
FROM Echipament;


INSERT INTO Mentenanta_Echipament(id_echipament, data_revizie, cost, descriere)
VALUES
    (1, '2024-06-15', 250.00, 'Revizie periodica pentru banda de alergare'),
    (2, '2024-08-20', 150.00, 'Verificare si reglare bicicleta stationara'),
    (3, '2024-04-10', 100.00, 'Ungere si verificare aparat pentru extensii'),
    (4, '2024-12-05', 50.00, 'Verificare stare gantere'),
    (5, '2025-01-12', 80.00, 'Inlocuire saltele deteriorate'),
    (6, '2025-03-18', 300.00, 'Reparatie bicicleta eliptica'),
    (7, '2025-05-22', 120.00, 'Verificare banca pentru impins'),
    (8, '2025-07-09', 200.00, 'Schimbare bara olimpica'),
    (9, '2025-09-14', 60.00, 'Verificare saltele yoga'),
    (10, '2026-02-11', 450.00, 'Schimbare aparat pentru tractiuni');

SELECT *
FROM Mentenanta_Echipament;


--1)Numele membrilor care au abonamente active , si data cand expira acestea
SELECT m.nume, m.prenume,t.denumire AS tip_abonament,a.data_sfarsit
FROM Membru m
INNER JOIN Abonament_Membru a
    ON m.id_membru = a.id_membru
INNER JOIN Tip_Abonament t
    ON a.id_tip_abonament = t.id_tip_abonament
WHERE a.status = 'Activ'
ORDER BY a.data_sfarsit;

--2)Membrii care au abonamentele expirate
SELECT m.nume,m.prenume,t.denumire AS Tip_Abonament,a.data_sfarsit
FROM Membru m
INNER JOIN Abonament_Membru a
ON m.id_membru = a.id_membru
INNER JOIN Tip_Abonament t
ON a.id_tip_abonament= t.id_tip_abonament
WHERE a.status = 'Expirat'
ORDER BY a.data_inceput DESC;

--3)Echipamente care necesita interventii
SELECT e.denumire , e.marca,e.stare,z.denumire as zona
FROM Echipament e
INNER JOIN Zona z
ON e.id_zona = z.id_zona
WHERE e.stare = 'Defect'
ORDER BY e.denumire

--4)Antrenorii cu salariu mai mare de 4500 lei
SELECT nume,prenume,specializare,salariu
FROM Antrenor
WHERE salariu > 4500
ORDER BY salariu DESC;

--5)Membrii inscrisi la calsele de fitness M:N
SELECT m.id_membru ,m.nume,m.prenume,c.id_clasa,c.denumire AS clasa , p.data_ora_start,i.status_prezenta
FROM Inscriere_Clasa i
INNER JOIN Membru m
ON i.id_membru = m.id_membru
INNER JOIN Programare_Clasa p
ON p.id_programare = i.id_programare
INNER JOIN Clasa_Grup c
ON p.id_clasa = c.id_clasa
ORDER BY c.id_clasa;

--6)Clasele la care s au inscris cel putin 2 membrii M:N
SELECT c.denumire AS clasa, COUNT(i.id_membru) AS numar_inscrieri
FROM Clasa_Grup c
INNER JOIN Programare_Clasa p
ON c.id_clasa = p.id_clasa
INNER JOIN Inscriere_Clasa i
ON i.id_programare = p.id_programare
GROUP BY c.id_clasa,c.denumire
HAVING COUNT(i.id_membru) >= 2
ORDER BY numar_inscrieri DESC;

--7) Clasele programate si numarul de antrenori diferiti
SELECT c.denumire AS clasa,COUNT(DISTINCT a.id_antrenor) AS numar_antrenori
FROM Clasa_Grup c
INNER JOIN Programare_Clasa p
ON c.id_clasa = p.id_clasa
INNER JOIN Antrenor a
ON p.id_antrenor = a.id_antrenor
GROUP BY c.id_clasa, c.denumire
ORDER BY numar_antrenori DESC;

--8)Totalul platilor pentru fiecare tip de abonament
SELECT t.denumire AS tip_abonament, COUNT(p.id_plata) as numar_plati,SUM(p.suma) AS total_incasat
FROM Tip_Abonament t
INNER JOIN Abonament_Membru a
ON t.id_tip_abonament = a.id_tip_abonament
INNER JOIN Plata p
ON p.id_abonament = a.id_abonament
GROUP BY t.id_tip_abonament,t.denumire
ORDER BY total_incasat DESC;


--9)Membrii care au anulat inscrieri la clase
SELECT DISTINCT m.id_membru, m.nume,m.prenume
FROM Membru m
INNER JOIN Inscriere_Clasa i
ON m.id_membru = i.id_membru
WHERE i.status_prezenta = 'Anulat'
ORDER BY m.nume,m.prenume

--10)Antrenorii care au sustinut deja cel putin 2 clase diferite
SELECT  a.id_antrenor,a.nume,a.prenume,COUNT(DISTINCT c.id_clasa) AS numar_clase
FROM Antrenor a
INNER JOIN Programare_Clasa p
ON a.id_antrenor = p.id_antrenor
INNER JOIN Clasa_Grup c
ON c.id_clasa = p.id_clasa
WHERE p.data_ora_start < GETDATE()
GROUP BY a.id_antrenor,a.nume,a.prenume
HAVING COUNT(DISTINCT c.id_clasa) >= 2
ORDER BY numar_clase DESC;


