<?php

require 'connection.php';
$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
else {
$name	= $_POST['username'];
$query  = mysqli_query($conn, "SELECT username FROM users WHERE username='".$name."'");

 if(mysqli_num_rows($query) >=1)
   {
    echo"name already exists";
   }
else	{
$User_type = $_POST['user_type'];
$password  = $_POST['password'];
$pas 	   = hash("whirlpool", $password);
$query     = "INSERT into users (username, user_type, password) VALUES('$name', '$User_type', '$pas')";
$success   = mysqli_query($conn, $query);

if (!$success) {
    die("Couldn't enter data: ");

}
echo "Thank You For Signing Up <br>";
}
}
mysqli_close($conn);

?>
<html>

<head>
<title> THANKS </title>
<link href="../index.css" rel="stylesheet" type="text/css">
</head>

<body>
<a href="../index.php">click me</a>
</form>
</div>
</div>
</body>
</html>