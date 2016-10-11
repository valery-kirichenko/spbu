<?php
header('Content-Type: text/html; charset=cp1251');
if($_POST['hash'] != "HCXt7xC47HGvVwo_68XX25Tgs789XBZ4fhsP0") exit("#Ошибка, доступ запрещен");

include_once("mysql/sql_connect.php");

$host = mysqli_real_escape_string($db, $_POST['host']);
if(!isset($host) || empty($host)) exit("#Ошибка, введено некорректное название игры");

$data = mysqli_query($db, "SELECT gid FROM hangman_games WHERE host='$host' AND active=0") or exit("#Не удалось подключиться к серверу, попробуйте позже");
$fdata = mysqli_fetch_assoc($data); if(isset($fdata['gid'])) exit("#Ваш ник уже занят, измените его для создания игры");

mysqli_query($db, "INSERT INTO hangman_games (host, letter) VALUES ('$host', '-')") or exit("#Не удалось подключиться к серверу, попробуйте позже");
exit("Игра была упешно создана под номером #".$fdata['gid']);
?>