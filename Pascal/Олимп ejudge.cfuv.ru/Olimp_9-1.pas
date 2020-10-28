program p;

var N, X, i : integer;

begin
  read(N);
  X := 0;
  
  for i := 1 to trunc(sqrt(N)) do
    if N mod i = 0 then
      X := X + 1;
  write(X);
end.