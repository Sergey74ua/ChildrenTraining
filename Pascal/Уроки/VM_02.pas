program VM_02;
var V, i : integer;

begin
  V := 1;
  
  for i := 1 to 15 do
  begin
    V := V * 2;
  end;
  
  write(V); // 32768
end.