<?php
	session_start();
	
	if(isset($_SESSION['username']))
		$c_user = $_SESSION['username'];
	else
		$c_user = "Anon";
	if(!file_exists("../private"))
	{
		mkdir("../private");
	}
	$file_str = "../private/$c_user";
	if (!file_exists($file_str)) {
		file_put_contents($file_str, null);
	}

	$cart = unserialize(file_get_contents($file_str));
	$item['item_name'] = str_replace('+', ' ', $_GET['item']);
	$item['price'] = $_GET['price'];
	$item['quantity'] = $_GET['quantity'];
	$exist = 0;
	
	if ($cart) {
		foreach ($cart as $k => $v) {
			if ($v['item_name'] === $item['item_name']) {
				$exist = 1;
				$cart[$k]['quantity']++;
				$price = $cart[$k]['price'];
				$price *= $cart[$k]['quantity'];
				$cart[$k]['price'] = round($price, 2);
			}
		}
	}

	if ($exist) {
		file_put_contents($file_str, serialize($cart));
		header("Location: ../index.php");
	}
	else    {
		$cart[] = $item;
		file_put_contents($file_str, serialize($cart));
		header("Location: ../index.php");
	}
?>