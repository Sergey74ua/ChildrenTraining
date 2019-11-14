Program Polindrom;
var a, aZerk, temp : integer;
label start;
Begin
start:
  write('Введите число: ');
  readln(a);
  while a <> aZerk do
  begin
    a := a+1;
    aZerk := 0;
    temp := a;
    while temp > 0 do
    begin
      aZerk := aZerk*10 + temp mod 10;
      temp := temp div 10;
    end;
  end;
  writeln('Ближайший больший полиндром: ', aZerk);
  goto start;
end.
