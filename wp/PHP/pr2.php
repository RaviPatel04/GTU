<!-- Write a PHP script to create a database StudentDB. -->

<?php
$connect = mysqli_connect('localhost', 'root', '');

if (!$connect) {
    die("Connection failed!!");
}

$query = "CREATE DATABASE ravi";
$result = mysqli_query($connect, $query);

if ($result) {
    echo "Database created successfully";
} else {
    echo "Error creating database: ";
}

mysqli_close($connect);
