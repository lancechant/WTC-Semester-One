<?php
	$message = " ";

	include "connection.php";
	$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
	session_start();

	$pass = hash("whirlpool",$_POST["passwd"]);

	if(count($_POST)>0) 
	{
		$result = mysqli_query($conn,"SELECT * FROM users WHERE username='" . $_POST["login"] . "' and password = '".$pass."'");
		$count  = mysqli_num_rows($result);
	if($count==0) {
		$message = "Invalid Username or Password!";
		echo "$message";
	} else {
		$_SESSION['logged_on'] = 1;
        $value = mysqli_fetch_assoc($result);
        $_SESSION['user_type'] = $value['user_type'];
        $_SESSION['username'] = $value['username'];
        header("Location: ../index.php");
	}
}
?>
<html>
	<head>
		<title>Login</title>
	<link href="../index.css" rel="stylesheet" type="text/css">
	</head>
	<body>
<div class="page">
	<div class="navigationbar">
		<ul>
			<li><a href="../index.php">home</a></li>
			<li><a href="signin.php">signup</a></li>
			<li><a href="recently_added.php">STORE</a></li>
		</ul>
	</div>
				<div class="login"> 
				<form class="log_form" action="" method="post">
            		<input type="text" name="login" placeholder="Username" /><br />
            		<input type="password" name="passwd" placeholder="Password" /><br />
            		<input type="submit" value="Submit"><br />
        		</form>
                
            	</div>
		</div>
	</body>
</html>