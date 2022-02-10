<?php
include "connection.php";
$query1 = "SELECT a.Assignment_Name, p.first_name, p.last_name, s.user_code, s.scores FROM assignments a, pupils p, scores s WHERE a.AssignmentID=s.AssignmentID AND p.user_code=s.user_code AND s.scores>=70 ORDER BY scores DESC;";
$result = mysqli_query($link, $query1);

foreach ($result as $row) {
    $usercode[] = $row['user_code'];
    $score[] = $row['scores'];
}

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="styles.css">
    <link rel="stylesheet" href="css/bootstrap.css">
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>


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

       
            
            <table class="table table-sm table-light table-hover table-bordered m-3">

            <h4>BEST PUPILS</h4>

                <tr>
                    <th>FIRST NAME</th>
                    <th>LAST NAME</th>
                    <th>USERCODE</th>
                    <th>ASSIGNMENT NAME</th>
                    <th>MARKS</th>

                </tr>
                <?php foreach ($result as $x) { ?>

                    <tr>
                        <td><?php echo $x['first_name']; ?> </td>
                        <td><?php echo $x['last_name']; ?> </td>
                        <td><?php echo $x['user_code']; ?> </td>
                        <td><?php echo $x['Assignment_Name']; ?> </td>
                        <td><?php echo $x['scores']; ?> </td>



                    </tr>
                <?php }; ?>



            </table>
            <div width="10px" height="10px">
                <h4> BEST PERFORMERS CHART</h4>
                <canvas id="chart" width="80" height="40"></canvas>
            </div>
            </div>

        
    </div>

    <!-- JAVA SCRIPT FOR CHARTS -->


    <script>
        const labels = <?php echo json_encode($usercode);
                        ?>;
        const data = {
            labels: labels,
            datasets: [{
                label: 'SCORE',
                data: <?php echo json_encode($score);
                        ?>,
                backgroundColor: [
                    'rgba(255, 99, 132 )',
                    // 'rgba(255, 159, 64)',
                    // 'rgba(255, 205, 86,)',
                    'rgba(75, 192, 192)',
                    'rgba(54, 162, 235)',
                    'rgba(153, 102, 255)',
                    // 'rgba(201, 203, 207)'
                ],
                borderColor: [
                    'rgb(255, 99, 132)',
                    // 'rgb(255, 159, 64)',
                    // 'rgb(255, 205, 86)',
                    'rgb(75, 192, 192)',
                    'rgb(54, 162, 235)',
                    'rgb(153, 102, 255)',
                    // 'rgb(201, 203, 207)'
                ],
                borderWidth: 1
            }]
        };

        //THE CONFIGURATION.
        const config = {
            type: 'line',
            data: data,
            options: {
                scales: {
                    y: {
                        beginAtZero: true
                    }
                }
            },
        };

        const myChart = new Chart(
            document.getElementById('chart'),
            config
        );
    </script>
    <?php include "footer.php"; ?>
</body>

</html>