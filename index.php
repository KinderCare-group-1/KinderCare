<?php
include "connection.php";

if (isset($_POST['login'])) {
    $userName = mysqli_real_escape_string($link, $_POST['username']);
    $password = mysqli_real_escape_string($link, $_POST['password']);
    $query2 = "SELECT * FROM teachers where username = '$userName' AND passwords =' $password';";

    if( mysqli_query($link, $query2)) {
        header("Location:pupils.php");
    }else{
        echo "ERROR 345: invalid login details!!!";
        header("location:index.php");
    }
}

?>


<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <link rel="stylesheet" type="text/css" href="styles.css">
    <link rel="stylesheet" href="css/bootstrap.css">



    <title>KCES</title>
</head>

<body>

    <?php require("header.php"); ?>

    <div class="container">

        <form action="index.php" method="POST">

            <fieldset class="login">
                <legend class="teacher">
                    <h2> LOGIN PAGE</h2>
                </legend>
                <label for="username">USER NAME</label>
                <input type="text" name="username" required>
                <label>PASSWORD</label>
                <input type="password" name="password" required>
                <button class="Lbtn" type="submit" name="login">LOG IN </button>
                <p>First time here? <a href="signup.php"> sign up </a> </p>
            </fieldset>
        </form>
    </div>




    <?php include "footer.php"; ?>

</body>

</html>