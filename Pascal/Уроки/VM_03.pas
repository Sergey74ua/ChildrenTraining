program VM_03;
var X, N : int64;

begin
  read(X);
  N := 0;
  
  while X > 0 do
  begin
    X := X div 10;
    N := N + 1;
  end;
  
  write(N); //123456789 = 9
end.