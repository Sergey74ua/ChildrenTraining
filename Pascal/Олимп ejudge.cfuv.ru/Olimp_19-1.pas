program p;
var N, kratn : integer;

begin
  read(N);
  kratn := N mod 4;
  
  if kratn = 2 then
    write(N + 1)
  else if kratn = 3 then
    write(0)
  else if kratn = 0 then
    write(-N)
  else if kratn = 1 then
    write(1)
  else
    write(1);  
end.