<!-- Right-click on the Web Pages folder in the Projects pane.
Select New > JSP. -->

<!DOCTYPE html>
<html>
<head>
    <title>Student Enrollment Form</title>
    <style>
        table td {
            padding: 8px;
        }
    </style>
</head>
<body>
    <h2>Student Enrollment Form</h2>
    <form action="StudentServlet" method="post">
        <table border="1">
            <tr>
                <th>Field</th>
                <th>Value</th>
            </tr>
            <tr>
                <td>Enrolment:</td>
                <td><input type="text" name="eno" required></td>
            </tr>
            <tr>
                <td>Student Name:</td>
                <td><input type="text" name="sname" required></td>
            </tr>
            <tr>
                <td>Branch:</td>
                <td><input type="text" name="branch" required></td>
            </tr>
            <tr>
                <td>Year:</td>
                <td><input type="text" name="year" required></td>
            </tr>
            <tr>
                <td colspan="2" align="center"><input type="submit" style="width: 100%; padding: 5px;" value="Submit"></td>
            </tr>
        </table>
    </form>
</body>
</html>
