<? include_once('header.php'); ?>

<?php
    if(!isset($_POST['sector']))
        $sector=$_POST['sector'];
    else
        $sector=rand(0, 36);
?>

<form method="post" action="<?php echo $_SERVER['SCRIPT_NAME']; ?>" >
    <input type="submit" name="sector" value="<?=$sector ?>" />
</form>

<?php
    echo 'Выпал сектор - ', $sector;
?>

<? include_once('footer.php'); ?>