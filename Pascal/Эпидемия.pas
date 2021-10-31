program p;
var nas, boln, dead, x : int64;
begin
  read(nas);
  boln := 1;
  x := 0;
  
  while nas > 0 do
  begin
    boln := boln * 2;
    dead := boln * 4 div 100;
    boln := boln - dead - boln * 24 div 100;
    nas := nas - dead;
    x := x + 1;
    write(nas, ' ');
  end;
  
  writeln();
  write(x);
end.

// 22 000 = 30
// 2 300 000 = 42
// 142 000 000 = 54
// 8 000 000 000 = 65