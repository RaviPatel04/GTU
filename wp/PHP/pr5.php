<!-- Write a PHP script to create a table student in the database StudentDB. -->

<?php
$connect = mysqli_connect('localhost', 'root', '', 'ravi');

if (!$connect) {
    die("Connection failed!!");
}

$database = 'ravi';

$query = "CREATE TABLE studentinfo (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    age INT,
    grade VARCHAR(10),
    college VARCHAR(150)
)";

$result = mysqli_query($connect, $query);

if ($result) {
    echo "Table 'studentinfo' created successfully in database '$database'";
} else {
    echo "Error creating table.";
}

mysqli_close($connect);
?>
