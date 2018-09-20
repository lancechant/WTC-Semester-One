<?php
	include "connection.php";

	function user_exists($login)   {
		global $dbhost, $dbuser, $dbpass, $dbname;
		$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
		$sql = "SELECT * FROM users WHERE username='$login'";
		$result = mysqli_query($conn, $sql);
		if (mysqli_num_rows($result) > 0)
			return TRUE;
		else
			return FALSE;
	}

	function create_user($login, $passwd)  {
		global $dbhost, $dbuser, $dbpass, $dbname;
		$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
		if(!user_exists($login))   {
			$pw = hash("whirlpool", $passwd);
			$sql = "INSERT INTO users (username, user_type, password) VALUES ('$login', 'pleb', '$pw');";
			if (mysqli_query($conn, $sql)) {
				return TRUE;
			} else {
				return FALSE;
			}
		}
		else
			return FALSE;
	}

	function edit_user($login, $passwd)    {
		global $dbhost, $dbuser, $dbpass, $dbname;
		$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
		if (user_exists($login))   {
			$pw = hash("whirlpool", $passwd);
			$sql = "UPDATE users SET password='$pw' WHERE username='$login';";
			if (mysqli_query($conn, $sql)) {
				return TRUE;
			} else {
				return FALSE;
			}
		}
		else
			return FALSE;
	}

	function del_user($login) {
		global $dbhost, $dbuser, $dbpass, $dbname;
		$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
		if (user_exists($login) == "TRUE")   {
			$sql = "DELETE FROM users WHERE username='$login';";
			if (mysqli_query($conn, $sql)) {
				return TRUE;
			} else {
				return FALSE;
			}
		}
		else
			return FALSE;
	}

	if (!isset($_POST['submit']) && !isset($_GET['submit']))   {
		$msg = "Error.";
	}
	else    {
		if (isset($_POST['submit']))
			$type = $_POST['submit'];
		else
			$type = $_GET['submit'];
		$msg = "Error.";
		if (isset($_POST['login']))
			$login = $_POST['login'];
		else
			$login = $_GET['login'];
		if (isset($_POST['pass']))  {
			$passwd = $_POST['pass'];
		}
		else
			$passwd = "";
		if ($type == "Delete")  {
			if (del_user($login))
				$msg = "Success";
		}
		else if ($type == "Create") {
			if (create_user($login, $passwd))
				$msg = "Success";
		}
		else if ($type == "Edit")   {
			if (edit_user($login, $passwd))
				$msg = "Success";
		}
	}
	header("Location: admin.php?msg=$msg");
?>