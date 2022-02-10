<?php

include "connection.php";

$query = "SELECT a.AssignmentID, a.Assignment_Name, s.duration, a.ATTEMPTS FROM assignments a, scores s WHERE s.AssignmentID=a.AssignmentID;";

$res = mysqli_query($link, $query);

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="styles.css">
    <link rel="stylesheet" href="css/bootstrap.css">
    <title>Document</title>
</head>

<body>

    <?php include "header.php" ?>
    <div class="wrapper">
        <div class="dash-board">
            <a href="pupils.php">
                <div class="p-4"> <img src="activation2.png" alt=""> Pupil's Details</div>
            </a>
            <a href="register.php">
                <div class="p-4"><img src="register.jpg" alt="">Register Pupil</div>
            </a>
            <a href="assign.php">
                <div class="p-4"> <img src="assignment.png" alt="">Post Assignment</div>
            </a>
            <a href="scores.php">
                <div class="p-4"> <img src="activation2.png" alt=""> Pupil Scores</div>
            </a>
            <a href="status.php">
                <div class="p-4"> <img src="status.jpg" alt="">Change Pupil's Status</div>
            </a>
            <a href="reports.php">
                <div class="p-4"><img src="report.png" alt="">Reports</div>
            </a>
            <a href="requests.php">
                <div class="p-4"> <img src="activation2.png" alt=""> Activation Requests</div>
            </a>


        </div>

        <div class="content">

            <!-- <table border="2"> -->
            <table class="table table-sm table-secondary table-hover table-bordered m-5">

                <h4 class = "text-center">ASSIGNMENTS REPORTS </h4>

                <tr>
                    <th>ASSIGNMENT ID</th>
                    <TH>ASSIGNMENT NAME</TH>
                    <TH>ATTEMPTS</TH>
                    <th>DURATION</th>
                </tr>
                <?php foreach ($res as $x) { ?>

                    <tr>
                        <td><?php echo $x['AssignmentID']; ?> </td>
                        <td><?php echo $x['Assignment_Name']; ?> </td>
                        <td><?php echo $x['ATTEMPTS']; ?> </td>
                        <td><?php echo $x['duration']; ?> </td>



                    </tr>
                <?php }; ?>



            </table>



        </div>
    </div>
    <?php include "footer.php"; ?>

</body>

</html>