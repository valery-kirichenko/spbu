<?php
header('Content-Type: text/html; charset=cp1251');
if($_POST['hash'] != "HCXt7xC47HGvVwo_68XX25Tgs789XBZ4fhsP0") exit("#Ошибка, доступ запрещен");

include_once("mysql/sql_connect.php");

$gid = (int)$_POST['gid'];
$rand = (int)$_POST['rand'];

mysqli_query($db, "UPDATE hangman_games SET mover='$rand' WHERE gid='$gid'") or exit("#");
?>