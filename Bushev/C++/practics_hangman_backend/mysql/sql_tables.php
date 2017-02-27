<?php
include_once("sql_connect.php");

mysqli_query($db, "CREATE TABLE IF NOT EXISTS hangman_games(
	gid INT(11) NOT NULL AUTO_INCREMENT,
	host VARCHAR(32) NOT NULL,
	player VARCHAR(32) NOT NULL,
	score_h INT(11) NOT NULL,
	score_p INT(11) NOT NULL,
	word VARCHAR(32) NOT NULL,
	progress VARCHAR(32) NOT NULL,
	letter VARCHAR(2) NOT NULL,
	tries INT(11) NOT NULL,
	mover BOOLEAN NOT NULL,
	active BOOLEAN NOT NULL,
	PRIMARY KEY (gid)
	)") or exit("Can't create table #1");

mysqli_close($db);
exit("success");
?>