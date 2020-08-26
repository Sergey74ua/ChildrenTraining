program p;
var
  dig : array [1..32] of integer;
  i, j, x, n, tmp : integer;

Begin
    readln(x);
    
    n := 0;
    while x > 0 do
    begin
      dig[n+1] := x mod 10;
      x := x div 10;
      n := n + 1;
    end;
    
    for i := 1 to n-1 do
    begin
      for j := i + 1 to n do
      begin
        if dig[j] > dig[i] then
        begin
          tmp := dig[i];
          dig[i] := dig[j];
          dig[j] := tmp;
        end;
      end;
    end;

    for i := 1 to n do
    begin
      x := x * 10 + dig[i];
    end;
    
    write(x);
end.