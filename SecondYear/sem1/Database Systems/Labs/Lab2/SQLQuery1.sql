CREATE DATABASE SalaFitnessDB;

USE SalaFitnessDB;
GO

CREATE TABLE Tip_Abonament (
    id_tip_abonament INT IDENTITY(1,1) PRIMARY KEY,
    denumire VARCHAR(50) NOT NULL UNIQUE,
    pret DECIMAL(8,2) NOT NULL,
    durata_zile INT NOT NULL,
    CONSTRAINT CK_TipAbonament_Pret CHECK (pret > 0),
    CONSTRAINT CK_TipAbonament_Durata CHECK (durata_zile > 0)
);

CREATE TABLE Membru (
    id_membru INT IDENTITY(1,1) PRIMARY KEY,
    nume VARCHAR(50) NOT NULL,
    prenume VARCHAR(50) NOT NULL,
    telefon VARCHAR(50) NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE,
    data_nasterii DATE NOT NULL,
    data_inregistrarii DATE NOT NULL DEFAULT CAST(GETDATE() AS DATE)
);

CREATE TABLE Antrenor (
    id_antrenor INT IDENTITY(1,1) PRIMARY KEY,
    nume VARCHAR(50) NOT NULL,
    prenume VARCHAR(50) NOT NULL,
    specializare VARCHAR(50) NOT NULL,
    telefon VARCHAR(15) NOT NULL,
    salariu DECIMAL(8,2) NOT NULL,
    data_angajarii DATE NOT NULL,
    CONSTRAINT CK_Antrenor_Salariu CHECK (salariu > 0)
);

CREATE TABLE Clasa_Grup (
    id_clasa INT IDENTITY(1,1) PRIMARY KEY,
    denumire VARCHAR(50) NOT NULL,
    descriere VARCHAR(255) NOT NULL,
    nivel_dificultate VARCHAR(20) NOT NULL
);

CREATE TABLE Zona (
    id_zona INT IDENTITY(1,1) PRIMARY KEY,
    denumire VARCHAR(50) NOT NULL UNIQUE,
    descriere VARCHAR(255) NOT NULL,
    capacitate_maxima INT NOT NULL,
    CONSTRAINT CK_Zona_Capacitate CHECK (capacitate_maxima > 0)
);

CREATE TABLE Abonament_Membru (
    id_abonament INT IDENTITY(1,1) PRIMARY KEY,
    id_tip_abonament INT NOT NULL,
    id_membru INT NOT NULL,
    pret_platit DECIMAL(8,2) NOT NULL,
    data_inceput DATE NOT NULL,
    data_sfarsit DATE NOT NULL,
    status VARCHAR(20) NOT NULL,
    CONSTRAINT FK_Abonament_Tip FOREIGN KEY (id_tip_abonament) REFERENCES Tip_Abonament(id_tip_abonament),
    CONSTRAINT FK_Abonament_Membru FOREIGN KEY (id_membru) REFERENCES Membru(id_membru),
    CONSTRAINT CK_Abonament_Perioada CHECK (data_sfarsit >= data_inceput),
    CONSTRAINT CK_Abonament_Pret CHECK (pret_platit >= 0),
    CONSTRAINT CK_Abonament_Status CHECK (status IN ('Activ', 'Expirat', 'Anulat'))
);

CREATE TABLE Plata (
    id_plata INT IDENTITY(1,1) PRIMARY KEY,
    id_abonament INT NOT NULL,
    suma DECIMAL(8,2) NOT NULL,
    data_plata DATETIME NOT NULL DEFAULT GETDATE(),
    metoda_plata VARCHAR(20) NOT NULL,
    CONSTRAINT FK_Plata_Abonament FOREIGN KEY (id_abonament) REFERENCES Abonament_Membru(id_abonament),
    CONSTRAINT CK_Plata_Suma CHECK (suma > 0)
);

CREATE TABLE Programare_Clasa (
    id_programare INT IDENTITY(1,1) PRIMARY KEY,
    id_clasa INT NOT NULL,
    id_antrenor INT NOT NULL,
    id_zona INT NOT NULL,
    data_ora_start DATETIME NOT NULL,
    durata_minute INT NOT NULL,
    CONSTRAINT FK_Prog_Clasa FOREIGN KEY (id_clasa) REFERENCES Clasa_Grup(id_clasa),
    CONSTRAINT FK_Prog_Antrenor FOREIGN KEY (id_antrenor) REFERENCES Antrenor(id_antrenor),
    CONSTRAINT FK_Prog_Zona FOREIGN KEY (id_zona) REFERENCES Zona(id_zona),
    CONSTRAINT CK_Prog_Durata CHECK (durata_minute > 0),
    CONSTRAINT UQ_Antrenor_DataOraStart UNIQUE (id_antrenor, data_ora_start),
    CONSTRAINT UQ_Zona_DataOraStart UNIQUE (id_zona, data_ora_start)
);

CREATE TABLE Inscriere_Clasa (
    id_programare INT NOT NULL,
    id_membru INT NOT NULL,
    data_inscrierii DATETIME NOT NULL DEFAULT GETDATE(),
    status_prezenta VARCHAR(20) NOT NULL,
    CONSTRAINT PK_Inscriere PRIMARY KEY (id_programare, id_membru),
    CONSTRAINT FK_Inscriere_Programare FOREIGN KEY (id_programare) REFERENCES Programare_Clasa(id_programare),
    CONSTRAINT FK_Inscriere_Membru FOREIGN KEY (id_membru) REFERENCES Membru(id_membru),
    CONSTRAINT CK_Inscriere_Status CHECK (status_prezenta IN ('Inscris', 'Prezent', 'Absent', 'Anulat'))
);

CREATE TABLE Echipament (
    id_echipament INT IDENTITY(1,1) PRIMARY KEY,
    id_zona INT NOT NULL,
    denumire VARCHAR(50) NOT NULL,
    marca VARCHAR(50) NOT NULL,
    data_achizitie DATE NOT NULL,
    stare VARCHAR(20) NOT NULL,
    CONSTRAINT FK_Echipament_Zona
    FOREIGN KEY (id_zona) REFERENCES Zona(id_zona),
    CONSTRAINT CK_Echipament_Status CHECK (stare IN ('Functional', 'Defect'))
);

CREATE TABLE Mentenanta_Echipament (
    id_mentenanta INT IDENTITY(1,1) PRIMARY KEY,
    id_echipament INT NOT NULL,
    data_revizie DATE NOT NULL,
    cost DECIMAL(8,2) NOT NULL,
    descriere VARCHAR(255) NOT NULL,
    CONSTRAINT FK_Mentenanta_Echipament FOREIGN KEY (id_echipament) REFERENCES Echipament(id_echipament),
    CONSTRAINT CK_Mentenanta_Cost CHECK (cost >= 0)
);


