program p;

var N, X, X1, X2, X3, i : int64;

begin
  readln(N);
  X1 := 1;
  X2 := 1;
  X3 := 1;
  
  if N < 4 then
    X := 1
  else
    for i := 4 to N do
    begin
      X := X1 + X2 + X3;
      X3 := X2;
      X2 := X1;
      X1 := X;
    end;
  write(X);
end.