Program Olimpiada5;
var N, s :integer;
    arr :array[1..20] of integer;
begin
  Write ('Введите число данных до 20: ');
  Readln (N);
  Writeln ('Введите ', N, ' данных');
  for var i := 1 to N do
    begin
    Readln (arr[i]);
    if arr[i] > i then s := s + arr[i];
    end;
  Writeln ('Сумма особых элементов: ', s); 
end.