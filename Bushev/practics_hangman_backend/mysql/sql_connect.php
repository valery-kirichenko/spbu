<?php
$db = mysqli_connect("localhost", "LOGIN", "PASS", "DB");
if(!$db) exit("Connect failed: ".mysqli_connect_error());

$db->set_charset("cp1251");
?>