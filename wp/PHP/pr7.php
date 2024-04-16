<!-- Write a PHP script to alter student table. For ex: modify sname by increasing its length. -->

<?php
$connect = mysqli_connect('localhost', 'root', '', 'ravi');

if (!$connect) {
    die("Connection failed!!");
}

$query = "ALTER TABLE studentinfo MODIFY name VARCHAR(255)";
$result = mysqli_query($connect, $query);

if ($result) {
    echo "Table altered successfully";
} else {
    echo "Error altering table";
}

mysqli_close($connect);
