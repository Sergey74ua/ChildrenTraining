program p;

var N, count, maxCount, num, numBack, i : integer;

begin
  read(N);
  count := 0;
  numBack := 0;
  
  for i := 0 to N-1 do
  begin
    read(num);
    
    if num >= numBack then
    begin
      numBack := num;
      count := count + 1;
      if count > maxCount then
        maxCount := count;
    end
    
    else
    begin
      count := 1;
      numBack := num;
    end;
  end;
  
  write(maxCount);
end.