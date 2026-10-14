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
