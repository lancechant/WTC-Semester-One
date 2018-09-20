<?php
    $server = "localhost";
    $user = "root";
    $pass = "a2sxtQhF";
    $db = "shopping";

    $conn = mysqli_connect($server, $user, $pass, "", 3306);

    if (!$conn) {
        echo ("Connection failed: ". mysqli_connect_error() . "\n");
    }

    $sql = "CREATE DATABASE shopping";

    if (mysqli_query($conn, $sql)) {
        // echo "Database created successfully\n";
    } else {
        echo "Error creating database: " . mysqli_error($conn) . "\n";
    }
    
    mysqli_close($conn);

    $conn = mysqli_connect($server, $user, $pass, $db, 3306);

    if (!$conn) {
        echo ("Connection failed: ". mysqli_connect_error(). "\n");
    }

    $sql = "CREATE TABLE users (
    id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(30) NOT NULL,
    user_type VARCHAR(5) NOT NULL,
    password VARCHAR(128) NOT NULL
    )";

    if (mysqli_query($conn, $sql)) {
        // echo "Table users created successfully\n";
    } else {
        echo "Error creating Table: " . mysqli_error($conn) . "\n";
    }

    

    $sql = "CREATE TABLE items(
    id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    item_name VARCHAR(50) NOT NULL,
    item_category VARCHAR(30) NOT NULL,
    item_image VARCHAR(300) NOT NULL,
    item_desc TEXT NOT NULL,
    item_quantity INT(6) UNSIGNED,
    price double(18,2)
    )";

    if (mysqli_query($conn, $sql)) {
        // echo "Table items created successfully\n";
    } else {
        echo "Error creating Table: " . mysqli_error($conn) ."\n";
    }

    $sql = "INSERT INTO users (username, user_type, password) VALUES('lance', 'admin', 'ec7d87741f86b8720f59602b59c80c8d29cd42e0f37cf11399313d9985de7d16477e2cc302f2661ac2b71287953ecf0635d64abb685feeb844ec705ec33631c5');";

    if (mysqli_query($conn, $sql)) {
        // echo "User entered successfully\n";
    } else {
        echo "Error creating user: " . mysqli_error($conn) ."\n";
    }

    $sql = "CREATE TABLE orders(
    id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(30) NOT NULL,
    item_total DECIMAL(18,2) NOT NULL
    )";

    if (mysqli_query($conn, $sql)) {
        echo "Table orders created successfully\n";
    } else {
        echo "Error creating Table: " . mysqli_error($conn) ."\n";
    }

    $sql = "INSERT INTO items (item_name, item_category, item_image, item_desc, item_quantity, price) VALUES ('mens shirt1', 'men_shirt', 'https://ae01.alicdn.com/kf/HTB1HI7MJFXXXXbIXXXXq6xXFXXXo/Dexter-Shirt-Top-New-Cute-Style-New-Round-Collar-Short-Sleeve-T-shirt-Design-Male-Model.jpg', 'first shirt', 5, 999)";
    $sql .= ",('mens shirt2', 'men_shirt', 'https://ae01.alicdn.com/kf/HTB1KmQgLXXXXXa5XpXXq6xXFXXXu/High-Quality-New-font-b-Model-b-font-Mens-Office-font-b-Formal-b-font-Dress.jpg', 'second mens shirt', 5, 899)";
    $sql .= ",('mens shirt3', 'men_shirt', 'https://ae01.alicdn.com/kf/HTB1j7DiKFXXXXaxXVXXq6xXFXXXj/M-2XL-Chemise-Homme-Casual-Fashion-Dot-Summer-Slim-Fit-Spring-Social-font-b-Shirt-b.jpg', 'third mens shirt', 5, 799)";

    $sql .= ",('mens pants', 'men_pants', 'http://g03.a.alicdn.com/kf/HTB1ZzjsLpXXXXXlXXXXq6xXFXXXi/hot-sale-Four-network-explosion-font-b-models-b-font-straight-font-b-men-s-b.jpg', 'first mens pants', 5, 999)";
    $sql .= ",('mens pants2', 'men_pants', 'https://ae01.alicdn.com/kf/HTB1zvZ0SFXXXXXnaFXXq6xXFXXXs/2017-fashion-ripped-font-b-jeans-b-font-men-slim-printed-font-b-jeans-b-font.jpg', 'second mens pants', 5, 899)";
    $sql .= ",('mens pants3', 'men_pants', 'https://ae01.alicdn.com/kf/HTB1Kn._NXXXXXXgapXXq6xXFXXXo/2016-autumn-new-font-b-men-s-b-font-font-b-jeans-b-font-tide-font.jpg', 'third mens pants', 5, 799)";

 	$sql .= ",('womens shirt1', 'women_shirt', 'https://ae01.alicdn.com/kf/HTB166h5KFXXXXbBXFXXq6xXFXXXT/2015-hot-new-brand-campaign-skeleton-skull-t-shirt-women-summer-casual-shirt-printing-short-black.jpg', 'first womens shirt', 5, 999)";
 	$sql .= ",('womens shirt2', 'women_shirt', 'https://ae01.alicdn.com/kf/HTB1R30ZLXXXXXcCXXXXq6xXFXXXt/Women-Bra-Bosom-t-Shirts-Short-Sleeve-2016-Summer-Hot-Lady-Teenager-100-Cotton-Topless-Printed.jpg', 'second womens shirt', 5, 899)";
    $sql .= ",('womens shirt3', 'women_shirt', 'https://ae01.alicdn.com/kf/HTB1ifNGcoAKL1JjSZFkq6y8cFXaw/High-quality-Women-T-font-b-shirt-b-font-Bodys-Armour-Marvel-costume-Superman-T-font.jpg', 'third womens shirt', 5, 799)";

    $sql .= ",('womens pants', 'women_pants', 'https://ae01.alicdn.com/kf/HTB1EkbaMVXXXXaEaXXXq6xXFXXXx/6-EXTRA-LARGE-font-b-Jeans-b-font-Women-font-b-Models-b-font-Two-Cuffs.jpg', 'first womens pants', 5, 999)";
    $sql .= ",('womens pants2', 'women_pants', 'https://ae01.alicdn.com/kf/HTB1AS.zPpXXXXbvaXXXq6xXFXXXZ/2017-hot-burst-font-b-models-b-font-women-s-holes-font-b-jeans-b-font.jpg', 'second womens pants', 5, 899)";
    $sql .= ",('womens pants3', 'women_pants', 'https://ae01.alicdn.com/kf/HTB1uXtXLVXXXXcuaXXXq6xXFXXX0/Female-Fitness-sportwear-Leggings-2015-font-b-SEXY-b-font-LeopardPattern-Slim-Elastic-font-b-Pants.jpg', 'third womens pants', 5, 799)";

     $sql .= ",('mens accessory', 'men_accessory', 'https://ae01.alicdn.com/kf/HTB1eHWmKVXXXXaYXXXXq6xXFXXXo/New-Fashion-font-b-Men-S-b-font-Accessories-Game-Super-Mario-Shark-font-b-Bullet.jpg', 'first mens accessory', 5, 999)";
 	$sql .= ",('mens accessory2', 'men_accessory', 'http://www.colorfulthebox.com/upfiles/main/Men-Polarizer-Sunglasses-2016-Running-Men-Style-Uv-Protection-Summer-Accessories-Free-Shipping-4711.jpg', 'second mens accessory', 5, 899)";
    $sql .= ",('mens accessory3', 'men_accessory', 'https://cdn.shopify.com/s/files/1/1851/9523/products/product-image-283398402_800x.jpg?v=1502954478', 'third mens accessory', 5, 799)";

    $sql .= ",('womens accessory', 'women_accessory', 'https://ae01.alicdn.com/kf/HTB1Bc0kQpXXXXXRXVXXq6xXFXXXU/Europe-Green-Crystal-Drops-Necklace-Diamante-Tassels-font-b-Women-s-b-font-font-b-Accessories.jpg', 'first womens accessory', 5, 999)";
    $sql .= ",('womens accessory2', 'women_accessory', 'https://cdn.shopify.com/s/files/1/1988/3437/products/product-image-89821444_990x@2x.jpg?v=1494347022', 'second womens accessory', 5, 899)";
    $sql .= ",('womens accessory3', 'women_accessory', 'https://cdn.shopify.com/s/files/1/2078/9251/products/product-image-347821371_1024x.jpg?v=1504306511', 'third womens accessory', 5, 799)";


    if (mysqli_query($conn, $sql)) {
        // echo "Items entered successfully\n";
    } else {
        echo "Error inserting items: " . mysqli_error($conn) ."\n";
    }

    mysqli_close($conn);
?>