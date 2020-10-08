program VM_01;
var V, M, D : integer;

begin
  V := 1000;
  M := 1;
  D := 0;
  
  while V > 0 do
  begin
    V := V - M;
    M := M * 2;
    D := D + 1;
  end;
  
  write(D); // 10
end.