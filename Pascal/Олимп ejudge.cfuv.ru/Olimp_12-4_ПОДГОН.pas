program p;

var N, X : integer;

begin
  read(N);
  
  X := N - N mod 5;

  write(X);
end.