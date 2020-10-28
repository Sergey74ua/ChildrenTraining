program p;
var K, i, z : integer;
    V : double;
begin
  read(K);
  V := 0;
  z := 1;
  
  for i := 1 to K-1 do
  begin
    V := V + 4 / (i * 2 + 1) * z;
    z := z * -1;
  end;
  
  V := 4 - V;
  
  write(V:0:9);
end.