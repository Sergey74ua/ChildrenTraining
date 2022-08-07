<? include_once('header.php'); ?>

<!-- Счетчик кликов на клиенте, через JS -->
<button type='button' onClick='JS_Click()' class='button'>
    <output id='js_count'>JS-счетчик: 0</output>
</button>
<br/><hr/><br/>

<!-- Счетчик кликов с сохранением на клиенте, через PHP -->
<?php
    $php_count=0;
    if(isset($_POST['php_count']))
        $php_count=preg_replace('/[^0-9]/', '', $_POST['php_count'])+1;
?>
<form method='post'>
    <input type='submit' name='php_count' class='button' value='<?='PHP-Счетчик: '.$php_count ?>' />
</form>
<br/><hr/><br/>

<!-- Рандом по клику на сервере, через PHP -->
<?php
    $php_random='?';
    if(isset($_POST['random']))
        $php_random=rand(0, 36);
?>
<form method='post'>
    <input type='submit' name='random' class='button' value='<?='PHP-Рандом: '.$php_random ?>' />
</form>

<? include_once('footer.php'); ?>