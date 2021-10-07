program p;

var N, K, M, S, ost: integer;

begin
  write('Введите N, K, M: ');
  readln(N, K, M);
  
  ost := N mod (K + M);
  if ost = 0 then
    S := (N div (K + M)) * 2
  else if ost > K then
    S := (N div (K + M)) * 2 + 2
  else
    S := (N div (K + M)) * 2 + 1;
  
  writeln('Необходимо машин: ', S);
end.