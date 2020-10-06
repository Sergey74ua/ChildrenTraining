program p;
var A, B, N: longint;
begin
  read(A, B, N);
  write(A - (A - B) * (N - 1));
end.