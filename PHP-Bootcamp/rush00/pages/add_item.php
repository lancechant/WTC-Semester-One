<?php

require 'connection.php';
$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
else {
$name	= $_POST['item_name'];
$query  = mysqli_query($conn, "SELECT item_name FROM items WHERE item_name='".$name."'");

 if(mysqli_num_rows($query) >=1)
   {
    echo"name already exists";
   }
else	{
$item_category = $_POST['item_category'];
$item_image  = $_POST['item_image'];
$item_desc  = $_POST['item_desc'];
$item_quantity  = $_POST['item_quantity'];
$price  = $_POST['price'];
$query     = "INSERT into items (item_name, item_category, item_image, item_desc, item_quantity, price) VALUES('$name', '$item_category', '$item_image', '$item_desc', '$item_quantity', '$price')";
$success   = mysqli_query($conn, $query);

if (!$success) {
    die("Couldn't enter data: ");

}
echo "Thank You For Adding An Item <br>";
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