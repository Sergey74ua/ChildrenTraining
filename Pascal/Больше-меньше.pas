Program BM;
var x, a, i: Integer;

Begin
  
  Randomize;
  x := random(0, 1000);
  
  writeln('Угадай число от 1 до 1000');
  i := 0;
  
  Repeat
    read(a);
    if a > x then
      writeln('Ваше число больше')
    else if a<x then
      writeln('Ваше число меньше');
    i := i+1;
  until a=x;
  
  writeln('Вы угадали, c ', i, ' попыток, это действительно ', a);
  
end.