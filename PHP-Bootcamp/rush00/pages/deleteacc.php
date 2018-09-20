<?php
	session_start();
	include "connection.php";
	$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
	$sql = "DELETE FROM users WHERE username ='" . $_SESSION['username'] . "'";
	$_SESSION['logged_on'] = "";
	if (mysqli_query($conn,$sql))
	{
		header("location: ../index.php");
	}
	session_destroy();
?>