<?php
header('Content-Type: text/html; charset=cp1251');
if($_POST['hash'] != "HCXt7xC47HGvVwo_68XX25Tgs789XBZ4fhsP0") exit("#Ошибка, доступ запрещен");

include_once("mysql/sql_connect.php");

$gid = (int)$_POST['gid'];
$role = (int)$_POST['role'];
$tries = (int)$_POST['tries'];
$letter = mysqli_real_escape_string($db, $_POST['letter']);
$progress = mysqli_real_escape_string($db, $_POST['progress']);
if(!isset($progress) || empty($progress)|| !isset($letter) || empty($letter)) exit("#Ћшибка, введено некорректное слово");

$win = (int)$_POST['win'];
$lost = (int)$_POST['lost'];

if(isset($win) && $win == 1){
	if($role == 1){
		mysqli_query($db, "UPDATE hangman_games SET score_p=score_p+1, mover='$role'") or exit('#');
	}else{
		mysqli_query($db, "UPDATE hangman_games SET score_h=score_h+1, mover='$role'") or exit('#');
	}
	
	$letter .= '#';
	$tries = 6;
}else if(isset($lost) && $lost == 1){
	if($role != 1){
		mysqli_query($db, "UPDATE hangman_games SET score_p=score_p+1, mover='$role'") or exit('#');
	}else{
		mysqli_query($db, "UPDATE hangman_games SET score_h=score_h+1, mover='$role'") or exit('#');
	}
	
	$letter .= '*';
	$tries = 6;
}

mysqli_query($db, "UPDATE hangman_games SET word='', progress='$progress', letter='$letter', tries='$tries' WHERE gid='$gid'") or exit('#');
?>