program A;
var X, Y, step, min, temp : integer;
begin
read(X);

step := 0;
while true do
begin
  step := step + 1;
  
  Y := X + step;
  min := trunc(sqrt(Y));
  temp := 3;
  while temp < min do
  begin
    if (Y mod temp) = 0 then
      break
    else
      temp := temp + 2;
  end;
  
  Y := X - step;
  min := trunc(sqrt(Y));
  temp := 3;
  while temp < min do
  begin
    if (Y mod temp) = 0 then
      break
    else
      temp := temp + 2;
  end;
  
end;

write(Y);
end.