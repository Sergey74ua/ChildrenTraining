<?php
    //База данных
    $db='data/casino.sqlite';
    //include_once('data/migration.php');
?>

<? include_once('header.php'); ?>

<form method="post">
    <input type="submit" name="bet" value="Go!" /><br/><br/>
    <input type="submit" name="reset" value="reset" /><br/>
</form>

<?php
    //Выводим все статистику с БД
    function statistics($db) {
        $connect = new PDO("sqlite:$db");
        $sql = "SELECT `sector`, `stat` FROM `Roulette`";
        $result = $connect->query($sql);
        $arr = [];
        foreach($result as $row)
            $arr[$row['sector']] = $row['stat'];
        ksort($arr);
        echo '<div class="stat">';
        foreach($arr as $key => $elem)
            echo '<div>', $key, "\n", $elem, '</div>';
        echo '</div>';
        $connect = null;
    }

    //Добавляем рандом в статистику БД
    $sector = 'начните игру';
    if(array_key_exists('bet', $_POST)) {
        $sector=rand(0, 36);
        $connect = new PDO("sqlite:$db");
        $sql = "UPDATE `Roulette` SET `stat`=`stat`+1 WHERE `sector` = $sector";
        $connect->exec($sql);
        $connect = null;
    }
    echo "<div>$sector</div>";

    //Обнуление статистики
    if(array_key_exists('reset', $_POST)) {
        $connect = new PDO("sqlite:$db");
        $sql = "UPDATE `Roulette` SET `stat` = 0";
        $connect->exec($sql);
        $connect = null;
    }

    statistics($db);
?>

<? include_once('footer.php'); ?>