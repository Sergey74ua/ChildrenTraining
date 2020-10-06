program porodox;

var
  priz, win, game, variant, pusto: integer;

label m, n;

begin
  
  while game < 1000 do
  begin
    game := game + 1;
    priz := random(3) + 1;
    writeln('всего побед: ', win, ' всего игр: ', game, ' В процентах: ', win / game * 100);
    writeln('Выберете ящик 1, 2 или 3');
    variant := random(3) + 1;
    //readln(variant);
    writeln('Вы выбрали ящик номер ', variant);
    
    m:
    pusto := random(3) + 1;
    if (pusto = priz) or (pusto = variant) then goto m
    else
    begin
      writeln('Я убераю ', pusto, ' ящик так как там нет денег');
      writeln('Выберете сново');
      
      for var i := 1 to 3 do
        begin
      variant := i;
      if (variant <> pusto) and (variant <> variant) then break;
      end;
    end;
    
    if variant = priz then
    begin
      writeln('Вы правельно ответели заберите ваш воздух');
      win := win + 1;
    end
    else writeln('Вы не правельно ответели и вы не заберите ваш воздух');
  end;
  
end.