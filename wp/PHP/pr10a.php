<!-- Write a PHP script to drop the table student tudentDB. -->

<?php
$connect = mysqli_connect('localhost', 'root', '', 'ravi');

if (!$connect) {
    die("Connection failed!!");
}

$query = "DROP TABLE studentinfo";
$result = mysqli_query($connect, $query);

if ($result) {
    echo "Table is dropped successfully";
} else {
    echo "Error occurred";
}

mysqli_close($connect);
?>