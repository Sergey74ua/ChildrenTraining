program p;
var N, P1, H1, P2, H2, T, min, max, step, i : integer;
  M : array of longint;
begin
  read(N);
  read(P1, H1);
  read(P2, H2);
  read(T);
  setLength(M, T);
  for i := 0 to T-1 do
    readln(M[i]);
  
  step := (H2 - H1) div (P2 - P1);
  if step >= 0 then
  begin
    min := H1 - P1 * step;
    max := H1 + (N - P1) * step;
  end
  else
  begin
    max := H1 - P1 * step;
    min := H1 + (N - P1) * step;
  end;
  
  for i := 0 to T-1 do
    if (M[i] >= min) and (M[i] <= max) and (M[i] mod step = 0) then
      writeln('YES')
    else
      writeln('NO');
end.