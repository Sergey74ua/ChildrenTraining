program p;
var x, i : integer;
  str, str1, str2 : string;
begin
  read(str);
  for i := 1 to length(str) do
    if str[i] = '*' then
    begin
      str1 := copy(str, 1, i-1);
      str2 := copy(str, i+1, length(str));
    end;
    for i := 0 to 9 do
    begin
      str := str1 + i + str2;
      x := strToInt(str);
      if (x mod 72) = 0 then
      begin
        write(x);
        break;
      end;
    end;
end.