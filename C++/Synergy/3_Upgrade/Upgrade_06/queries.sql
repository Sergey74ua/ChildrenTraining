CREATE TABLE `classroom` (
  `id` INT PRIMARY KEY AUTO_INCREMENT,
  `class` CHAR(3),
  `student` CHAR(60)
);

INSERT `classroom` (`class`, `student`) VALUES
  ('11А', 'Иванов Вова'),
  ('11Б', 'Петрова Маша'),
  ('11А', 'Воровьев Вася'),
  ('11Б', 'Соколова Света'),
  ('11А', 'Кукушкина Лена'),
  ('11Б', 'Соловьев Иван');

CREATE TABLE `classroom_teacher` (
  `class` CHAR(3) PRIMARY KEY,
  `teacher` CHAR(60)
);

INSERT `classroom_teacher` (`class`, `teacher`) VALUES
  ('11А', 'Столярова М.И.'),
  ('11Б', 'Плотницкий И.В.');

SELECT `class`, COUNT(`student`) AS 'count' FROM `classroom`
  GROUP BY `class`;

SELECT '';

SELECT `teacher`, `classroom_teacher`.`class`, `student`
  FROM `classroom_teacher`
  JOIN `classroom`
  ON `classroom_teacher`.`class`=`classroom`.`class`;


/*5. Оператор UNION не сможет объединить таблицы с разным количеством
столбцов: в `classroom` - 3, а в `classroom_teacher` - 2.*/