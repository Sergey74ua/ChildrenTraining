program p;

var N, X : integer;

begin
  read(N);
  X := N;
  
  while true do
  begin
  if (X mod N = 1) and (X mod (N + 1) = 1) and (X mod (N + 2) = 0) then
    break
  else
    X := X + 1;
  end;
  
  write(X);
end.