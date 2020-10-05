program p;
var A, B, N, X : integer;
begin
  read(A, B, N);
  if B >= A then
    X := A + (N-1) * (B - A)
  else
    X := A - (N-1) * (A - B);
  write(X);
end.