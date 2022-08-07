<? include_once('header.php'); ?>

<!-- Счетчик кликов на клиенте, через JS -->
<button type='button' onClick='JS_Click()' class='button'>
    <output id='js_count'>JS-Счетчик: 0</output>
</button>
<br/><hr/><br/>

<!-- Счетчик кликов с сохранением на клиенте, через PHP -->
<?php
    $count=0;
    if(isset($_POST['php_count']))
        $count=preg_replace('/[^0-9]/', '', $_POST['php_count'])+1;
?>
<form method='post'>
    <input type='submit' name='php_count' class='button' value='<?='PHP-Счетчик: '.$count ?>' />
</form>
<br/><hr/><br/>

<!-- Рандом по клику на сервере, через PHP -->
<?php
    $random='?';
    if(isset($_POST['php_random']))
        $random=rand(0, 36);
?>
<form method='post'>
    <input type='submit' name='php_random' class='button' value='<?='PHP-Рандом: '.$random ?>' />
</form>

<? include_once('footer.php'); ?>