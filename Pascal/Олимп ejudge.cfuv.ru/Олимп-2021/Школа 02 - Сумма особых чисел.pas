program p;

var N, S, A, i: integer;

begin
  write('Введите количество элементов: ');
  readln(N);
  writeln('Введите элементы:');
  S := 0;
  
  for i := 1 to N do
  begin
    read(A);
    if A > i then
      S := S + A;
  end;
	
  writeln('Сумма особых элементов: ', S);
end.