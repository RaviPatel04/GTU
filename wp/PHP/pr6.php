<!-- Write a PHP script to insert a row into the table student. The values to be inserted are taken from a HTML page. -->

<?php

$connect = mysqli_connect('localhost', 'root', '', 'ravi');

if (!$connect) {
    die("Connection failed!!");
}

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $name = $_POST['name'];
    $age = $_POST['age'];
    $grade = $_POST['grade'];
    $college = $_POST['college'];

    $insert = "INSERT INTO studentinfo (name, age, grade, college) VALUES ('$name', '$age', '$grade', '$college')";
    $result = mysqli_query($connect, $insert);

    if ($result) {
        echo "New record inserted successfully";
    } else {
        echo "Failed to insert data";
    }
}

mysqli_close($connect);

?>
