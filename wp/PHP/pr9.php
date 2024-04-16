<!-- Write a PHP script to delete all rows from student table whose roll numbers are between 1 and 3. -->

<?php
$connect = mysqli_connect('localhost', 'root', '', 'ravi');

if (!$connect) {
    die("Connection failed!!");
}

$query = "DELETE FROM studentinfo WHERE id BETWEEN 1 AND 3";
$result = mysqli_query($connect, $query);

if ($result) {
    echo "Data Deleted successfully";
} else {
    echo "Error occurred.";
}

mysqli_close($connect);
?>
