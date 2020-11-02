program p;

var a, b, c, ac, cb, n : int64;

begin
  readln(a, b, c);
  ac := a div c * c + c;
  cb := b div c * c;
  
  if ac > cb then
    begin
      if (b - a) mod 2 = 0 then
        n := (b - a) div 2
      else
        n := (b - a) div 2 + 1;
      end
  
  else if ac = cb then
    n := (ac - a) div 2 + 1 + (b - cb) div 2
  
  else
  begin
    n := (ac - a) div 2 + 1;
    if c mod 2 = 0 then
      n := n + ((cb - ac) div c) * (c div 2)
    else
      n := n + ((cb - ac) div c) * (c div 2 + 1);
    n := n + (b - cb) div 2;
  end;
  
  writeln(n);
end.