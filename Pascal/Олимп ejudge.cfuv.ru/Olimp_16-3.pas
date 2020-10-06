program p;

var
    L, R, S, i, j, temp, test : integer;

begin
    read(L, R);
    S := 0;
    
    for i := L to R do
    begin
      temp := i;
        for j := 1 to 10 do
        begin
            test := temp mod 10;
            if test = 1 then
              begin
                S := S + 1;
                break;
              end
            else if temp > 0 then
              temp := temp div 10
            else
              break;
        end;
     end;
     
    write(S);
end.