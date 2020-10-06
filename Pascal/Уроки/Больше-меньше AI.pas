Program BM AI;
Label l;
var x, a, b, i, r: Integer;

Begin
  a := 0;
  b := 1000;
  writeln('Загадай число от 0 до 1000');
  
  l: i := i+1;
  x := (b-a) div 2 + a;
  write('Попытка №', i, '. Если ваше число меньше "', x, '" то нажмите - 0, если больше - 1, а если это оно - любое другое число.  ');
  read(r);
  if r = 0 then
    begin
      b := x;
      goto l
    end
  else if r = 1 then
    begin
      a := x;
      goto l
    end
  else writeln('Число "', x, '" угадано c ', i, ' попыток.');  
end.