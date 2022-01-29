<?php
include"connection.php";

if(isset($_POST['register'])){
    $firstName=mysqli_real_escape_string($link, $_POST['fname']);
    $lastName=mysqli_real_escape_string($link, $_POST['lname']);
    $usercode=mysqli_real_escape_string($link, $_POST['usercode']);
    $userName=mysqli_real_escape_string($link, $_POST['username']);
    $password=mysqli_real_escape_string($link, $_POST['password']);
    $ssimu=mysqli_real_escape_string($link, $_POST['phone']);
   
    $query3="INSERT INTO pupils (user_code, first_name, last_name, username, passwords, phone_number) VALUES('$usercode', '$firstName', '$lastName', '$userName', '$password', '$ssimu');";

    if(mysqli_query($link, $query3)){
        header("Location:register.php");
    }


}


?>




<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <style>
        .btn a{
            color: black;
        }
    
    </style>
    <title>KCES</title>
</head>
<body>
    <?php require ("header.php"); ?>
   

    <div class="wrapper">
        <div class="dash-board">
            
                <a href="register.php"><div>Register Pupil</div></a>
                <a href="assign.php"><div>Post Assignment</div></a>
                <a href="status.php"><div>Change Pupil's Status</div></a>
                <a href="reports.php"><div>Reports</div></a>
        </div>

        <div class="content">
        <form action="register.php" method ="POST">
            
            
            <h2>Pupil's registration page</h2>
                <label for="fname">FIRST NAME</label>
                <input type="text" name="fname">
                <label for="lname">LAST NAME</label>
                <input type="text" name="lname">
                <label for="usercode">USER CODE</label>
                <input type="text" name="usercode">
                <label for="username">USER NAME</label>
                <input type="text" name="username">
                <labe>PASSWORD</label>
                <input type="password" name = "password">
                <label for="phone">PHONE NUMBER</label>
                <input type="tel" name="phone">
                <button type="submit" name="register" class = "btn">REGISTER </button>
                <button class = "btn"> <a href="#"> HOME</a> </button>
        </form>


        </div>
    </div>


</body>
</html>