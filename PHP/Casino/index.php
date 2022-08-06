<? include_once('header.php'); ?>

<?php
    if(!isset($_POST['sector']))
        $sector=$_POST['sector'];
    else
        $sector=rand(0, 36);
?>

<div><button type="button" onClick="JS_Click()" class="button">JS счетчик</button></div>
<p>JS-счетчик кликов на клиенте: <a id="js_count">0</a></p>
<br/><hr/><br/>

<form method="post" action="<?php echo $_SERVER['SCRIPT_NAME']; ?>" >
    <input type="submit" name="sector" value="<?=$sector ?>" id="button" class="button" />
</form>

<?php
    echo 'Выпал сектор - ', $sector;
?>

<? include_once('footer.php'); ?>