program p;
var N, r, S, i : byte;
begin
  S := 0;
  readln(N);
  for i := 1 to N do
  begin
    readln(r);
    if r > 0 then
      S := S + 1;
  end;
  write(S);
end.