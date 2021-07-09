program p;

var N, M, i, j, temp, max: integer;
    arr : array of integer;

begin
  read(N, M);
  SetLength(arr, N);
  
  for i := 0 to N-1 do
    read(arr[i]);
  
  max := 1;
  temp := 1;
  for i := 0 to N-1 do
    for j := i+1 to N-1 do
      if arr[i] = arr[j] then
      begin
        temp := temp+1;
        if temp > max then
          begin
            max := temp;
            temp := 1;
          end;
      end;
  
  if max >= M then
    write(0)
  else
    write(M - max);
end.