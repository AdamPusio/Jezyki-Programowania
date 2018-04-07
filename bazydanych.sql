CREATE TABLE pracownik (
id            serial            PRIMARY KEY,
imie          varchar(255),
nazwisko      varchar(255),
num_tel       varchar(9),
kod_pocztowy  varchar(6),
miejscowosc   varchar(255),
ulica         varchar(255),
wynagrodzenie integer
);

CREATE TABLE klient (
id            serial            PRIMARY KEY,
imie          varchar(255),
nazwisko      varchar(255),
num_tel       varchar(9),
kod_pocztowy  varchar(6),
miejscowosc   varchar(255),
ulica         varchar(255)
);

CREATE TABLE sprzet (
numer_seryjny varchar(255)             PRIMARY KEY,
id_klient     serial,
wartosc       smallint,
rodzaj        varchar(255),
marka         varchar(255),
model         varchar(255),
CONSTRAINT id_klient_FK FOREIGN KEY(id_klient)
	   REFERENCES klient(id) 
	   ON UPDATE CASCADE ON DELETE SET NULL
);

CREATE TABLE naprawa (
id            serial            PRIMARY KEY,
numer_seryjny varchar(255),
tresc         varchar(255),
koszt         smallint,
cena          NUMERIC(7,2),
data_od       date,
data_do       date,
CONSTRAINT numer_seryjny_FK FOREIGN KEY(numer_seryjny)
	   REFERENCES sprzet(numer_seryjny) 
	   ON UPDATE CASCADE ON DELETE SET NULL
);

CREATE TABLE reklamacja (
id            serial            PRIMARY KEY,
id_klient     serial,
data          date,
tresc         varchar(255),
status        varchar(255),
CONSTRAINT id_klient_FK FOREIGN KEY(id_klient)
	   REFERENCES klient(id) 
	   ON UPDATE CASCADE ON DELETE SET NULL
);

CREATE TABLE pracownik_naprawa (
id            serial            PRIMARY KEY,
id_pracownik  serial,
id_naprawa    serial,
CONSTRAINT pracownik_FK FOREIGN KEY(id_pracownik)
	   REFERENCES pracownik(id) 
	   ON UPDATE CASCADE ON DELETE CASCADE,
CONSTRAINT naprawa_FK FOREIGN KEY(id_naprawa)
	   REFERENCES naprawa(id) 
	   ON UPDATE CASCADE ON DELETE CASCADE
);
