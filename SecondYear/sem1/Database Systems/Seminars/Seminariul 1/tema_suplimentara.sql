CREATE DATABASE ParcDistractii;
GO
USE ParcDistractii;

CREATE TABLE Categorii
(
	id_c INT PRIMARY KEY IDENTITY(1,1),
	nume_c VARCHAR(100) NOT NULL
);

CREATE TABLE Vizitatori
(
	id_v INT PRIMARY KEY IDENTITY(1,1),
	nume_v VARCHAR(100) NOT NULL,
	email VARCHAR(100) UNIQUE,
	id_c INT NOT NULL,
	CONSTRAINT fk_Vizitatori_Categorii FOREIGN KEY(id_c) REFERENCES Categorii(id_c)
)

CREATE TABLE Sectiuni
(
	id_s INT PRIMARY KEY IDENTITY(1,1),
	nume_s VARCHAR(100) NOT NULL,
	descriere VARCHAR(100)
)

CREATE TABLE Atractii
(
	id_a INT PRIMARY KEY IDENTITY(1,1),
	nume_a VARCHAR(50) NOT NULL,
	descriere VARCHAR(50),
	varsta_minima INT NOT NULL,
	id_s INT NOT NULL,
	CONSTRAINT  fk_Abstractii_Sectiuni FOREIGN KEY(id_s) REFERENCES Sectiuni(id_s)
)


CREATE TABLE Note
(
	id_v INT NOT NULL,
	CONSTRAINT fk_Note_Vizitatori FOREIGN KEY(id_v) REFERENCES Vizitatori(id_v),
	id_a INT NOT NULL,
	CONSTRAINT fk_Note_Atractii FOREIGN KEY(id_a) REFERENCES Atractii(id_a),
	CONSTRAINT pk_Note PRIMARY KEY(id_v,id_a),
	nota DECIMAL(4,2),
	CONSTRAINT ck_nota CHECK (nota >= 1 AND nota <= 10)
)


INSERT INTO Categorii(nume_c)
VALUES
('copii'),
('adulti'),
('pensionari'),
('studenti'),
('angajati'),
('turisti'),
('familii')


SELECT *
FROM Categorii

INSERT INTO Vizitatori(nume_v,email,id_c)
VALUES
('Stefania','stefania@email.com',4),
('Octavian','octavian@email.com',1),
('George','george@email.com',2),
('Bobita','bobita@email.com',3),
('Ovidiu','ovidiu@email.com',5),
('Tavi','tavi@email.com',6),
('Ana','ana@email.com',7)

SELECT *
FROM Vizitatori

INSERT INTO Sectiuni(nume_s,descriere)
VALUES
('Copii','Loc de joaca pt copii'),
('Horror','Loc horror'),
('Nature','Loc in aer liber'),
('Acvatica','Loc cu pesti'),
('Parkour','Loc pt parkour'),
('Pool','Loc cu piscina'),
('Fotbal','Loc de fotbal')

SELECT *
FROM Sectiuni

INSERT INTO Atractii (nume_a,descriere,varsta_minima,id_s)
VALUES
('Castel','un castel magic','3',1),
('Turn','un castel magic','12',2),
('Carusel','un castel magic','4',3),
('Tobogan acvatic','un castel magic','1',4),
('Roata panoramica','un castel magic','2',5),
('Caleasca','un castel magic','19',6),
('Trenulet','un castel magic','13',7)

INSERT INTO Note(id_v,id_a,nota)
VALUES
(1,2,10),
(2,2,4),
(3,1,7),
(4,3,8),
(5,4,9),
(6,5,6),
(7,5,2);