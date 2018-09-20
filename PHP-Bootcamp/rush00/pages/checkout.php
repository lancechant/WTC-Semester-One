<?php
    include "conection.php";
    session_start();

    if(isset($_SESSION['username']))
        $c_user = $_SESSION['username'];
    else
        $msg = "Error";
    
    $file_str = "../private/$c_user";

    if (!isset($_GET['total']) || !isset($_SESSION['username'])) {
        $msg = "Error.";
    }
    else    {
        $total = $_GET['total'];
        $conn1 = mysqli_connect("localhost", "root", "a2sxtQhF", "shopping", 3306);
        $sql = "INSERT INTO orders (username, item_total) VALUES ('$c_user', $total);";
        if (mysqli_query($conn1, $sql))  {
            $msg = "Success";
            if(file_exists("../private") && file_exists($file_str))
                file_put_contents($file_str, null);
        }
        else
            $msg = "error";
    }
    header("Location: ../index.php?msg=$msg");
?>