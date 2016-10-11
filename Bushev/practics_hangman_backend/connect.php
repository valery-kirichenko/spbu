<?php
header('Content-Type: text/html; charset=cp1251');
if($_POST['hash'] != "HCXt7xC47HGvVwo_68XX25Tgs789XBZ4fhsP0") exit("#Ошибка, доступ запрещен");

include_once("mysql/sql_connect.php");

$gid = (int)$_POST['gid'];
$player = mysqli_real_escape_string($db, $_POST['player']);
if(!isset($player) || empty($player)) exit("#Ошибка, введен некорректный идентификатор игры");

$data = mysqli_query($db, "SELECT gid, host, player FROM hangman_games WHERE gid='$gid'") or exit("#Не удалось подключиться к серверу, попробуйте позже");
$fdata = mysqli_fetch_assoc($data);

if(!isset($fdata['gid'])) exit("#Указанной игры не существует");
else if(!empty($fdata['player']) || !empty($fdata['active'])) exit("#Данная игра уже началась");

mysqli_query($db, "UPDATE hangman_games SET player='$player', active=1 WHERE gid='$gid'") or exit("#Не удалось подключиться к серверу, попробуйте позже");
exit($fdata['host']);
?>