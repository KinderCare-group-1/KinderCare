<?php
 include"connection.php";

 if(isset($_POST['login'])){
   $userName= mysqli_real_escape_string($link, $_POST['username']);
$password= mysqli_real_escape_string($link, $_POST['password']);
$query2="SELECT username, passwords FROM teachers;";

$result=mysqli_query($link, $query2);
$resultzo = mysqli_fetch_assoc($result);
if($userName==$resultzo['username'] && $password==$resultzo['passwords']){
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

    <link rel="stylesheet" type="text/css" href="style.css">

    <style>
        /* .container{
          width: 100%;   
          margin: 50px auto;
          display: flex;
          justify-content: center;
          align-items: center;
          width: 600px;
        }

        .container form{
            width: 600px;
        }

        .teacher{
           text-align: center;
           margin-bottom: 40px;
         } */
    </style>
    <title>KCES</title>
</head>

<body>

    <?php require ("header.php"); ?>
   
    <div  class= "container">
    
        <form action="index.php" method ="POST">
        
            <div class="login">
                <h2 class="teacher">Teacher's login page</h2>
                <label for="username">USER NAME</label>
                <input type="text" name="username">
                <label>PASSWORD</label>
                <input type="password" name = "password">
                <button type="submit" name="login" >LOG IN </button>
                <p>First time here? <a href="signup.php"> sign up </a> </p> 
            </div>
        </form>
    </div>
 




</body>

</html>