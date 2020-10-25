program p;

var N, i : integer;
  X, X1, X2, X3 : int64;

begin
  readln(N);
  
  if N < 4 then
    X := 1
  else
    begin
      X1 := 1;
      X2 := 1;
      X3 := 1;
      
      for i := 4 to N do
        begin
          X := X1 + X2 + X3;
          X3 := X2;
          X2 := X1;
          X1 := X;
        end;
    end;
  
  write(X);
end.