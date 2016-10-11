<?php
header('Content-Type: text/html; charset=cp1251');
if($_POST['hash'] != "HCXt7xC47HGvVwo_68XX25Tgs789XBZ4fhsP0") exit("#Ћшибка, доступ запрещен");

include_once("mysql/sql_connect.php");

$host = mysqli_real_escape_string($db, $_POST['host']);
if(!isset($host) || empty($host)) exit();

$data = mysqli_query($db, "SELECT gid FROM hangman_games WHERE host='$host' AND active=0") or exit();
$fdata = mysqli_fetch_assoc($data);

exit($fdata['gid']);
?>