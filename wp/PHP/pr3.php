<!-- Write a PHP script to list all the databases available in mysql. -->

<?php
$connect = mysqli_connect('localhost', 'root', '');

if (!$connect) {
    die("Connection failed!!");
}

$query = "SHOW DATABASES";
$result = mysqli_query($connect, $query);

if (mysqli_num_rows($result) > 0) {
    while ($row = mysqli_fetch_assoc($result)) {
        echo $row['Database'] . "<br>";
    }
} else {
    echo "No databases found.";
}

mysqli_close($connect);
?>
