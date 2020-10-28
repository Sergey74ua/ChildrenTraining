program p;

var A, B, Ax, Bx, X, Xx, i : int64;

begin
  read(A, B);
  Ax := 0;
  Bx := 0;
  
  while A > 0 do
  begin
    Ax := Ax * 10 + (A mod 10);
    A := A div 10;
  end;
  
  while B > 0 do
  begin
    Bx := Bx * 10 + (B mod 10);
    B := B div 10;
  end;
  
  Xx := Ax + Bx;
  
  while Xx > 0 do
  begin
    X := X * 10 + (Xx mod 10);
    Xx := Xx div 10;
  end;
  
  write(X);
end.