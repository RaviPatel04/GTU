<!-- Write a PHP script to list all the records in the student table in tabular format. -->

<?php
$connect = mysqli_connect('localhost', 'root', '', 'ravi');

if (!$connect) {
    die("Connection failed!!");
}

$query = "SELECT * FROM studentinfo";
$result = mysqli_query($connect, $query);

if (mysqli_num_rows($result) > 0) {
    echo "<table border = '2'>
          <tr>
          <th>Name</th>
          <th>Age</th>
          <th>Grade</th>
          <th>College</th>
          </tr>";
    while ($data = mysqli_fetch_assoc($result)) {
        echo "<tr>
              <td>" . $data['name'] . "</td>
              <td>" . $data['age'] . "</td>
              <td>" . $data['grade'] . "</td>
              <td>" . $data['college'] . "</td>
              </tr>";
    }
    echo "</table>";
} else {
    echo "No records found";
}

mysqli_close($connect);
?>
