<!-- Write a PHP script to drop the database StudentDB. -->

<?php
$connect = mysqli_connect('localhost', 'root', '', 'ravi');

if (!$connect) {
    die("Connection failed!!");
}

$query = "DROP DATABASE ravi";
$result = mysqli_query($connect, $query);

if ($result) {
    echo "Database is dropped successfully";
} else {
    echo "Error occurred";
}

mysqli_close($connect);
?>
