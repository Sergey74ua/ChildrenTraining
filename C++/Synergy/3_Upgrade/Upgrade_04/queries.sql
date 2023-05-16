#CREATE DATABASE [IF NOT EXISTS] `MyDB`;
#USE `MyDB`;


CREATE TABLE `playlist` (
  `id` INT PRIMARY KEY AUTO_INCREMENT,
  `title` CHAR(64),
  `artist` CHAR(64)
);

INSERT `playlist` (`title`, `artist`) VALUES
  ('Queen', 'Bohemian Rhapsody'),
  ('Michael Jackson', 'Billie Jean'),
  ('The Beatles', 'Hey Jude'),
  ('Madonna', 'Like a Prayer'),
  ('Beyonce', 'Crazy in Love'),
  ('Prince', 'Purple Rain'),
  ('Whitney Houston', 'I Will Always Love You'),
  ('Elvis Presley', 'Jailhouse Rock'),
  ('Bob Marley', 'No Woman, No Cry'),
  ('Adele', 'Someone Like You');

SELECT `title` AS 'Название', `artist` AS 'Исполнитель'
  FROM `playlist`;