<?php 

session_start();

?>
<html>

<head>
<title>Shopping</title>
<link href="index.css" rel="stylesheet" type="text/css">
</head>

  <body>
<div class="page">
	<div class="navigationbar">
		<ul>
			<li><a href="index.php">home</a></li>
			<li><a href="pages/recently_added.php">STORE</a></li>
			<li><a href="pages/cart.php">CART</a></li>
			<?php if (($_SESSION['logged_on']) == "")
			{ ?>
				<li><a href="pages/signin.php">signup</a></li>
				<li><a href="pages/login.php">login</a></li>
			<?php } elseif ($_SESSION['logged_on'] == 1 && $_SESSION['user_type'] == 'admin') { ?>
				<li><a href="pages/logout.php">logout</a></li>
				<li><a href="pages/admin.php">Admin</a></li>
			<?php } else { ?>
				<li><a href="pages/logout.php">logout</a></li>
				<li><a href="pages/deleteacc.php">delete account</a></li>
			<?php } ?>
		</ul>
		</div>
	</div>
	<br />
	<div class=mbox>
		<img class ="image" src="img/home page.jpg">
		<big>STYLE UP</big>
		<p>With a selection of items to choose from</p>
	</div>
	<div class="mini_header">
		<h2>CLICK THE BELOW IMAGES TO GO TO THE RELATIVE WEBPAGES</h2>
	</div>
	<div class=bbox>
		<table>
			<td class="no_border"><a href="pages/recently_added.php"><img class="men_clothing" src="img/men clothing.jpg"></a></td>
			<td class="no_border"><a href="pages/recently_added.php"><img class= "women_clothing" src="img/women clothing.jpg"></a></td>
			<td class="no_border"><a href="pages/recently_added.php"><img class="accessories" src="img/accessories.jpg"></a></td>
		</table>
	</div>
</div>
	<div class="footer">
		<h2>&copyDone by LCHANT 2017</h2>
		<h2>&copyDone by MNAIDOO 2017</h2>
	</div>
  </body>
</html>