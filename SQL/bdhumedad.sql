DROP DATABASE IF EXISTS bdhumedad;
CREATE DATABASE IF NOT EXISTS bdhumedad;

USE bdhumedad;
DROP TABLE IF EXISTS THumedad;
CREATE TABLE IF NOT EXISTS THumedad
(
	id_empresa		int(3) NOT NULL PRIMARY KEY AUTO_INCREMENT,
    humedadBits		varchar(20) NOT NULL,
    humedadAnalog	varchar(20) NOT NULL
);
select * from THumedad;
insert into THumedad (humedadBits, humedadAnalog) values("1023", "100%");

-- truncate table THumedad;