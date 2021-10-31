Program ParadoxMH;
var priz, variant, variant1, variant2, removed, game, win : integer;
label start, recursion;

Begin
  while true do
  begin
  priz := random(3)+1;
  writeln('Из ', game,' игр, выиграно ', win,'.');
  writeln('При этом выбор менялся ', variant, ' раз.');
  writeln('***************************************');
  write('Выберете ящик 1, 2, 3:  ');
  readln(variant1);
  
  //убираем лишний ящик
  recursion:
  removed := random(3)+1;
  if (removed = priz) or (removed = variant1) then goto recursion;
  
  //Подсказка и повторный выбор
  writeln('Вы выбрали ящик № ', variant1, ', но не спешите.');
  writeln('ПОДСКАЗКА! Ящик № ', removed, ' - точно пустой.');
  write('Из оставшихся двух ящиков: ');
  for var i := 1 to 3 do
  begin
    if i <> removed then write(i, ', ');
  end;
  write('что вы выберете - ');
  read(variant2);
  game := game + 1;
  
  if variant1 <> variant2 then variant := variant + 1;
  
  writeln('И так, вы выбрали ящик № ', variant2, '.');
  writeln('Приз был в ящике № ', priz, '. ');
  if variant2 <> priz then writeln('Вы проиграли!') else
    begin
    win := win + 1;
    writeln('Поздравляем, вы выиграли!');
    end;
  writeln();
  end;
end.