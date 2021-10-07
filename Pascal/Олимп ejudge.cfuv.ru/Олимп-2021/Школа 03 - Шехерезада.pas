program p;

var N, S: integer;

begin
  S := 0;
  write('Введите количество сказок: ');
  readln(N);
  
  while N > 0 do
  begin
    if N mod 3 > 0 then
    begin
      N := N - 5;
      S := S + 1;
    end
    else
    begin
      S := S + N div 3;
      break
    end
  end;
	
  writeln('Максимальное число дней: ', S);
end.