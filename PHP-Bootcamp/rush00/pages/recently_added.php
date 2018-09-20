<?php
	session_start();
	include "connection.php";
	$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
	if (mysqli_connect_errno())
		{
			echo "Failed to connect to MySQL: " . mysqli_connect_error();
		}
	if (isset($_GET['categories']))
		{
			$result = mysqli_query($conn,"SELECT * FROM items WHERE item_category = '" . $_GET['categories'] . "';");        
		}
		else
		{
			$result = mysqli_query($conn,"SELECT * FROM items");
		}
?>
<html>
	<head>
	<title>STORE</title>
	<link href="../index.css" rel="stylesheet" type="text/css">
	</head>
	<body class="store">
		<div class="page">
		<div class="navigation_bar1">
			<ul>
				<li><a class="store_top" href="../index.php">home</a></li>
				<li><a class="store_top" href="recently_added.php">ALL</a></li>
				<li><a class="store_top" href="recently_added.php?categories=men_shirt">men shirts</a></li>
				<li><a class="store_top" href="recently_added.php?categories=men_pants">men pants</a></li>
				<li><a class="store_top" href="recently_added.php?categories=men_accessory">men accessories</a></li>
				<li><a class="store_top" href="recently_added.php?categories=women_shirt">women shirts</a></li>
				<li><a class="store_top" href="recently_added.php?categories=women_pants">women pants</a></li>
				<li><a class="store_top" href="recently_added.php?categories=women_accessory">women accessories</a></li>
			</ul>
		</div>
		<br />
		<?php
		while($row = mysqli_fetch_assoc($result))
		{
			echo "<div class='productbox'>
			<table>
			<tr>
				<td><img class='item_server' title='" . $row['item_desc'] . "' alt='" . $row['item_desc'] . "' src='".$row['item_image']."'></td>
				</tr>
				<tr>
				<td><strong>"." R" . $row['price'] . "</strong><button><a href='add_to_cart.php?item=".str_replace(' ', '+', $row['item_name'])."&price=".$row['price']."&quantity=1'>Add to cart</a></button></td>
				</tr>
			</div>";
		}
			mysqli_free_result($result);
		mysqli_close($conn);
		?>
	</div>
		</body>
</html>