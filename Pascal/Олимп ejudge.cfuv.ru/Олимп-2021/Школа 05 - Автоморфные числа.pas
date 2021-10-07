program p;

var
  m, n, i, r, t: integer;
  s: string;

begin
  Writeln('Введите m, n:');
  Readln(m, n);
  t := 0;
  Writeln('Автоморфные числа:');
  For i := m to n do
  begin
    s := IntToStr(Sqr(i));
    r := StrToInt(
      s.SubString(
        s.Length - Length(
          IntToStr(i)
        )
      )
    );
    if i = r then
    begin
      Writeln(i);
      t := 1;
    end;
  end;
  if t = 0 then
    Writeln(0);
end.