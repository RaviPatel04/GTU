<!-- Write a PHP script to list all the tables available in a particular database. -->

<?php
$connect = mysqli_connect('localhost', 'root', '', 'ravi');

if (!$connect) {
    die("Connection failed!!");
}

$database = 'ravi';
echo "Tables in database $database:<br>";

$query = "SHOW TABLES";
$result = mysqli_query($connect, $query);

if (mysqli_num_rows($result) > 0) {
    while ($row = mysqli_fetch_row($result)) {
        echo $row[0] . "<br>";
    }
} else {
    echo "No tables found in the database.";
}

mysqli_close($connect);
?>
