program p;
var N : integer;

begin
  read(N);
  while N > trunc(sqrt(N)) * trunc(sqrt(N)) do
    N := N + 1;
  write(N);
end.