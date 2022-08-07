<? include_once('header.php'); ?>

<!-- Счетчик кликов на клиенте, через JS -->
<button type='button' onClick='JS_Click()' class='button'>JS счетчик</button>
<p>JS-счетчик кликов на клиенте: <output id='js_count'>0</output></p>
<br/><hr/><br/>

<!-- Счетчик кликов с сохранением на клиенте, через PHP -->
<?php
    if(isset($_POST['php_count']))
        $php_count=$_POST['php_count']+1;
    else
        $php_count=0;
?>
<form method='post' action="<?php echo $_SERVER['SCRIPT_NAME']; ?>" >
    <input type='submit' name='php_count' class='button' value='<?=$php_count ?>' />
</form>
<p>PHP счетчик с сохранением на клиенте: <output><?=$php_count ?></output></p>
<br/><hr/><br/>

<!-- Рандом по клику на сервере, через PHP -->
<form method='post'>
    <input type='submit' name='random' class='button' value='Рандом' />
</form>
<?php
    $random='неизвестно';
    if(isset($_POST['random']))
        $random=rand(0, 36);
    echo "<p>Рандомное число - $random </p>";
?>

<? include_once('footer.php'); ?>