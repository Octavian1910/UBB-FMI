/*Creare bazei de date*/
CREATE DATABASE Blog226;
GO
USE Blog226;

/*Crearea unui tabel*/
CREATE TABLE Utilizatori
( cod_u INT PRIMARY KEY IDENTITY(1,1),
  nume NVARCHAR(100) NOT NULL,
  email VARCHAR(100) UNIQUE,
  parola VARCHAR(200),
  data_nasterii DATE
)

CREATE TABLE Postari
( cod_p INT PRIMARY KEY IDENTITY, /* PRIMARY KEY IDENTITY <==> (1,1)*/
  titlu NVARCHAR(200),
  continut NVARCHAR(MAX),
  data_publicarii DATETIME,
  codu_u INT FOREIGN KEY REFERENCES Utilizatori(cod_u)
)

CREATE TABLE Comentarii
(
 cod_c INT PRIMARY KEY IDENTITY,
 continut NVARCHAR(20),
 data_publicarii DATETIME,
 cod_u INT FOREIGN KEY REFERENCES Utilizatori(cod_u),
 cod_p INT FOREIGN KEY REFERENCES Postari(cod_p)
)

CREATE TABLE CuvinteCheie
(
 cod_cc INT PRIMARY KEY IDENTITY,
 nume VARCHAR(100)
);

/* tabelul de legatura */
CREATE TABLE PostariCuvinteCheie
(cod_p INT FOREIGN KEY REFERENCES Postari(cod_p),
 cod_cc INT FOREIGN KEY REFERENCES CuvinteCheie(cod_cc),
 CONSTRAINT pb_PostariCuvinteCheie Primary Key(cod_p,cod_cc)
)