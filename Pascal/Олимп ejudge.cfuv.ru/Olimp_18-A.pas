program p;

var
    N, K, M, i, j: longint;
    arr: array of longint;

begin
    read(N, K);
    
    setLength(arr, N);
    for i := 0 to N - 1 do
        read(arr[i]);
    
    for j := 0 to K - 1 do
    begin
        M := 0;
        for i := 0 to N - 1 do
        begin
            if arr[i] > M then
                M := arr[i];
        end;
        
        for i := 0 to N - 1 do
            arr[i] := M - arr[i];
    end;
    
    for i := 0 to N - 1 do
        write(arr[i], ' ');
end.