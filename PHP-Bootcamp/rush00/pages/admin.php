<html>

<head>
<title> ADMIN PORTAL </title>
<link href="../index.css" rel="stylesheet" type="text/css">
</head>

<body>
<div class="page">
	<div class="navigationbar">
		<ul>
			<li><a href="../index.php">home</a></li>
			<li><a href="admin_accounts.php">remove accounts</a></li>
			<li><a href="orders.php">Orders</a></li>
		</ul>
	</div>
<div class="signup">
<form class="signin_form" action="add_item.php" method="post">
  item_name:
  <input type="varchar" name="item_name" required><br />
  item_category
  <input type="varchar" name="item_category" required><br />
  item_image:
  <input type="varchar" name="item_image" required><br />
   item_desc:
  <input type="text" name="item_desc" required><br />
   item_quantity:
  <input type="int" name="item_quantity" required><br />
   price:
  <input type="double(18,2)" name="price" required><br />
<input type="submit" value="Submit"><br />
</form>
</div>
</div>
</body>
</html>