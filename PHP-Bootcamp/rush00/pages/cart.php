<?php
	include "connection.php";
	session_start();

	if (isset($_SESSION['username']))
		$c_user = $_SESSION['username'];
	else
		$c_user = "Anon";

	$file_str = "../private/".$c_user;
	if (!file_exists("../private"))
		mkdir("../private");
	if (!file_exists($file_str))
		file_put_contents($file_str, null);

	$cart = unserialize(file_get_contents($file_str));
?>

<html>
	<head>
		<title>CART</title>
		
		<meta charset="utf-8">
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<link rel="stylesheet" href="CSS/styles.css">
		
	</head>
	<body>
		<div class="container">
			<div class="navbar">
				<a id="logo" href="index.php">
					<img src="https://www.tskins.com/bundles/tradesteam/images/typeIcons/knives.png" alt="logo" title="logo"/>
				</a>
				<div class="float_right">
					<span style="float: left; padding: 14px 16px; font-size: 1.2em;"><?php if(isset($_SESSION['username'])) {echo "Hi, ".$_SESSION['username'];} ?></span>
					<?php 
						if(!isset($_SESSION['username']))   {
					?>
					<a href="javascript: log_form();" style="padding: 10px 10px 0px 10px;"><img id="profile" src="http://www.iconninja.com/files/945/151/636/customer-person-customers-profile-account-user-filled-icon.png" alt="profile" title="profile" /></a>
					<?php
						}
						else    {
					?>
					<a href="javascript: log_out();" style="padding: 10px 10px 0px 10px;"><img id="profile" src="http://www.iconninja.com/files/945/151/636/customer-person-customers-profile-account-user-filled-icon.png" alt="profile" title="profile" /></a>
					<?php
						}
					?>
					<a href="cart.php" style="padding: 10px 10px 0px 10px;"><img id="cart" src="http://www.iconninja.com/files/751/262/458/e-commerce-shopping-cart-tool-icon.png" alt="cart" title="cart" ></a>
				</div>
			</div>
			<div class="content" id="content">
			<?php
				if ($cart)  {
					echo "<ul class=cart_ul>";
					$total = 0;
					foreach($cart as $k => $v)  {
						echo "<li>Item: ".$v['item_name']." Quantity: ".$v['quantity']." Total Price: ".round($v['price'], 2)."</li>";
						$total += $v['price'];
					}
					echo "</ul><p>Total: ".round($total, 2)."</p>";
				}
				else
					echo "No Items in cart";    
			?>
				<?php 
					if (isset($_SESSION['username']))    { ?>
					<a href="checkout.php?total=<?php echo $total ?>">Check Out</a>
				<?php
					} 
					else { 
						echo "You need to be logged in to check out."; 
					}
				?>
				<a href="clear.php">Clear Cart</a>
			</div>
		</div>
		
		<script type="text/javascript" src="JS/scripts.js"></script>
	</body>
</html>