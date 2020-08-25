program autobiografija (output);
  var c : array[1..14] of string[60];
      i : integer;
begin
c[ 1]:='program autobiografija (output);                            ';
c[ 2]:='  var c : array[1..14] of string[60];                       ';
c[ 3]:='      i : integer;                                          ';
c[ 4]:='begin                                                       ';
c[ 5]:='for i := 1  to  4 do writeln(c[i]);                         ';
c[ 6]:='for i := 1  to 13 do writeln(c[14,1],c[14,2],i:2,c[14,5],   ';
c[ 7]:='           c[14,6],c[14,7],c[14,8],c[i],c[14,8],c[14,9]);   ';
c[ 8]:='for i := 1  to  8 do write(c[14,i]);                        ';
c[ 9]:='for i := 1  to  8 do write(c[14,i]);                        ';
c[10]:='for i := 8  to 60 do write(c[14,i]);                        ';
c[11]:='writeln(c[14,8],c[14,9]);                                   ';
c[12]:='for i := 5  to 13 do writeln(c[i]);                         ';
c[13]:='end.                                                        ';
c[14]:='c[14]:='';                                                  ';
for i := 1  to  4 do writeln(c[i]);
for i := 1  to 13 do writeln(c[14,1],c[14,2],i:2,c[14,5],
           c[14,6],c[14,7],c[14,8],c[i],c[14,8],c[14,9]);
for i := 1  to  8 do write(c[14,i]);
for i := 1  to  8 do write(c[14,i]);
for i := 8  to 60 do write(c[14,i]);
writeln(c[14,8],c[14,9]);
for i := 5  to 13 do writeln(c[i]);
end.