<?php
	include "connection.php";

	$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);

	if (!$conn) {
		echo "Error";
	}
	else    {
		$sql = "select * from orders";
		$result = mysqli_query($conn, $sql);
		if (mysqli_num_rows($result) > 0)   {
			while ($row = mysqli_fetch_assoc($result))  {
				echo "<p>User: ".$row['username']." Total: R".$row['item_total']."</p>";
			}
		}
		else
			echo "No Orders";
	}
?>