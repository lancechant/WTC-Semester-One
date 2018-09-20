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
			<li><a href="womens_clothing.html">Womens Clothing</a></li>
			<li><a href="accessories.html">accessories</a></li>
		</ul>
	</div>
<?php
		include "connection.php";
		
		$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);

		if (!$conn) {
				echo "Database connection failed.";
		}
		else    {
				$sql = "SELECT username FROM users";
				$result = mysqli_query($conn, $sql);
				
				if (mysqli_num_rows($result) <= 0)  {
						echo "No users.";
				}
				else    {
						?>
								<div class='create_user'>
										<form action="user_functions.php" method="post">
												<fieldset>
														<legend>Create User: </legend>
														<span>Username: </span>
														<input type="text" name="login" />
														<br />
														<span>Password: </span>
														<input type="password" name='pass' />
														<br />
														
														<input type="submit" name='submit' value="Create" />
														<br />
												</fieldset>
										</form>
								</div>
								<div class='edit_user'>
										<form action="user_functions.php" method="post">
												<fieldset>
														<legend>Edit User: </legend>
														<span>Username: </span>
														<select name="login">
																<?php
																		while ($row = mysqli_fetch_assoc($result))  {
																				echo "<option value='".$row['username']."'>".$row['username']."</option>";
																		} 
																?>
														</select>
														<br />
														<span>Password: </span>
														<input type="password" name='pass' />
														<br />
														<input type="submit" name='submit' value="Edit" />
														<br />
												</fieldset>
										</form>
								</div>
								<div class='del_user'>
										<form action="user_functions.php" method="get">
												<fieldset>
														<legend>Delete User: </legend>
														<span>Username: </span>
														<select name="login">
																<?php
																		$result = mysqli_query($conn, $sql);
																		while ($row = mysqli_fetch_assoc($result))  {
																				echo "<option value='".$row['username']."'>".$row['username']."</option>";
																		} 
																?>
														</select>
														<br />
														<input type="submit" name='submit' value="Delete" />
														<br />
												</fieldset>
										</form>
								</div>
						<?php
				}
		}
?>
</div>
</div>
</body>
</html>