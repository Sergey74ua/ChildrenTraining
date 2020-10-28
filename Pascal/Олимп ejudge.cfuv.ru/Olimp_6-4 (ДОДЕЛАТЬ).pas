program p;

var N, endN, X, i, j, temp : integer;

begin
  read(N);
  X := 0;
  endN := trunc(sqrt(N));
  
  for i := 2 to endN do
  begin
    temp := 0;
    if N mod i = 0 then
    begin
      for j := 1 to i do
        if i mod j = 0 then
          temp := temp + 1;
        if temp = 2 then
        begin
          X := X + 1;
          temp := 0;
        end;        
    end;
  end;
  
  write(X);
end.