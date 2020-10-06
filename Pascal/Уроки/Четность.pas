Program Chetnost;
var a, b : integer;
  s : string;
label l;
Begin
  l: s := '';
  write('Ведите число ');
  readln(a);
  b := a mod 2;
  if b = 1 then s := 'не';
  writeln('Число ', a, ' - ', s, 'четное');
  writeln;
  goto l;
end.