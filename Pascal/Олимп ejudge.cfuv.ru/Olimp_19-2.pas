program p;
var Z, W : string;
    i : char;
    X : byte;

begin
  readln(Z);
  readln(W);
  X := 0;
  
  for i := 'a' to 'z' do
    if (pos(i, Z) > 0) and (pos(i, W) > 0) then
      X := X + 1;
  
  write(X);  
end.