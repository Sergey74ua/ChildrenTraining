program p;

var
    N, i, j: word;

begin
    read(N);
    
    for i := 0 to N div 2 do
    begin
        
        for j := N div 2 downto 0 do
        begin
            if i < j then
                write(' ')
            else
                write('*');
        end;
        
        for j := 1 to N div 2 do
        begin
            if i < j then
                write(' ')
            else
                write('*');
        end;
        
        writeln();
    end;
    
    for i := 1 to N div 2 do
    begin
        
        for j := 0 to N div 2 do
        begin
            if i > j then
                write(' ')
            else
                write('*');
        end;
        
        for j := N div 2 - 1 downto 0 do
        begin
            if i > j then
                write(' ')
            else
                write('*');
        end;
        
        writeln();
    end;
end.