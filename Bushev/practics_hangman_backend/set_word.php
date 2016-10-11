<?php
header('Content-Type: text/html; charset=cp1251');
if($_POST['hash'] != "HCXt7xC47HGvVwo_68XX25Tgs789XBZ4fhsP0") exit("#Ошибка, доступ запрещен");

include_once("mysql/sql_connect.php");

$gid = (int)$_POST['gid'];
$tries = (int)$_POST['tries'];
$word = mysqli_real_escape_string($db, $_POST['word']);
$progress = mysqli_real_escape_string($db, $_POST['progress']);
if(!isset($word) || empty($word) || !isset($progress) || empty($progress)) exit("#Ћшибка, введено некорректное слово");

mysqli_query($db, "UPDATE hangman_games SET word='$word', progress='$progress', tries='$tries' WHERE gid='$gid'") or exit('#');
?>